class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        int fresh = 0, ans = 0;

        queue<pair<int, pair<int,int>>> q;

        // Step 1: Count fresh & push rotten
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 2){
                    q.push({0, {i, j}});
                }
                else if(mat[i][j] == 1){
                    fresh++;
                }
            }
        }

        vector<int> radd = {-1, 1, 0, 0};
        vector<int> cadd = {0, 0, -1, 1};

        // Step 2: BFS
        while(!q.empty()){
            auto it = q.front(); q.pop();
            int t = it.first;
            int row = it.second.first;
            int col = it.second.second;

            ans = max(ans, t);

            for(int i = 0; i < 4; i++){
                int nrow = row + radd[i];
                int ncol = col + cadd[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && mat[nrow][ncol] == 1){
                    mat[nrow][ncol] = 2; // mark rotten
                    fresh--;             // only decrement fresh
                    q.push({t + 1, {nrow, ncol}});
                }
            }
        }

        // Step 3: Check result
        if(fresh == 0) return ans;
        return -1;
    }
};