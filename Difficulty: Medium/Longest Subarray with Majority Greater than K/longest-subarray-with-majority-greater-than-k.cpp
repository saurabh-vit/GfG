class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> diff(n);
        for (int i = 0; i < n; i++) {
            diff[i] = (arr[i] > k) ? 1 : -1;
        }
        unordered_map<int, int> prefixIndex;
        int maxLen = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += diff[i];
            if (sum > 0) {
                maxLen = i + 1;
            }
            else {
                if (prefixIndex.find(sum - 1) != prefixIndex.end()) {
                    maxLen = max(maxLen, i - prefixIndex[sum - 1]);
                }
            }
            if (prefixIndex.find(sum) == prefixIndex.end()) {
                prefixIndex[sum] = i;
            }
        }
        return maxLen;
    }
};