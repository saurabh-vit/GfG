class Solution {
  public:
    int numOfWays(int n, int m) {
        // code here
        long long cells = 1LL * n * m;
        long long total = cells * (cells - 1);
        long long attacking = 0;
        if (n >= 2 && m >= 3)
            attacking += 1LL * (n - 1) * (m - 2);
        if (n >= 3 && m >= 2)
            attacking += 1LL * (n - 2) * (m - 1);
        attacking *= 4;
        return total - attacking;
    }
};
