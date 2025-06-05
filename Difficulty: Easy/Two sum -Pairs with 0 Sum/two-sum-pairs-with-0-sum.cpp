// User function template for C++

class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        // code here
        int n = arr.size();
        int st = 0, end = n-1;
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        while(st<end){
            int x = arr[st]+arr[end];
            if(x==0){
                ans.push_back({arr[st], arr[end]});
                int leftVal = arr[st], rightVal = arr[end];
                while (st < end && arr[st] == leftVal) st++;
                while (st < end && arr[end] == rightVal) end--;
            }else if(x>0){
                end--;
            }else{
                st++;
            }
        }
        return ans;
    }
};