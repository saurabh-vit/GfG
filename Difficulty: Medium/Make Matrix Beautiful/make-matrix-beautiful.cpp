class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        vector<int> row(n, 0), col(n, 0);
        int total = 0;
        int maxsum = 0;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                row[i] += mat[i][j];
                col[j] += mat[i][j];
                total += mat[i][j];
            }
        }
        
        for(int i = 0; i<n; i++){
            maxsum = max(maxsum, row[i]);
            maxsum = max(maxsum, col[i]);
        }
        
        int total2 = maxsum*n;
        int opration = total2 - total;
        return opration;
    }
};