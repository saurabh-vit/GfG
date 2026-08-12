class Solution {
public:
    vector<int> findWays(vector<vector<int>>& grid) {
        int n = grid.size();
        const int MOD = 1000000007;

        vector<vector<long long>> paths(n, vector<long long>(n, 0));
        vector<vector<long long>> adventure(n, vector<long long>(n, -1));

        // Starting cell
        paths[0][0] = 1;
        adventure[0][0] = grid[0][0];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (paths[i][j] == 0)
                    continue;

                // Move Right
                if ((grid[i][j] == 1 || grid[i][j] == 3) &&
                    j + 1 < n) {

                    paths[i][j + 1] =
                        (paths[i][j + 1] + paths[i][j]) % MOD;

                    adventure[i][j + 1] =
                        max(adventure[i][j + 1],
                            adventure[i][j] + grid[i][j + 1]);
                }

                // Move Down
                if ((grid[i][j] == 2 || grid[i][j] == 3) &&
                    i + 1 < n) {

                    paths[i + 1][j] =
                        (paths[i + 1][j] + paths[i][j]) % MOD;

                    adventure[i + 1][j] =
                        max(adventure[i + 1][j],
                            adventure[i][j] + grid[i + 1][j]);
                }
            }
        }

        // No valid path exists
        if (paths[n - 1][n - 1] == 0) {
            return {0, 0};
        }

        return {
            (int)paths[n - 1][n - 1],
            (int)adventure[n - 1][n - 1]
        };
    }
};