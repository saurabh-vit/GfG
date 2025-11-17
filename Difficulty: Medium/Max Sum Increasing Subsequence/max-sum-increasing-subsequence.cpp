class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> dp(n);
    
        // Initialize dp with the value of elements
        for (int i = 0; i < n; i++)
            dp[i] = arr[i];
        int maxSum = arr[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    dp[i] = max(dp[i], dp[j] + arr[i]);
                }
            }
            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
    }
};