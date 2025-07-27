class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<bool> row(n, false), col(m, false);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j]==0){
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(row[i] || col[j]){
                    mat[i][j] = 0;
                }
            }
        }
        
    }
};