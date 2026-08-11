class Solution {
  public:
    vector<int> largestSquare(vector<vector<int>>& mat, vector<vector<int>>& queries,
                              int k) {
        // code here
        int n = mat.size();
        int m = mat[0].size();

        // 2D Prefix Sum
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pref[i + 1][j + 1] =
                    mat[i][j]
                    + pref[i][j + 1]
                    + pref[i + 1][j]
                    - pref[i][j];
            }
        }

        // Returns number of ones in rectangle
        // (r1,c1) to (r2,c2), inclusive
        auto getSum = [&](int r1, int c1, int r2, int c2) {
            return pref[r2 + 1][c2 + 1]
                 - pref[r1][c2 + 1]
                 - pref[r2 + 1][c1]
                 + pref[r1][c1];
        };

        vector<int> ans;

        for (auto &q : queries) {
            int i = q[0];
            int j = q[1];

            // Maximum possible radius without going outside matrix
            int maxRadius = min({
                i,
                n - 1 - i,
                j,
                m - 1 - j
            });

            // If even the 1x1 square has more than k ones
            if (mat[i][j] > k) {
                ans.push_back(-1);
                continue;
            }

            int low = 0;
            int high = maxRadius;
            int best = 0;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                int r1 = i - mid;
                int c1 = j - mid;
                int r2 = i + mid;
                int c2 = j + mid;

                int ones = getSum(r1, c1, r2, c2);

                if (ones <= k) {
                    // This square is valid
                    best = mid;
                    low = mid + 1;
                } else {
                    // Need a smaller square
                    high = mid - 1;
                }
            }

            ans.push_back(2 * best + 1);
        }

        return ans;
    }
};