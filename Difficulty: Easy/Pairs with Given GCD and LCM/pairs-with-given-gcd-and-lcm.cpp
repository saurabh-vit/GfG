class Solution {
  public:
    int pairCount(int x, int y) {
        if (y % x != 0) {
            return 0;
        }
        int n = y / x;
        int count = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                int q = n / i;
                if (std::gcd(i, q) == 1) {
                    if (i == q)
                        count++;
                    else
                        count += 2;
                }
            }
        }
        return count;
    }
};