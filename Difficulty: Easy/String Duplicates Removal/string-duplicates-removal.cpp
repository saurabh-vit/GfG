// User function template for C++
class Solution {
  public:
    string removeDuplicates(string &s) {
        // code here
        bool str[256] = {false};
        string result = "";
        for(char ch : s){
            if(!str[(unsigned char)ch]){
                str[(unsigned char)ch] = true;
                result += ch;
            }
        }
        return result;
    }
};