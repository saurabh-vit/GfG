class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int cand = 0;

        // Step 1: Find candidate
        for(int i = 1; i < n; i++) {
            if(mat[cand][i] == 1) {
                cand = i;  // cand knows i → cand cannot be celebrity
            }
        }

        // Step 2: Verify candidate
        for(int i = 0; i < n; i++) {
            if(i == cand) continue;
            if(mat[cand][i] == 1 || mat[i][cand] == 0) {
                return -1;
            }
        }

        return cand;
    }
};