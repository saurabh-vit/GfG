class Solution {
public:
    long long sumMatrix(long long n, long long q) {
        long long low  = max(1LL, q - n);
        long long high = min(n, q - 1);
        if (low > high) return 0;
        return high - low + 1;
    }
};
