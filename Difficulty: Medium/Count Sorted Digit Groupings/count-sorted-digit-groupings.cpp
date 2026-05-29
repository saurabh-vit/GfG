class Solution {
  public:
    long long dp[101][901];

    long long solve(int pos, int prevSum, string &s) {
        int n = s.size();

        if (pos == n)
            return 1;

        if (dp[pos][prevSum] != -1)
            return dp[pos][prevSum];

        long long ans = 0;
        int currSum = 0;

        for (int i = pos; i < n; i++) {
            currSum += s[i] - '0';

            if (currSum >= prevSum) {
                ans += solve(i + 1, currSum, s);
            }
        }

        return dp[pos][prevSum] = ans;
    }

    int validGroups(string &s) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s);
    }
};