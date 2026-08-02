class Solution {
  public:
    int count(int n, int m) {
        // code here
         vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int v = 1; v <= m; v++)
            dp[1][v] = 1;

        for (int i = 2; i <= n; i++) {
            for (int cur = 1; cur <= m; cur++) {
                for (int prev = 1; prev <= m; prev++) {
                    if (cur % prev == 0 || prev % cur == 0)
                        dp[i][cur] += dp[i - 1][prev];
                }
            }
        }

        int ans = 0;
        for (int v = 1; v <= m; v++)
            ans += dp[n][v];

        return ans;
    }
};