class Solution {
public:
    bool divisibleByK(vector<int>& arr, int k) {

        vector<bool> dp(k, false);

        for (int num : arr) {

            vector<bool> ndp(dp);

            // subset containing only current element
            ndp[num % k] = true;

            // extend previous subsets
            for (int r = 0; r < k; r++) {
                if (dp[r]) {
                    ndp[(r + num) % k] = true;
                }
            }

            dp = ndp;

            if (dp[0])
                return true;
        }

        return false;
    }
};