class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        // code here
        vector<int> st;

    for (int x : arr) {
        bool destroyed = false;

        while (!st.empty() && st.back() * x < 0) {
            int top = st.back();

            if (abs(top) > abs(x)) {
                destroyed = true;
                break;
            }
            else if (abs(top) < abs(x)) {
                st.pop_back();
            }
            else {
                st.pop_back();
                destroyed = true;
                break;
            }
        }

        if (!destroyed) {
            st.push_back(x);
        }
    }

    return st;
    }
};