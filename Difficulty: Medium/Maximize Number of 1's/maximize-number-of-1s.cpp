class Solution {
  public:
    // k is the maximum number of zeros allowed to flip
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int left = 0, len = 0, count = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] == 0) {
                count++;
            }
            while (count > k) {
                if (arr[left] == 0) {
                    count--;
                }
                left++;
            }
            len = max(len, i-left + 1);
        }
        return len;
    }
};

