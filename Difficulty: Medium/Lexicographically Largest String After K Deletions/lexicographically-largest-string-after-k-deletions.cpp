class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
        int n = s.size();
        int keep = n - k;
        string result;
        for (char c : s) {
            while (!result.empty() && result.back() < c && k > 0) {
                result.pop_back();
                k--;
            }
            result.push_back(c);
        }
        result.resize(keep);
        return result;
    }
};
