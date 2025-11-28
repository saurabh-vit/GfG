class Solution {
public:
    vector<int> subsetXOR(int n) {
        vector<int> ans;

        // compute XOR from 1 to n
        int full = 0;
        for (int i = 1; i <= n; i++) full ^= i;

        if (full == n) {
            // use full set
            ans.resize(n);
            for (int i = 1; i <= n; i++) ans[i - 1] = i;
        } else {
            int rem = full ^ n;   // number to remove

            for (int i = 1; i <= n; i++) {
                if (i != rem) ans.push_back(i);
            }
        }

        return ans;
    }
};
