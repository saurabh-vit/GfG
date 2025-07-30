class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int count = 0, sum = 0;
        unordered_map<int, int> presum;
        presum[0] = 1;
        for(int i =0; i<n; i++){
            sum += arr[i];
            if(presum.find(sum-k) != presum.end()){
                count += presum[sum - k];
            }
            presum[sum]++;
        }
        return count;
    }
};