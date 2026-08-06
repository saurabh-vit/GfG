class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        // code here
        int inc = 0;
        int dbl = 0;

        for (int x : arr) {
            inc += __builtin_popcount(x);

            if (x > 0) {
                int bits = 31 - __builtin_clz(x);
                dbl = max(dbl, bits);
            }
        }

        return inc + dbl;
    }
};