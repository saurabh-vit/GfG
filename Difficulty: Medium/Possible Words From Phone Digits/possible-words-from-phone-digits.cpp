class Solution {
  public:
    vector<string> keypad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(int idx, vector<int>& arr, string curr, vector<string>& ans) {
        if (idx == arr.size()) {
            ans.push_back(curr);
            return;
        }

        string letters = keypad[arr[idx]];
        if (letters.empty()) {
            // skip digits 0 and 1
            backtrack(idx + 1, arr, curr, ans);
        } else {
            for (char c : letters) {
                backtrack(idx + 1, arr, curr + c, ans);
            }
        }
    }

    vector<string> possibleWords(vector<int>& arr) {
        vector<string> ans;
        if (arr.empty()) return ans;
        backtrack(0, arr, "", ans);
        return ans;
    }
};