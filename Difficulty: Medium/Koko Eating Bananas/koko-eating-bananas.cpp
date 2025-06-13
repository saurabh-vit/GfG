class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int left = 1, right = *max_element(arr.begin(), arr.end());
        auto canFinish = [&](int speed) {
            int hours = 0;
            for (int bananas : arr) {
                hours += (bananas + speed - 1) / speed;  // ceil(bananas / speed)
            }
            return hours <= k;
        };
        while (left < right) {
            int mid = (left + right) / 2;
            if (canFinish(mid)) {
                right = mid;  // try smaller speed
            } else {
                left = mid + 1;  // need more speed
            }
        }
        return left;
    }
};