class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(n==1){
            return 0;
        }
        sort(arr.begin(), arr.end());
        int mindiff = arr[n-1] - arr[0];
        int mini = arr[0]+k;
        int maxi = arr[n-1]-k;
        for(int i = 0; i<n; i++){
            int currmax = max(maxi, arr[i]+k);
            int currmin = min(mini, arr[i+1]-k);
            if(currmin<0){
                continue;
            }
            mindiff = min(mindiff, currmax - currmin);
        }
        return mindiff;
    }
};