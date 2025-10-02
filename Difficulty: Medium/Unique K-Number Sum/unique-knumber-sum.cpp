class Solution {
  public:
    vector<vector<int>> ans;
    
    void backtrack(int st, int k, int n, vector<int> &path){
        if(path.size()==k && n==0){
            ans.push_back(path);
            return;
        }
        
        if(path.size()>k || n<0){
            return;
        }
        
        for(int i = st; i<=9; i++){
            path.push_back(i);
            backtrack(i+1, k, n-i, path);
            path.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        vector<int> path;
        backtrack(1, k, n, path);
        return ans;
    }
};