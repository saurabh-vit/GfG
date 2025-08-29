class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        // code here
        if (s.size() < p.size()) return "";
        vector<int> need(26, 0), have(26, 0);
        int required = 0;
        for (char c : p) {
            if (need[c - 'a'] == 0) required++; 
            need[c - 'a']++;
        }
        int left = 0, right = 0, formed = 0;
        int minLen = INT_MAX, startIdx = 0;
        while (right < s.size()) {
            char c = s[right];
            have[c - 'a']++;
            if (have[c - 'a'] == need[c - 'a']) 
                formed++;
            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }
                char lch = s[left];
                have[lch - 'a']--;
                if (have[lch - 'a'] < need[lch - 'a']) 
                    formed--;
                left++;
            }
            right++;
        }
        return (minLen == INT_MAX) ? "" : s.substr(startIdx, minLen);
    }
};