class Solution {
public:
    long long findMaxProduct(vector<int>& arr) {
        const long long MOD = 1000000007;

        int n = arr.size();

        if (n == 1)
            return arr[0];

        int negCount = 0, zeroCount = 0;
        int maxNeg = INT_MIN;

        for (int x : arr) {
            if (x == 0)
                zeroCount++;
            else if (x < 0) {
                negCount++;
                maxNeg = max(maxNeg, x); // closest negative to 0
            }
        }

        // All zeros
        if (zeroCount == n)
            return 0;

        // Only one negative and rest zeros
        if (negCount == 1 && zeroCount + negCount == n)
            return 0;

        long long ans = 1;
        bool removed = false;

        for (int x : arr) {
            if (x == 0)
                continue;

            if (negCount % 2 && x == maxNeg && !removed) {
                removed = true;
                continue;
            }

            long long val = x;

            // handle negative modulo properly
            val = ((val % MOD) + MOD) % MOD;

            ans = (ans * val) % MOD;
        }

        return ans;
    }
};