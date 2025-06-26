class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        // write code here
        vector<int> ans(n);
        stack<int> s;
        for(int i = 0; i<n; i++){
            int curr = arr[i];
            while(!s.empty() && curr >= arr[s.top()]){
                s.pop();
            }
            if(s.empty()){
                ans[i] = i+1;
            }else{
                ans[i] = i-s.top();
            }
            s.push(i);
        }
        return ans;
    }
};