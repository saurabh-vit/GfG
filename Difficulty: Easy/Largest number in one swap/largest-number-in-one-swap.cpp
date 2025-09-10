class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        int n = s.size();
        vector<int> ans(10, -1);
        for(int i = 0; i<n; i++){
            ans[s[i] - '0'] = i;
        }
        
        for(int i =0; i<n; i++){
            int curr = s[i] - '0';
            for(int j = 9; j>curr; j--){
                if(ans[j] > i){
                    swap(s[i], s[ans[j]]);
                    return s;
                }
            }
        }
        return s;
    }
};