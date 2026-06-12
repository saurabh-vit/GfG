class Solution {
  public:
    bool kSubstr(string &s, int k) {
        // code here
         int n = s.size();

        if (n % k != 0)
            return false;

        unordered_map<string, int> freq;
        int blocks = n / k;
        int maxFreq = 0;

        for (int i = 0; i < n; i += k) {
            string block = s.substr(i, k);
            maxFreq = max(maxFreq, ++freq[block]);
        }

        return (blocks - maxFreq <= 1);
    }
};