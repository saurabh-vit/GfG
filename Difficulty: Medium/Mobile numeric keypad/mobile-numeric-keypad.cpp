class Solution {
  public:
    int getCount(int n) {
        // code here
        if (n <= 0) return 0;
        vector<vector<int>> moves = {
            {0,8},        // 0
            {1,2,4},      // 1
            {2,1,3,5},    // 2
            {3,2,6},      // 3
            {4,1,5,7},    // 4
            {5,2,4,6,8},  // 5
            {6,3,5,9},    // 6
            {7,4,8},      // 7
            {8,5,7,9,0},  // 8
            {9,6,8}       // 9
        };
        vector<vector<long long>> dp(n+1, vector<long long>(10, 0));
        for (int k=0; k<=9; k++) {
            dp[1][k] = 1;
        }
        for (int len=2; len<=n; len++) {
            for (int k=0; k<=9; k++) {
                for (int next : moves[k]) {
                    dp[len][k] += dp[len-1][next];
                }
            }
        }
        long long total = 0;
        for (int k=0; k<=9; k++) {
            total += dp[n][k];
        }
        return total;
    }
};