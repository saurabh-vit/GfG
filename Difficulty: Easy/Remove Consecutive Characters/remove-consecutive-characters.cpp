class Solution {
  public:
    string removeConsecutiveCharacter(string& s) {
        // code here.
        for(int i = 1; i<s.size();){
            if(s[i]==s[i-1]){
                s.erase(i, 1);
            }else{
                i++;
            }
        }
        return s;
    }
};