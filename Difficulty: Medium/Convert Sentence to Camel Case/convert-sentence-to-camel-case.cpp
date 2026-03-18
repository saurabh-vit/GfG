class Solution {
  public:
    string convertToCamelCase(string& s) {
        string ans = "";
        bool capitalize = false;
        
        for(char c : s) {
            if(c == ' ') {
                capitalize = true;
            } 
            else {
                if(capitalize) {
                    ans.push_back(toupper(c));
                    capitalize = false;
                } else {
                    ans.push_back(c);
                }
            }
        }
        
        return ans;
    }
};