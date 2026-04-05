class Solution {
  public:
    int totalWays(vector<int>& arr, int target) {
        //  code here
        int total_sum = 0;
    for (int num : arr) total_sum += num;

    // Edge cases
    if ((target + total_sum) % 2 != 0 || abs(target) > total_sum)
        return 0;

    int subset_sum = (target + total_sum) / 2;

    vector<int> dp(subset_sum + 1, 0);
    dp[0] = 1;

    for (int num : arr) {
        for (int j = subset_sum; j >= num; j--) {
            dp[j] += dp[j - num];
        }
    }

    return dp[subset_sum];
    }
};