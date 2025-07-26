class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> ans;
        unordered_map<int, int> freq;
        
        for(int i = 0; i<n; i++){
            freq[arr[i]]++;
        }
        
        unordered_set<int> added;
        for(int i = 0; i<n; i++){
            if(freq[arr[i]]>n/3 && added.find(arr[i])==added.end()){
                ans.push_back(arr[i]);
                added.insert(arr[i]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};