class Solution {
public:
    int countSquare(vector<vector<int>>& mat, int x) {
        
        int n = mat.size();
        int m = mat[0].size();
        int count = 0;
        
        vector<vector<int>> pre(n, vector<int>(m));
        
        // Build prefix matrix
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                pre[i][j] = mat[i][j];
                
                if(i > 0)
                    pre[i][j] += pre[i-1][j];
                    
                if(j > 0)
                    pre[i][j] += pre[i][j-1];
                    
                if(i > 0 && j > 0)
                    pre[i][j] -= pre[i-1][j-1];
            }
        }
        
        // Check all squares
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                for(int size = 0; i+size < n && j+size < m; size++){
                    
                    int r = i + size;
                    int c = j + size;
                    
                    int sum = pre[r][c];
                    
                    if(i > 0)
                        sum -= pre[i-1][c];
                        
                    if(j > 0)
                        sum -= pre[r][j-1];
                        
                    if(i > 0 && j > 0)
                        sum += pre[i-1][j-1];
                        
                    if(sum == x)
                        count++;
                }
            }
        }
        
        return count;
    }
};