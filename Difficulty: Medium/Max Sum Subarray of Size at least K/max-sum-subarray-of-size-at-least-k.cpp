class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int> maxsum(n);
        maxsum[0] = arr[0];
        for(int i = 0; i<n; i++){
            maxsum[i] = max(arr[i], maxsum[i-1]+arr[i]);
        }
        int windowsum = 0;
        for(int i = 0; i<k; i++){
            windowsum += arr[i];
        }
        int ans = windowsum;
        for(int i = k; i<n; i++){
            windowsum += arr[i] - arr[i-k];
            ans = max(windowsum, ans);
            ans = max(ans, windowsum + maxsum[i-k]);
        }
        return ans;
    }
};