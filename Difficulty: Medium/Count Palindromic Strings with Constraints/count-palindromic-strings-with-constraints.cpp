class Solution {
  public:
    int palindromicStrings(int n, int k) {
        // code here
        const long long MOD = 1000000007;
        long long ans = 0;
        long long perm = 1;  // P(k, 0)
        for (int m = 1; m <= k; m++) {
            // P(k, m) = P(k, m-1) * (k-m+1)
            perm = (perm * (k - m + 1)) % MOD;
            // Odd length = 2m - 1
            // Number = P(k, m)
            if (2 * m - 1 <= n) {
                ans = (ans + perm) % MOD;
            }
            // Even length = 2m
            // Number = P(k, m)
            if (2 * m <= n) {
                ans = (ans + perm) % MOD;
            }
            if (2 * m > n)
                break;
        }
        return ans;
    }
};