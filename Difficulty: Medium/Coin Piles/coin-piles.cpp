class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }
        long long result = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            int minPile = arr[i];
            int maxAllowed = minPile + k;
            int j = upper_bound(arr.begin(), arr.end(), maxAllowed) - arr.begin();
            long long coinsToRemoveLeft = prefix[i];
            long long coinsToRemoveRight = prefix[n] - prefix[j] - 1LL * (n - j) * maxAllowed;
            result = min(result, coinsToRemoveLeft + coinsToRemoveRight);
        }
        return (int)result;
    }
};
