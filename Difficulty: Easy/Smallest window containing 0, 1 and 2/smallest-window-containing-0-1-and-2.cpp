class Solution {
  public:
    int smallestSubstring(string s) {
        // code here
        int n = s.size();
        vector<int> count(3, 0); // for '0', '1', '2'
        
        int left = 0;
        int minLen = INT_MAX;
        
        for (int right = 0; right < n; right++) {
            // include current character
            count[s[right] - '0']++;
            
            // check if window has all 3 characters
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                minLen = min(minLen, right - left + 1);
                
                // shrink window
                count[s[left] - '0']--;
                left++;
            }
        }
        return (minLen == INT_MAX) ? -1 : minLen;
    }
};
