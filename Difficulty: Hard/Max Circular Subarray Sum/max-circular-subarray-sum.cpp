class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        int curr = arr[0], maxi = arr[0];
        for(int i=1; i<n; i++){
            curr = max(arr[i], curr + arr[i]);
            maxi = max(maxi, curr);
        }
        int sum = 0;
        int curr_min = arr[0], min_kadane = arr[0];
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(i != 0) {
                curr_min = min(arr[i], curr_min + arr[i]);
                min_kadane = min(min_kadane, curr_min);
            }
        }
        if(maxi < 0) {
            return maxi;
        }
        return max(maxi, sum - min_kadane);
    }
};