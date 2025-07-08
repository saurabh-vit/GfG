class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        int n = arr.size();
        unordered_map<int, int>freq;
        for(int num : arr){
            freq[num]++;
        }
        
        stack<int> s;
        vector<int> ans(n, -1);
        for(int i = n-1; i>=0; i--){
            while(!s.empty() && freq[s.top()] <= freq[arr[i]]){
                s.pop();
            }
            if(!s.empty()){
                ans[i] = s.top();
            }
            s.push(arr[i]);
        }
        return ans;
    }
};
