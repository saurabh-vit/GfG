class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int left = 0, right = arr.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int width = right - left;
            int height = min(arr[left], arr[right]);
            int area = width * height;
            maxWater = max(maxWater, area);

            // Move the pointer at smaller height
            if (arr[left] < arr[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};