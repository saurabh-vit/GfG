class Solution {
  public:
    int maxSubsetXOR(vector<int> &arr) {
        // code here
        const int MAXB = 31;
        vector<int> basis(MAXB + 1, 0);

        // Build XOR basis
        for (int x : arr) {
            int num = x;
            for (int b = MAXB; b >= 0; b--) {
                if (!(num & (1 << b))) continue;

                if (!basis[b]) {
                    basis[b] = num;
                    break;
                }

                num ^= basis[b];
            }
        }

        // Find maximum XOR
        int ans = 0;
        for (int b = MAXB; b >= 0; b--) {
            ans = max(ans, ans ^ basis[b]);
        }

        return ans;
    }
};