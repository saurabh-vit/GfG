class Solution {
public:
    int shortestPath(vector<vector<int>> &mat) {

        int n = mat.size();
        int m = mat[0].size();

        // safe[i][j] = true means we can travel through this cell
        vector<vector<bool>> safe(n, vector<bool>(m, true));

        // Directions: up, down, left, right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // ------------------------------------------------
        // STEP 1: Mark mines and their adjacent cells unsafe
        // ------------------------------------------------
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Found a mine
                if (mat[i][j] == 0) {

                    // Mine itself is unsafe
                    safe[i][j] = false;

                    // Its 4 adjacent cells are also unsafe
                    for (int k = 0; k < 4; k++) {

                        int ni = i + dr[k];
                        int nj = j + dc[k];

                        // Check boundaries
                        if (ni >= 0 && ni < n &&
                            nj >= 0 && nj < m) {

                            safe[ni][nj] = false;
                        }
                    }
                }
            }
        }

        // ------------------------------------------------
        // STEP 2: Multi-source BFS
        // ------------------------------------------------

        queue<pair<int, int>> q;

        // Distance from the starting cell
        vector<vector<int>> dist(n, vector<int>(m, -1));

        // Start from every safe cell in the first column
        for (int i = 0; i < n; i++) {

            if (safe[i][0]) {

                q.push({i, 0});

                // Starting cell counts as 1
                dist[i][0] = 1;
            }
        }

        // ------------------------------------------------
        // STEP 3: BFS
        // ------------------------------------------------

        while (!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            // Reached the last column
            if (c == m - 1) {
                return dist[r][c];
            }

            // Explore 4 directions
            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                // Check boundaries
                if (nr < 0 || nr >= n ||
                    nc < 0 || nc >= m) {
                    continue;
                }

                // Cell must be safe and unvisited
                if (safe[nr][nc] && dist[nr][nc] == -1) {

                    dist[nr][nc] = dist[r][c] + 1;

                    q.push({nr, nc});
                }
            }
        }

        // No safe path exists
        return -1;
    }
};