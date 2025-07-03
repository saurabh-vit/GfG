class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.size();
        vector<int> freq(26, 0);
        int left = 0, right = 0;
        int dist = 0;
        int maxlen = -1;
        while(right<n){
            if(freq[s[right]-'a']==0){
                dist++;
            }
            freq[s[right]-'a']++;
            while(dist > k){
                freq[s[left] - 'a']--;
                if(freq[s[left] - 'a'] == 0){
                    dist--;
                }
                left++;
            }
            if(dist==k){
                maxlen = max(maxlen, right - left + 1);
            }
            right++;
        }
        return maxlen;
    }
};