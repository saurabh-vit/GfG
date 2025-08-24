class Solution {
  public:
    bool canMake(vector<int>& arr, int k, int m, int day) {
        int bouquets = 0, flowers = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0; // reset after making one bouquet
                }
            } else {
                flowers = 0; // reset streak
            }
            if (bouquets >= m) return true;
        }
        return false;
    }
    
    int minDaysBloom(vector<int>& arr, int k, int m) {
        long long need = 1LL * m * k;
        if (need > arr.size()) return -1;  // not enough flowers

        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canMake(arr, k, m, mid)) {
                ans = mid;
                high = mid - 1; // try smaller
            } else {
                low = mid + 1; // need more days
            }
        }
        return ans;
    }
};