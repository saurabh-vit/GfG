class Solution {
  public:
    string removeConsecutiveCharacter(string& s) {
        // code here.
        int n = s.length();
        string ans = "";
        for(int i = 0; i<n; i++){
            if(s[i] != s[i+1]){
                ans += s[i];
            }else if(s[i] == s[i+1]){
                continue;
            }
        }
        return ans;
    }
};