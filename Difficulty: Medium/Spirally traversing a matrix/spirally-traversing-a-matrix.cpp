//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        vector<int> ans;
        int rs = 0, cs = 0, re = n-1, ce = m-1;
        while(rs<=re && cs<=ce){
            for(int i = cs; i<=ce; i++){
                ans.push_back(mat[rs][i]);
            }
            rs++;
            for(int i = rs; i<=re; i++){
                ans.push_back(mat[i][ce]);
            }
            ce--;
            if (rs <= re) {
                for(int i = ce; i>=cs; i--){
                    ans.push_back(mat[re][i]);
                }
                re--;
            }
            if (cs <= ce) {
                for(int i = re; i>=rs; i--){
                    ans.push_back(mat[i][cs]);
                }
                cs++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends