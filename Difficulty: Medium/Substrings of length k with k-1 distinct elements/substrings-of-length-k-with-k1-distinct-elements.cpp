class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        int n = s.size();
        if(k>n) return 0;
        int count = 0;
        vector<int> freq(26, 0);
        int unique = 0;
        
        for (int i = 0; i < k; i++) {
            if (freq[s[i] - 'a'] == 0) unique++;
            freq[s[i] - 'a']++;
        }
        if (unique == k - 1) count++;
        
        for(int i = k; i<n; i++){
            freq[s[i - k] - 'a']--;
            if (freq[s[i - k] - 'a'] == 0) unique--;
            if (freq[s[i] - 'a'] == 0) unique++;
            freq[s[i] - 'a']++;
            if (unique == k - 1) count++;
        }
        return count;
    }
};