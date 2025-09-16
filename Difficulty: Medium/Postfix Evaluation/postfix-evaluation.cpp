#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evaluatePostfix(vector<string>& arr) {
        stack<int> st;
        for (string &i : arr) {
            if (i == "+" || i == "-" || i == "*" || i == "/" || i == "^") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int result = 0;

                if (i == "+") result = a + b;
                else if (i == "-") result = a - b;
                else if (i == "*") result = a * b;
                else if (i == "/") result = divFloor(a, b);
                else if (i == "^") result = (int)pow(a, b);

                st.push(result);
            } else {
                st.push(stoi(i));
            }
        }
        return st.top();
    }

private:
    // helper for floor division
    int divFloor(int a, int b) {
        int q = a / b;
        int r = a % b;
        if ((r != 0) && ((a < 0) ^ (b < 0))) {
            q--; // adjust toward -∞
        }
        return q;
    }
};