class Solution {
  public:
    int findWays(vector<vector<int>>& matrix, int k) {
        const long long MOD = 1000000007;
        int n = matrix.size(), m = matrix[0].size();

        // has_one_row[p][c1] = row p has a 1 in columns c1..m-1
        vector<vector<int>> has_one_row(n, vector<int>(m+1, 0));
        for (int p = 0; p < n; p++) {
            for (int c1 = m-1; c1 >= 0; c1--) {
                has_one_row[p][c1] = (matrix[p][c1] == 1 || has_one_row[p][c1+1]) ? 1 : 0;
            }
        }

        // has_one_col[r1][q] = column q has a 1 in rows r1..n-1
        vector<vector<int>> has_one_col(n+1, vector<int>(m, 0));
        for (int r1 = n-1; r1 >= 0; r1--) {
            for (int q = 0; q < m; q++) {
                has_one_col[r1][q] = (matrix[r1][q] == 1 || has_one_col[r1+1][q]) ? 1 : 0;
            }
        }

        // L[r1][c1] = largest p < r1 with has_one_row[p][c1] == 1, else -1
        vector<vector<int>> L(n, vector<int>(m, -1));
        for (int c1 = 0; c1 < m; c1++) {
            int prev = -1;
            for (int r1 = 0; r1 < n; r1++) {
                L[r1][c1] = prev;
                if (has_one_row[r1][c1]) prev = r1;
            }
        }

        // M[c1][r1] = largest q < c1 with has_one_col[r1][q] == 1, else -1
        vector<vector<int>> M(m, vector<int>(n, -1));
        for (int r1 = 0; r1 < n; r1++) {
            int prev = -1;
            for (int c1 = 0; c1 < m; c1++) {
                M[c1][r1] = prev;
                if (has_one_col[r1][c1]) prev = c1;
            }
        }

        // total_suffix[r1][c1] = does rows[r1..n-1] x cols[c1..m-1] contain a 1?
        vector<vector<int>> total_suffix(n, vector<int>(m, 0));
        for (int c1 = 0; c1 < m; c1++) {
            int cur = 0;
            for (int r1 = n-1; r1 >= 0; r1--) {
                cur = (has_one_row[r1][c1] || cur) ? 1 : 0;
                total_suffix[r1][c1] = cur;
            }
        }

        vector<vector<long long>> f(n, vector<long long>(m, 0));
        f[0][0] = 1;

        for (int step = 1; step < k; step++) {
            // PS_row[c1][x+1] = sum_{r1'=0}^{x} f[r1'][c1]
            vector<vector<long long>> PS_row(m, vector<long long>(n+1, 0));
            for (int c1 = 0; c1 < m; c1++) {
                long long s = 0;
                for (int r1 = 0; r1 < n; r1++) {
                    s = (s + f[r1][c1]) % MOD;
                    PS_row[c1][r1+1] = s;
                }
            }

            // PS_col[r1][y+1] = sum_{c1'=0}^{y} f[r1][c1']
            vector<vector<long long>> PS_col(n, vector<long long>(m+1, 0));
            for (int r1 = 0; r1 < n; r1++) {
                long long s = 0;
                for (int c1 = 0; c1 < m; c1++) {
                    s = (s + f[r1][c1]) % MOD;
                    PS_col[r1][c1+1] = s;
                }
            }

            vector<vector<long long>> new_f(n, vector<long long>(m, 0));
            for (int r1 = 0; r1 < n; r1++) {
                for (int c1 = 0; c1 < m; c1++) {
                    long long horiz = PS_row[c1][L[r1][c1] + 1];
                    long long vert  = PS_col[r1][M[c1][r1] + 1];
                    new_f[r1][c1] = (horiz + vert) % MOD;
                }
            }
            f = move(new_f);
        }

        long long ans = 0;
        for (int r1 = 0; r1 < n; r1++) {
            for (int c1 = 0; c1 < m; c1++) {
                if (total_suffix[r1][c1]) {
                    ans = (ans + f[r1][c1]) % MOD;
                }
            }
        }
        return (int)ans;
    }
};