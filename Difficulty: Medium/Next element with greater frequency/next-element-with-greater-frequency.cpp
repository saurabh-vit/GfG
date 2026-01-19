class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> ans(n, -1);

        // Step 1: Frequency count
        unordered_map<int, int> freq;
        for (int x : arr) {
            freq[x]++;
        }

        // Step 2: Monotonic stack (stores indices)
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            // Remove elements with <= frequency
            while (!st.empty() && freq[arr[st.top()]] <= freq[arr[i]]) {
                st.pop();
            }

            // If stack not empty, top is answer
            if (!st.empty()) {
                ans[i] = arr[st.top()];
            }

            // Push current index
            st.push(i);
        }

        return ans;
    }
};
