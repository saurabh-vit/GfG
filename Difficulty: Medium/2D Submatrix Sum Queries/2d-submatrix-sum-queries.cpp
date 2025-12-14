class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        // code here
        int n = mat.size();
        int m = mat[0].size();

        // Step 1: Build Prefix Sum Matrix
        vector<vector<long long>> pref(n, vector<long long>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                long long up = (i > 0 ? pref[i-1][j] : 0);
                long long left = (j > 0 ? pref[i][j-1] : 0);
                long long diag = (i > 0 && j > 0 ? pref[i-1][j-1] : 0);

                pref[i][j] = mat[i][j] + up + left - diag;
            }
        }

        // Step 2: Answer queries
        vector<int> ans;
        for(auto &q : queries) {
            int r1 = q[0], c1 = q[1];
            int r2 = q[2], c2 = q[3];

            long long sum = pref[r2][c2];

            if(c1 > 0) sum -= pref[r2][c1 - 1];
            if(r1 > 0) sum -= pref[r1 - 1][c2];
            if(r1 > 0 && c1 > 0) sum += pref[r1 - 1][c1 - 1];

            ans.push_back(sum);
        }

        return ans;
    }
};
