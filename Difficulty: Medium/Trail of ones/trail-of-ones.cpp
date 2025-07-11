class Solution {
  public:
    int countConsec(int n) {
        // code here
        vector<long long> dp(n+2, 0);
        dp[0] = 1;
        dp[1] = 2;
        for(int i=2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        long long total = pow(2, n);
        return total - dp[n];
    }
};