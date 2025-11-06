class Solution {
  public:
    int numberOfWays(int n) {
        // code here
        if (n == 1) return 1;
        if (n == 2) return 2;
        long long a = 1; // ways[1]
        long long b = 2; // ways[2]
        for(int i = 3; i <= n; ++i) {
            long long c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};