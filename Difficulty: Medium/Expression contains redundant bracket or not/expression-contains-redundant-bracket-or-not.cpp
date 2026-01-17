class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        stack<char> st;
        for (char ch : s) {
            if (ch == ')') {
                bool hasOperator = false;
                while (!st.empty() && st.top() != '(') {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                        hasOperator = true;
                    }
                    st.pop();
                }
                if (!st.empty()) st.pop();
                if (!hasOperator) return true;
            } 
            else {
                st.push(ch);
            }
        }
        return false;
    }
};
