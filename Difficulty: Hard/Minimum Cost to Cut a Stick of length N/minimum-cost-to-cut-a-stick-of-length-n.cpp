class Solution {
  public:
    int minCutCost(int n, vector<int>& cuts) {
        // code here
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
    
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
    
        // len = segment length in dp (difference between l and r)
        for (int len = 2; len < m; len++) {
            for (int l = 0; l + len < m; l++) {
                int r = l + len;
                dp[l][r] = INT_MAX;
    
                // Try making the first cut at position k between l and r
                for (int k = l + 1; k < r; k++) {
                    dp[l][r] = min(dp[l][r],
                                   dp[l][k] + dp[k][r] + cuts[r] - cuts[l]);
                }
            }
        }
    
        return dp[0][m - 1];
    }
};