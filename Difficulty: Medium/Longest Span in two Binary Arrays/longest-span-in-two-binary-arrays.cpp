class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        // code here
        int n = a1.size();
        unordered_map<int, int> mp;
        int prefix_sum = 0;
        int max_len = 0;
        for (int i = 0; i < n; i++) {
            // Create difference on the fly
            prefix_sum += (a1[i] - a2[i]);
            // If prefix sum becomes 0, span from 0 to i
            if (prefix_sum == 0)
                max_len = i + 1;
            
            // If prefix_sum seen before
            if (mp.find(prefix_sum) != mp.end()) {
                max_len = max(max_len, i - mp[prefix_sum]);
            } else {
                // Store first occurrence
                mp[prefix_sum] = i;
            }
        }
        return max_len;
    }
};