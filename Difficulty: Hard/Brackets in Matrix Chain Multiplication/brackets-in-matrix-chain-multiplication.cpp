class Solution {
public:
    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size();
        int m = n - 1;
        vector<vector<long long>> dp(m, vector<long long>(m, 0));
        vector<vector<int>> split(m, vector<int>(m, -1));

        // gap method
        for (int len = 2; len <= m; len++) {
            for (int i = 0; i + len - 1 < m; i++) {
                int j = i + len - 1;
                dp[i][j] = LLONG_MAX;

                for (int k = i; k < j; k++) {
                    long long cost =
                        dp[i][k] +
                        dp[k+1][j] +
                        1LL * arr[i] * arr[k+1] * arr[j+1];

                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        split[i][j] = k;
                    }
                }
            }
        }

        return build(0, m - 1, split);
    }

    string build(int i, int j, vector<vector<int>> &split) {
        if (i == j) {
            return string(1, 'A' + i); // A, B, C...
        }

        int k = split[i][j];
        string left = build(i, k, split);
        string right = build(k + 1, j, split);

        return "(" + left + right + ")";
    }
};