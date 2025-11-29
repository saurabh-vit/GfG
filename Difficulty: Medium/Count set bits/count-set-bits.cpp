class Solution {
public:
    int countSetBits(int n) {
        if (n == 0) return 0;

        // Step 1: find largest power of 2 <= n
        int x = log2(n);

        // Step 2: count bits from 1 to 2^x - 1
        int bitsTill2x = x * (1 << (x - 1));

        // Step 3: count MSB bits from 2^x to n
        int msbBits = n - (1 << x) + 1;

        // Step 4: recursion for remaining numbers
        int rest = n - (1 << x);

        return bitsTill2x + msbBits + countSetBits(rest);
    }
};
