class Solution {
  public:
    vector<string> binstr(int n) {
        // code here
        vector<string> result;
        int total = 1 << n;
        for(int i = 0; i<total; i++){
            string curr = "";
            for(int j = n-1; j>=0; j--){
                curr += ((i>>j) & 1) ? "1" : "0";
            }
            result.push_back(curr);
        }
        return result;
    }
};