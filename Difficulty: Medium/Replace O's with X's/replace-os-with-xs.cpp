class Solution {
  public:
    void bfsMark(vector<vector<char>> &grid, int i, int j, int n, int m) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 'B'; // Mark as boundary-connected 'O'

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 'O') {
                    grid[nx][ny] = 'B';
                    q.push({nx, ny});
                }
            }
        }
    }

    void fill(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Step 1: Mark all boundary-connected 'O's as 'B'
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 'O') bfsMark(grid, i, 0, n, m);
            if (grid[i][m - 1] == 'O') bfsMark(grid, i, m - 1, n, m);
        }

        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 'O') bfsMark(grid, 0, j, n, m);
            if (grid[n - 1][j] == 'O') bfsMark(grid, n - 1, j, n, m);
        }

        // Step 2: Convert surrounded 'O' → 'X' and 'B' → 'O'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'O') grid[i][j] = 'X';
                else if (grid[i][j] == 'B') grid[i][j] = 'O';
            }
        }
    }
};
