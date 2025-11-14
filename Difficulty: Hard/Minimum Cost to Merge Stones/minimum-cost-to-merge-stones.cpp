class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();

        // If impossible to end with 1 pile
        if ((n - 1) % (k - 1) != 0) return -1;

        // Prefix sums
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + stones[i];

        auto rangeSum = [&](int i, int j) {
            return prefix[j + 1] - prefix[i];
        };

        const int INF = 1e9;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, INF)));

        // Base case: merging one pile into one pile costs 0
        for (int i = 0; i < n; i++) dp[i][i][1] = 0;

        // Length of interval
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                // Try merging into m piles (2..k)
                for (int m = 2; m <= k; m++) {
                    for (int mid = i; mid < j; mid += (k - 1)) {
                        if (dp[i][mid][1] == INF || dp[mid+1][j][m-1] == INF) continue;
                        dp[i][j][m] = min(dp[i][j][m], dp[i][mid][1] + dp[mid+1][j][m-1]);
                    }
                }

                // If we can merge range i..j into k piles, then into 1 pile
                if (dp[i][j][k] != INF) {
                    dp[i][j][1] = dp[i][j][k] + rangeSum(i, j);
                }
            }
        }

        return dp[0][n-1][1];
    }
};