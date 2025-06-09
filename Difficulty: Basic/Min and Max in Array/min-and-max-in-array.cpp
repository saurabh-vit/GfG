// User function Template for C++
class Solution {
  public:
    pair<int, int> getMinMax(vector<int> arr) {
        // code here
        int mini = arr[0];
        int maxi = arr[0];
        for(int i = 0; i<arr.size(); i++){
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);
        }
        return {mini, maxi};
    }
};