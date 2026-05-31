class Solution {
  public:
    bool isSumOfConsecutive(int n) {
        // code here
        return n > 1 && (n & (n - 1));
    }
};