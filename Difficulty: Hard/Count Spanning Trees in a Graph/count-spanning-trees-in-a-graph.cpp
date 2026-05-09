class Solution {
  public:
    
    // Function to calculate determinant using Gaussian Elimination
    long long determinant(vector<vector<double>> mat, int n) {
        
        double det = 1;

        for(int i = 0; i < n; i++) {

            int pivot = i;

            // Find non-zero pivot
            while(pivot < n && abs(mat[pivot][i]) < 1e-9) {
                pivot++;
            }

            // If no pivot found
            if(pivot == n)
                return 0;

            // Swap rows if needed
            if(pivot != i) {
                swap(mat[pivot], mat[i]);
                det *= -1;
            }

            det *= mat[i][i];

            // Eliminate below rows
            for(int j = i + 1; j < n; j++) {

                double factor = mat[j][i] / mat[i][i];

                for(int k = i; k < n; k++) {
                    mat[j][k] -= factor * mat[i][k];
                }
            }
        }

        return round(det);
    }

    int countSpanTree(int n, vector<vector<int>>& edges) {
        
        // Special case
        if(n == 1)
            return 1;

        // Step 1: Build Laplacian Matrix
        vector<vector<double>> lap(n, vector<double>(n, 0));

        for(auto &e : edges) {

            int u = e[0];
            int v = e[1];

            lap[u][u]++;
            lap[v][v]++;

            lap[u][v] = -1;
            lap[v][u] = -1;
        }

        // Step 2: Create minor matrix
        // Remove last row and last column
        vector<vector<double>> minor(n - 1, vector<double>(n - 1));

        for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < n - 1; j++) {
                minor[i][j] = lap[i][j];
            }
        }

        // Step 3: Determinant gives number of spanning trees
        return determinant(minor, n - 1);
    }
};