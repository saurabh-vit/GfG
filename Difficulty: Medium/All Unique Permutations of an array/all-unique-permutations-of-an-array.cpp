class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(arr.size(), false);
        
        sort(arr.begin(), arr.end()); // sort to handle duplicates
        backtrack(arr, ans, temp, used);
        
        return ans;
    }

  private:
    void backtrack(vector<int>& arr, vector<vector<int>>& ans, vector<int>& temp, vector<bool>& used) {
        if(temp.size() == arr.size()) {
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < arr.size(); i++) {
            // skip used
            if(used[i]) continue;

            // skip duplicates
            if(i > 0 && arr[i] == arr[i-1] && !used[i-1]) continue;

            used[i] = true;
            temp.push_back(arr[i]);

            backtrack(arr, ans, temp, used);

            // backtrack step
            temp.pop_back();
            used[i] = false;
        }
    }
};