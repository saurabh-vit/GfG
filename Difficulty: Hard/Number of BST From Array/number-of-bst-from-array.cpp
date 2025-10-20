class Solution {
public:
    int catalan(int n) {
        if (n <= 1) return 1;
        int res = 0;
        for (int i = 0; i < n; i++)
            res += catalan(i) * catalan(n - i - 1);
        return res;
    }

    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        vector<int> result;

        for (int i = 0; i < n; i++) {
            int left = 0, right = 0;

            // Count smaller and greater elements
            for (int j = 0; j < n; j++) {
                if (arr[j] < arr[i]) left++;
                else if (arr[j] > arr[i]) right++;
            }

            int count = catalan(left) * catalan(right);
            result.push_back(count);
        }

        return result;
    }
};