class Solution {
  public:
    string removeBrackets(string s) {
        string ans = "";
    vector<int> v(s.size());
    stack<int> st;
    unordered_set<int> st1, st2, st3;

    // First pass: assign each character with the correct parentheses scope
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
            v[i] = st.top();
        }
        else if (s[i] == ')') {
            v[i] = st.top();
            st.pop();
        }
        else if ((s[i] == '+' || s[i] == '-') && st.size() > 0) {
            v[i] = st.top();
            st1.insert(st.top());
        }
        else if ((s[i] == '*' || s[i] == '/') && st.size() > 0) {
            v[i] = st.top();
            st3.insert(st.top());
        }
        else if (st.size() > 0) {
            v[i] = st.top();
        }
    }

    // Second pass: identify redundant parentheses
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '*' && s[i] != '/' && s[i] != '-') continue;
        int j = i + 1;
        
        // For subtraction, skip over nested parentheses
        if (s[i] == '-') {
            while (j < s.size() && s[j] == '(') {
                if (st1.find(v[j]) != st1.end()) 
                    st2.insert(j);
                j++;
            }
            continue;
        }
        
        // For multiplication or division, handle nested parentheses
        j = i + 1;
        while (j < s.size() && s[j] == '(') {
            if (st1.find(v[j]) != st1.end())
                st2.insert(j);
            j++;
        }
        
        if (s[i] == '/') {
            j = i + 1;
            while (j < s.size() && s[j] == '(') {
                if (st3.find(v[j]) != st3.end())
                    st2.insert(j);
                j++;
            }
        }
        
        j = i - 1;
        while (j >= 0 && s[j] == ')') {
            if (st1.find(v[j]) != st1.end())
                st2.insert(j);
            j--;
        }
    }

    // Construct the final string after removing redundant parentheses
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ')' && s[i] != '(') {
            ans += s[i];
        }
        else {
            if (st2.find(v[i]) != st2.end()) {
                ans += s[i];
            }
        }
    }
    
    return ans;
    }
};
