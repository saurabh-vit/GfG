class Solution {
  public:
    int minMoves(vector<int>& arr) {
        // code here
        int n = arr.size();
        int longest = 1;

        // dp/value: length of consecutive sequence ending at x
        vector<int> dp(n + 1, 0);

        for (int x : arr) {
            dp[x] = dp[x - 1] + 1;
            longest = max(longest, dp[x]);
        }

        return n - longest;
    }
};