class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        vector<pair<int, int>> freq;
        int count = 1;
        for(int i = 1; i<=n; i++){
            if(i<n && arr[i] == arr[i-1]){
                count++;
            }else{
                freq.push_back({count, arr[i-1]});
                count = 1;
            }
        }
        
        sort(freq.begin(), freq.end(), [](auto &a, auto &b){
            if(a.first == b.first){
                return a.second>b.second;
            }
            return a.first>b.first;
        });
        
        vector<int> ans;
        for(int i = 0; i<k && i<freq.size(); i++){
            ans.push_back(freq[i].second);
        }
        return ans;
    }
};
