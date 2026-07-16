class Solution {
  public:
    int countWays(int n, int sum) {
        // code here
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int s = 0; s <= sum; s++) {
                int start = (i == 1) ? 1 : 0;
                for (int d = start; d <= 9; d++) {
                    if (s >= d)
                        dp[i][s] += dp[i - 1][s - d];
                }
            }
        }

        return dp[n][sum] == 0 ? -1 : dp[n][sum];
    }
};