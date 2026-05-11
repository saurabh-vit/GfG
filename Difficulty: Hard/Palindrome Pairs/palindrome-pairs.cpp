class Solution {
  public:
  
    bool isPal(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
  
    bool palindromePair(vector<string>& arr) {
        unordered_map<string, int> mp;
        
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }
        
        for (int i = 0; i < n; i++) {
            string s = arr[i];
            int len = s.length();
            
            for (int j = 0; j <= len; j++) {
                
                string left = s.substr(0, j);
                string right = s.substr(j);
                
                // Case 1: left part is palindrome
                if (isPal(s, 0, j - 1)) {
                    string revRight = right;
                    reverse(revRight.begin(), revRight.end());
                    
                    if (mp.count(revRight) && mp[revRight] != i) {
                        return true;
                    }
                }
                
                // Case 2: right part is palindrome
                if (j != len && isPal(s, j, len - 1)) {
                    string revLeft = left;
                    reverse(revLeft.begin(), revLeft.end());
                    
                    if (mp.count(revLeft) && mp[revLeft] != i) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};