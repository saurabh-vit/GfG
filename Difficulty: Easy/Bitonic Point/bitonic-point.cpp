// User function template for C++
class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        // code here
        int n = arr.size();
        for(int i = 0; i<n-1; i++){
            if(arr[i]<arr[i+1]){
                continue;
            }else{
                return arr[i];
            }
        }
        return arr[n-1];
    }
};