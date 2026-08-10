class Solution {
  public:
    int maxTask(vector<int>& h, vector<int>& l) {
        // code here
        int n = h.size();

        vector<vector<int>> dp(n, vector<int>(2, 0));

        // Day 0
        dp[0][0] = 0;
        dp[0][1] = max(h[0], l[0]);

        for (int i = 1; i < n; i++) {
            // Do no task today
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);

            // Low-effort task today
            int low = max(dp[i - 1][0], dp[i - 1][1]) + l[i];

            // High-effort task today
            // Previous day must have no task
            int high = dp[i - 1][0] + h[i];

            dp[i][1] = max(low, high);
        }

        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};