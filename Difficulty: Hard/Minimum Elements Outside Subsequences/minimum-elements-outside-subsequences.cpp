class Solution {
  public:
    int minCount(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        dp[0][0] = 0;

        for (int k = 0; k < n; k++) {
            for (int i = -1; i < k; i++) {
                for (int j = -1; j < k; j++) {

                    int &cur = dp[i + 1][j + 1];

                    if (cur == -1)
                        continue;

                    // Option 1: Don't use arr[k]
                    dp[i + 1][j + 1] =
                        max(dp[i + 1][j + 1], cur);

                    // Option 2: Put arr[k] in increasing subsequence
                    if (i == -1 || arr[k] > arr[i]) {
                        dp[k + 1][j + 1] =
                            max(dp[k + 1][j + 1], cur + 1);
                    }

                    // Option 3: Put arr[k] in decreasing subsequence
                    if (j == -1 || arr[k] < arr[j]) {
                        dp[i + 1][k + 1] =
                            max(dp[i + 1][k + 1], cur + 1);
                    }
                }
            }
        }

        int maxSelected = 0;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                maxSelected = max(maxSelected, dp[i][j]);
            }
        }

        return n - maxSelected;
    }
};