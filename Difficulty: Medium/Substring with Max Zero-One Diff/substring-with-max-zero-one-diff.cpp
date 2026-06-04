class Solution {
  public:
    int maxSubstring(string &s) {
        // code here
        int currSum = 0;
        int maxSum = INT_MIN;

        for (char ch : s) {
            int val = (ch == '0') ? 1 : -1;

            currSum = max(val, currSum + val);
            maxSum = max(maxSum, currSum);
        }

        return (maxSum <= 0) ? -1 : maxSum;
    }
};