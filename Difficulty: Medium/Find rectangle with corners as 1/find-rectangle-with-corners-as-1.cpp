class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        // code here
        int rows = mat.size();
    if (rows == 0) return false;
    int cols = mat[0].size();

    // For every pair of columns
    for (int c1 = 0; c1 < cols; ++c1) {
        for (int c2 = c1 + 1; c2 < cols; ++c2) {
            unordered_set<int> seenRows;

            for (int r = 0; r < rows; ++r) {
                if (mat[r][c1] == 1 && mat[r][c2] == 1) {
                    if (seenRows.count(r)) {
                        return true; // Already seen this row pair — rectangle formed
                    }
                    seenRows.insert(r);
                }
            }

            // We only need to see 2 rows with both c1 and c2 = 1
            if (seenRows.size() >= 2) {
                return true;
            }
        }
    }

    return false;
    }
};