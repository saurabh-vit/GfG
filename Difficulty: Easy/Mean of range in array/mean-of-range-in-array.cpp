class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int n = arr.size();
        vector<int> prefix(n);
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }
        vector<int> result;
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];
            int sum;
            if (l == 0)
                sum = prefix[r];
            else
                sum = prefix[r] - prefix[l - 1];
            int length = r - l + 1;
            int mean = sum / length;
            result.push_back(mean);
        }
        return result;
    }
};