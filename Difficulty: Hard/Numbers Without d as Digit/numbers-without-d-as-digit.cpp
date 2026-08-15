class Solution {
public:
    long long dp[12][2][2];
    int digit;
    string s;

    long long solve(int pos, int tight, int started) {
        if (pos == s.size())
            return started;  // exclude number 0

        long long &ans = dp[pos][tight][started];

        if (ans != -1)
            return ans;

        ans = 0;

        int limit = tight ? s[pos] - '0' : 9;

        for (int x = 0; x <= limit; x++) {
            int newTight = tight && (x == limit);

            // Leading zero: number hasn't started yet
            if (!started && x == 0) {
                ans += solve(pos + 1, newTight, 0);
            }
            else {
                // Forbidden digit
                if (x == digit)
                    continue;

                ans += solve(pos + 1, newTight, 1);
            }
        }

        return ans;
    }

    int countWithout(int n, int d) {
        if (n == 0)
            return 0;

        digit = d;
        s = to_string(n);

        memset(dp, -1, sizeof(dp));

        return solve(0, 1, 0);
    }
};