class Solution {
  public:
    bool canAchieve(vector<int> &arr, int k, int w, int target) {
        int n = arr.size();
        vector<int> diff(n + 1, 0); // difference array for range updates
        int daysUsed = 0, currAdd = 0;

        for (int i = 0; i < n; i++) {
            currAdd += diff[i];

            int height = arr[i] + currAdd;
            if (height < target) {
                int need = target - height;
                daysUsed += need;
                if (daysUsed > k) return false;

                currAdd += need;
                if (i + w < n)
                    diff[i + w] -= need;
            }
        }

        return true;
    }

    int maxMinHeight(vector<int> &arr, int k, int w) {
        int low = *min_element(arr.begin(), arr.end());
        int high = low + k; // maximum possible

        int ans = low;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (canAchieve(arr, k, w, mid)) {
                ans = mid; // mid is possible, try for higher
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};