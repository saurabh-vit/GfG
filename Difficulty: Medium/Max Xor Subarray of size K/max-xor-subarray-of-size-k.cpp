class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int currXor = 0;
        for (int i = 0; i < k; i++) {
            currXor ^= arr[i];
        }
        int maxXor = currXor;
        for (int i = k; i < n; i++) {
            currXor ^= arr[i - k];  // remove left element
            currXor ^= arr[i];      // add right element
            maxXor = max(maxXor, currXor);
        }
        return maxXor;
    }
};