class Solution {
  public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        // code here
        int n = a.size();
        int m = b.size();

        // Store the index of each element in b
        unordered_map<int, int> pos;
        for (int i = 0; i < m; i++) {
            pos[b[i]] = i;
        }

        // Convert a into indices of elements present in b
        vector<int> indices;
        for (int num : a) {
            if (pos.find(num) != pos.end()) {
                indices.push_back(pos[num]);
            }
        }

        // Find LIS on indices
        vector<int> lis;
        for (int idx : indices) {
            auto it = lower_bound(lis.begin(), lis.end(), idx);

            if (it == lis.end())
                lis.push_back(idx);
            else
                *it = idx;
        }

        int lcs = lis.size();

        // Minimum operations = deletions + insertions
        return (n - lcs) + (m - lcs);
    }
};