class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        vector<int> st;
        for(int x : arr) {
            if(!st.empty() && 
               ((st.back() >= 0 && x < 0) || (st.back() < 0 && x >= 0))) {
                st.pop_back();
            }
            else {
                st.push_back(x);
            }
        }
        return st;
    }
};