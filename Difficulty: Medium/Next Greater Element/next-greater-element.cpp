class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        vector<int> ans(n, -1);
        for(int i = n-1; i>=0; i--){
            int curr = arr[i];
            while(!s.empty() && curr>=s.top()){
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