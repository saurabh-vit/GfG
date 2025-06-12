class Solution {
  public:
    // arr: input array
    // Function to sort the array into a wave-like array.
    void convertToWave(vector<int>& arr) {
        // code here
        int n = arr.size();
        if(n<=1) return;
        int st = 0, end = n-1;
        while(st<end){
            if(arr[st]<=arr[st+1]){
                swap(arr[st], arr[st+1]);
            }
            st = st+2;
        }
    }
};