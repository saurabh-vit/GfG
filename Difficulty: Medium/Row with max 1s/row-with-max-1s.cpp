// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n = arr.size();
        int m = arr[0].size();
        int ans = -1;
        int mc = 0;
        for(int i = 0; i<n; i++){
            int cs = 0;
            for(int j = 0; j<m; j++){
                if(arr[i][j] == 1){
                    cs++;
                }
            }
            if(cs>mc){
                mc = cs;
                ans = i;
            }
        }
        return ans;
    }
};