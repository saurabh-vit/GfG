class Solution {
  public:
    int numberOfPath(vector<vector<int>>& mat, int k) {
        // Code Here
        int n = mat.size(), m = mat[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k+1, 0)));
    
        if(mat[0][0] <= k)
            dp[0][0][mat[0][0]] = 1;
    
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int sum = 0; sum <= k; sum++) {
                    if(i > 0 && sum - mat[i][j] >= 0)
                        dp[i][j][sum] += dp[i-1][j][sum - mat[i][j]];
                    if(j > 0 && sum - mat[i][j] >= 0)
                        dp[i][j][sum] += dp[i][j-1][sum - mat[i][j]];
                }
            }
        }
    
        return dp[n-1][m-1][k];
    }
};