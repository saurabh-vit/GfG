class Solution {
  public:
    vector<string> findExpr(string &s, int target) {
        vector<string> res;
        dfs(s, target, 0, 0, 0, "", res);
        sort(res.begin(), res.end());  // Lexicographically smallest order
        return res;
    }

  private:
    void dfs(string &num, long target, int pos, long currVal, long lastVal,
             string path, vector<string> &res) {
        // Base case: if we've used all digits
        if (pos == num.size()) {
            if (currVal == target) res.push_back(path);
            return;
        }

        for (int i = pos; i < num.size(); ++i) {
            // Prevent numbers with leading zeros
            if (i != pos && num[pos] == '0') break;

            string part = num.substr(pos, i - pos + 1);
            long val = stol(part);

            if (pos == 0) {
                // First number (no operator before it)
                dfs(num, target, i + 1, val, val, part, res);
            } else {
                // Try addition
                dfs(num, target, i + 1, currVal + val, val, path + "+" + part, res);
                // Try subtraction
                dfs(num, target, i + 1, currVal - val, -val, path + "-" + part, res);
                // Try multiplication
                dfs(num, target, i + 1, currVal - lastVal + lastVal * val, lastVal * val, path + "*" + part, res);
            }
        }
    }
};