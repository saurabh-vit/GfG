class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        sort(arr.begin(), arr.end());

        vector<int> result;
        for (auto &q : queries) {
            int a = q[0];
            int b = q[1];

            int left = lower_bound(arr.begin(), arr.end(), a) - arr.begin();

            int right = upper_bound(arr.begin(), arr.end(), b) - arr.begin();

            result.push_back(right - left);
        }

        return result;
    }
};