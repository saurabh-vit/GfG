class Solution {
public:
    vector<vector<int>> ans;

    bool issafe(vector<int>& board, int col, int row) {
        for (int prevCol = 0; prevCol < col; prevCol++) {
            int prevRow = board[prevCol];
            // Check same row
            if (prevRow == row) return false;
            // Check diagonals
            if (abs(prevRow - row) == abs(prevCol - col)) return false;
        }
        return true;
    }

    void solve(int col, int n, vector<int>& board) {
        if (col == n) {
            vector<int> res = board;
            for (int& r : res) r++; // convert 0-based to 1-based
            ans.push_back(res);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (issafe(board, col, row)) {
                board[col] = row;
                solve(col + 1, n, board);
                // backtrack not needed here as we're overwriting board[col]
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<int> board(n, -1); // board[col] = row
        solve(0, n, board);
        return ans;
    }
};
