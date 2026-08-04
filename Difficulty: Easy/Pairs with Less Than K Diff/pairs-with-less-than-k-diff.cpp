class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int count = 0;
        int i = 0, j = 1;
        while(i<n){
            while(j<n && arr[j] - arr[i] < k){
                j++;
            }
            count += (j-i-1);
            i++;
            if(j==i){
                j++;
            }
        }
        return count;
    }
};