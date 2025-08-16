class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        vector<string> ans;
        for(int x : arr){
            ans.push_back(to_string(x));
        }
        
        sort(ans.begin(), ans.end(), [](string &a, string &b){
            return a+b > b+a;
        });
        
        if(ans[0] == "0") return "0";
        
        string result = "";
        for(string &s : ans){
            result += s;
        }
        return result;
    }
};