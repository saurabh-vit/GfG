class Solution {
public:
    int n, m;
    vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int i, int j, vector<vector<int>>& mat,
             vector<vector<int>>& vis) {

        vis[i][j] = 1;

        for (auto &d : dir) {
            int ni = i + d[0];
            int nj = j + d[1];

            if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                !vis[ni][nj] &&
                mat[ni][nj] >= mat[i][j]) {

                dfs(ni, nj, mat, vis);
            }
        }
    }

    int countCoordinates(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();

        vector<vector<int>> visP(n, vector<int>(m, 0));
        vector<vector<int>> visQ(n, vector<int>(m, 0));

        // Station P (Top row)
        for (int j = 0; j < m; j++)
            dfs(0, j, mat, visP);

        // Station P (Left column)
        for (int i = 0; i < n; i++)
            dfs(i, 0, mat, visP);

        // Station Q (Bottom row)
        for (int j = 0; j < m; j++)
            dfs(n - 1, j, mat, visQ);

        // Station Q (Right column)
        for (int i = 0; i < n; i++)
            dfs(i, m - 1, mat, visQ);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visP[i][j] && visQ[i][j])
                    ans++;
            }
        }

        return ans;
    }
};