class Solution {
  public:
    string removeKdig(string &s, int k) {
        stack<char> st;

        // Step 1: Greedy removal using stack
        for (char c : s) {
            while (!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }

        // Step 2: Remove remaining digits from end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Step 3: Build result
        string ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        // Step 4: Remove leading zeros
        int i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }
        ans = ans.substr(i);

        // Step 5: Edge case
        return ans.empty() ? "0" : ans;
    }
};
