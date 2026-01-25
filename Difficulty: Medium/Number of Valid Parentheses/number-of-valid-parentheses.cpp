class Solution {
  public:
    int findWays(int n) {
        // code here
        if (n % 2 != 0) return 0;  // odd length can't be valid

        int pairs = n / 2;
        vector<long long> dp(pairs + 1, 0);
    
        dp[0] = 1;
        dp[1] = 1;
    
        for (int i = 2; i <= pairs; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
    
        return dp[pairs];
    }
};