class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        // code here
        unordered_set<int> st(arr.begin(), arr.end());
        int cnt = 0;
        for (int x : arr) {
            if (st.find(x - 1) == st.end())
                cnt++;
        }
        return cnt;
    }
};
