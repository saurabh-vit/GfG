class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        int n = arr.size();
        int st = 0, end = n-1;
        while(st<=end){
            swap(arr[st], arr[end]);
            st++;
            end--;
        }
    }
};