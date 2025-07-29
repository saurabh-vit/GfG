class Solution {
  public:
    vector<int> asciirange(string& s) {
        int n = s.size();
        vector<int> ans;
        unordered_map<char, pair<int, int>> pos;
        for(int i = 0; i < n; i++) {
            if(pos.find(s[i]) == pos.end()) {
                pos[s[i]].first = i;
            }
            pos[s[i]].second = i;
        }
        vector<int> final;
        for(auto it : pos) {
            int start = it.second.first;
            int end = it.second.second;
            if(end > start + 1) {
                int sum = 0;
                for(int i = start + 1; i < end; i++) {
                    sum += s[i];
                }
                final.push_back(sum);
            }
        }
        return final;
    }
};