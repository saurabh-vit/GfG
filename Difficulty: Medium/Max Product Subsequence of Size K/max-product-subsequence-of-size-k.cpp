class Solution {
public:
    long long maxProduct(vector<int>& arr, int k) {
        int n = arr.size();

        // dpMax[i][j] = maximum product by choosing j elements
        // from first i elements
        //
        // dpMin[i][j] = minimum product by choosing j elements
        vector<vector<long long>> dpMax(n + 1,
                                        vector<long long>(k + 1, LLONG_MIN));

        vector<vector<long long>> dpMin(n + 1,
                                        vector<long long>(k + 1, LLONG_MAX));

        // Choosing 0 elements gives product 1
        for (int i = 0; i <= n; i++) {
            dpMax[i][0] = 1;
            dpMin[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, k); j++) {

                // Option 1: Don't take arr[i-1]
                dpMax[i][j] = dpMax[i - 1][j];
                dpMin[i][j] = dpMin[i - 1][j];

                // Option 2: Take arr[i-1]
                if (dpMax[i - 1][j - 1] != LLONG_MIN) {
                    long long x = arr[i - 1];

                    long long a = dpMax[i - 1][j - 1] * x;
                    long long b = dpMin[i - 1][j - 1] * x;

                    dpMax[i][j] = max({dpMax[i][j], a, b});
                    dpMin[i][j] = min({dpMin[i][j], a, b});
                }
            }
        }

        return dpMax[n][k];
    }
};