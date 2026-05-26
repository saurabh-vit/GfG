class Solution {
  public:
    int minToggle(vector<int>& arr) {
        // code here
         int n = arr.size();

        vector<int> prefix1(n + 1, 0);
        vector<int> suffix0(n + 1, 0);

        // Count 1s from left
        for (int i = 0; i < n; i++) {
            prefix1[i + 1] = prefix1[i] + (arr[i] == 1);
        }

        // Count 0s from right
        for (int i = n - 1; i >= 0; i--) {
            suffix0[i] = suffix0[i + 1] + (arr[i] == 0);
        }

        int ans = n;

        // Try every partition
        for (int i = 0; i <= n; i++) {
            ans = min(ans, prefix1[i] + suffix0[i]);
        }

        return ans;
    }
};