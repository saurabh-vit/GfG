class Solution {
  public:
    int countSubsequences(string& s, int n) {
        // code here
        const int MOD = 1e9 + 7;

        // dp[r] = number of non-empty subsequences having remainder r
        vector<long long> dp(n, 0);

        for (char c : s) {
            int digit = c - '0';

            // Subsequence consisting only of this digit
            vector<long long> ndp = dp;

            ndp[digit % n] = (ndp[digit % n] + 1) % MOD;

            // Append current digit to every existing subsequence
            for (int r = 0; r < n; r++) {
                if (dp[r] == 0) continue;

                int newRemainder = (r * 10LL + digit) % n;
                ndp[newRemainder] =
                    (ndp[newRemainder] + dp[r]) % MOD;
            }

            dp.swap(ndp);
        }

        return dp[0];
    }
};