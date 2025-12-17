class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        if (arr.empty()) return {};
        
        sort(arr.begin(), arr.end());  // sort by start time
        
        vector<vector<int>> ans;
        ans.push_back(arr[0]);
        
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i][0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }
            else {
                ans.push_back(arr[i]);
            }
        }
        
        return ans;
    }
};