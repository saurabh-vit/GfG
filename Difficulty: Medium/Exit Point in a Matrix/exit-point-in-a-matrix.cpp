class Solution {
public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int dir = 0; // 0=Right, 1=Down, 2=Left, 3=Up

        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};

        int i = 0, j = 0;

        while (i >= 0 && i < n && j >= 0 && j < m) {
            
            if (mat[i][j] == 1) {
                dir = (dir + 1) % 4; // turn right
                mat[i][j] = 0;
            }

            i += dr[dir];
            j += dc[dir];
        }

        // Move back to last valid cell
        i -= dr[dir];
        j -= dc[dir];

        return {i, j};
    }
};