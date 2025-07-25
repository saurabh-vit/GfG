class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        int curr_max = arr[0], max_kadane = arr[0];
        for(int i=1; i<n; i++){
            curr_max = max(arr[i], curr_max + arr[i]);
            max_kadane = max(max_kadane, curr_max);
        }
        int total_sum = 0;
        int curr_min = arr[0], min_kadane = arr[0];
        for(int i=0; i<n; i++){
            total_sum += arr[i];
            if(i != 0) {
                curr_min = min(arr[i], curr_min + arr[i]);
                min_kadane = min(min_kadane, curr_min);
            }
        }
        if(max_kadane < 0) {
            return max_kadane;
        }
        return max(max_kadane, total_sum - min_kadane);
    }
};