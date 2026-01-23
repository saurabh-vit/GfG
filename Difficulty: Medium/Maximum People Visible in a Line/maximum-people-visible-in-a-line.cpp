class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        int n = arr.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> st;

        // Nearest >= on the left
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            if (!st.empty()) left[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Nearest >= on the right
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            if (!st.empty()) right[i] = st.top();
            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int visible = 1; // self
            visible += (i - left[i] - 1);
            visible += (right[i] - i - 1);
            ans = max(ans, visible);
        }

        return ans;
    }
};