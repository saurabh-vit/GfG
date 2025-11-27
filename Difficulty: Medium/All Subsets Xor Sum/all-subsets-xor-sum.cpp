class Solution {
  public:
    int subsetXORSum(vector<int>& arr) {
        // code here
        int sum = 0;
        int n = arr.size();
        for(int i : arr){
            sum |= i;
        }
        return sum * (1 << (n - 1));
    }
};