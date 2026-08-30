class Solution {
  public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        // code here
        int n = l.size();

        // Store {rank, original index}
        vector<pair<int, int>> queries;
        for (int i = 0; i < rank.size(); i++) {
            queries.push_back({rank[i], i});
        }

        sort(queries.begin(), queries.end());

        vector<int> ans(rank.size());

        long long count = 0;
        int j = 0;

        for (auto [k, idx] : queries) {

            // Move to the interval containing rank k
            while (j < n && count + (long long)(r[j] - l[j] + 1) < k) {
                count += (long long)(r[j] - l[j] + 1);
                j++;
            }

            // k is inside interval [l[j], r[j]]
            ans[idx] = l[j] + (k - count - 1);
        }

        return ans;
    }
};