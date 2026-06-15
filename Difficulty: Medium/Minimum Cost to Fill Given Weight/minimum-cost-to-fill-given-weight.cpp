class Solution {
  public:
    int minimumCost(vector<int> &cost, int w) {
        // code here
        vector<long long> dp(w + 1, 1e18);
        dp[0] = 0;

        int n = cost.size();

        for (int j = 0; j < n; j++) {
            if (cost[j] == -1) continue;

            int weight = j + 1;

            for (int i = weight; i <= w; i++) {
                dp[i] = min(dp[i], dp[i - weight] + cost[j]);
            }
        }

        return (dp[w] == 1e18) ? -1 : (int)dp[w];
    }
};
