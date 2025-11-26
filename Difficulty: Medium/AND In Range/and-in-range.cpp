class Solution {
  public:
    int andInRange(int l, int r) {
        int shift = 0;
        // code here
         while (l < r) {
            l >>= 1;
            r >>= 1;
            shift++;
        }
        return l << shift;
    }
};
