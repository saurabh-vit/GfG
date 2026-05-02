class Solution {
  public:
    int findPosition(int n) {
        // code here
        if (n == 0 || (n & (n - 1)) != 0) {
            return -1;
        }
        int position = 1;
        while ((n & 1) == 0) {
            n = n >> 1;
            position++;
        }
        return position;
    }
};