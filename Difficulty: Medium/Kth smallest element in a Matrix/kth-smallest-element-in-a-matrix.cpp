class Solution {
  public:
    int countLessEqual(vector<vector<int>> &mat, int mid) {
        int n = mat.size();
        int row = n - 1, col = 0;
        int count = 0;

        // Start from bottom-left
        while (row >= 0 && col < n) {
            if (mat[row][col] <= mid) {
                count += (row + 1);
                col++;
            } else {
                row--;
            }
        }
        return count;
    }

    int kthSmallest(vector<vector<int>> &mat, int k) {
        int n = mat.size();
        int low = mat[0][0];
        int high = mat[n - 1][n - 1];

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (countLessEqual(mat, mid) < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};