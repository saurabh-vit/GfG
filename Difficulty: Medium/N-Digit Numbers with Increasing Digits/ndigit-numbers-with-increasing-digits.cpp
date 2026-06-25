class Solution {
public:
    void solve(int n, int lastDigit, long long num, vector<int> &ans) {
        if (n == 0) {
            ans.push_back((int)num);
            return;
        }

        for (int d = lastDigit + 1; d <= 9; d++) {
            solve(n - 1, d, num * 10 + d, ans);
        }
    }

    vector<int> increasingNumbers(int n) {
        vector<int> ans;

        if (n == 1) {
            for (int i = 0; i <= 9; i++)
                ans.push_back(i);
            return ans;
        }

        if (n > 10)
            return ans;

        // First digit cannot be 0
        for (int first = 1; first <= 9; first++) {
            solve(n - 1, first, first, ans);
        }

        return ans;
    }
};