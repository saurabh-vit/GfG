class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
        // code here
        int n = arr.size();

        if (n == 1)
            return arr[0];

        vector<int> left(n), right(n);

        // Maximum subarray sum ending at each index
        left[0] = arr[0];
        int ans = arr[0];

        for (int i = 1; i < n; i++) {
            left[i] = max(arr[i], left[i - 1] + arr[i]);
            ans = max(ans, left[i]);   // Case: no deletion
        }

        // Maximum subarray sum starting at each index
        right[n - 1] = arr[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(arr[i], right[i + 1] + arr[i]);
        }

        // Try deleting each element
        for (int i = 1; i < n - 1; i++) {
            ans = max(ans, left[i - 1] + right[i + 1]);
        }

        return ans;
    }
};