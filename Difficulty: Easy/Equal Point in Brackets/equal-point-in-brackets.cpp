class Solution {
  public:
    int findIndex(string &s) {
        // code here
        int n = s.size();
        int r = 0;
        for(int i = 0; i<n; i++){
            if(s[i]==')'){
                r++;
            }
        }
        
        int l = 0;
        for(int i = 0; i<n; i++){
            if(l==r){
                return i;
            }
            if(s[i] == '('){
                l++;
            }
            if(s[i] == ')'){
                r--;
            }
        }
        if(l == r) {
            return n;
        }
        return -1;
    }
};