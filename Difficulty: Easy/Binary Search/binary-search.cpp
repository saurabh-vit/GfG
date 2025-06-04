class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int st = 0, end = n-1, ans = -1;
        while(st<=end){
            int mid = st+(end-st)/2;
            if(arr[mid]==k){
                ans = mid;
                end = mid-1;
            }else if(arr[mid]>k){
                end = mid-1;
            }else{
                st = mid+1;
            }
        }
        return ans;
    }
};