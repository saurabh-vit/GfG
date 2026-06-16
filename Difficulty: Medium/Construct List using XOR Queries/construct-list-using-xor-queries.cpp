class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {
        vector<int> arr;
        int xr = 0;

        arr.push_back(0);

        for (auto &query : queries) {
            int type = query[0];
            int x = query[1];

            if (type == 0) {
                arr.push_back(x ^ xr);
            } else {
                xr ^= x;
            }
        }

        for (auto &val : arr) {
            val ^= xr;
        }

        sort(arr.begin(), arr.end());

        return arr;
    }
};