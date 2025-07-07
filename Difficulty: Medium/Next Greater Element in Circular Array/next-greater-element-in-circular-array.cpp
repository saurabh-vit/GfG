class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        int n = arr.size();
        stack<int> s;
        vector<int> ans(n, -1);
        for(int i = 2*n-1; i>=0; i--){
            int curr = arr[i%n];
            while(!s.empty() && curr>=s.top()){
                s.pop();
            }
            if(i<n){
                if(!s.empty()){
                    ans[i] = s.top();
                }
            }
            s.push(curr);
        }
        return ans;
    }
};