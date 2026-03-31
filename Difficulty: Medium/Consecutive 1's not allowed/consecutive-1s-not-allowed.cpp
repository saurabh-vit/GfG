class Solution {
  public:
    int countStrings(int n) {
        // code here
        long long dp[n+3]; 
        dp[1] = 2; 
        dp[2] = 3;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};