class Solution {
  public:
    int chocolatePickup(vector<vector<int>> &mat) {
        int n = (int)mat.size();
        if (n == 0) return 0;
        if (mat[0][0] == -1 || mat[n-1][n-1] == -1) return 0;

        const int NEG = -1e9;
        int K = 2 * n - 2;

        // dp[k][r1][r2] rolled over k: prev and cur are n x n
        vector<vector<int>> prev(n, vector<int>(n, NEG));
        vector<vector<int>> cur(n, vector<int>(n, NEG));

        // step 0: both at (0,0)
        prev[0][0] = mat[0][0];

        for (int k = 1; k <= K; ++k) {
            for (int r1 = 0; r1 < n; ++r1)
                fill(cur[r1].begin(), cur[r1].end(), NEG);

            for (int r1 = 0; r1 < n; ++r1) {
                int c1 = k - r1;
                if (c1 < 0 || c1 >= n) continue;
                if (mat[r1][c1] == -1) continue;

                for (int r2 = 0; r2 < n; ++r2) {
                    int c2 = k - r2;
                    if (c2 < 0 || c2 >= n) continue;
                    if (mat[r2][c2] == -1) continue;

                    int best = NEG;

                    // previous step combinations:
                    // walker1 from (r1-1,c1) or (r1,c1-1)
                    // walker2 from (r2-1,c2) or (r2,c2-1)
                    for (int dr1 = 0; dr1 <= 1; ++dr1) {
                        int pr1 = r1 - dr1;
                        int pc1 = (k - 1) - pr1;
                        if (pr1 < 0 || pc1 < 0 || pr1 >= n || pc1 >= n) continue;

                        for (int dr2 = 0; dr2 <= 1; ++dr2) {
                            int pr2 = r2 - dr2;
                            int pc2 = (k - 1) - pr2;
                            if (pr2 < 0 || pc2 < 0 || pr2 >= n || pc2 >= n) continue;

                            if (prev[pr1][pr2] == NEG) continue;
                            best = max(best, prev[pr1][pr2]);
                        }
                    }

                    if (best == NEG) continue;

                    int gain = mat[r1][c1];
                    if (r1 != r2 || c1 != c2) gain += mat[r2][c2];
                    cur[r1][r2] = max(cur[r1][r2], best + gain);
                }
            }
            swap(prev, cur);
        }

        int ans = prev[n-1][n-1];
        return max(0, ans);
    }
};