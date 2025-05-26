class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> ans;
        sort(arr.begin(), arr.end());
        int count = 1;
        for(int i = 0; i<n-1; i++){
            if(arr[i]==arr[i+1]){
                ans.push_back(arr[i]);
                break;
            }
        }
        for(int i = 0 ; i<n; i++){
            if(arr[i]==count){
                count++;
            }else if(arr[i] > count){
                ans.push_back(count);
                break;
            }
        }
         if (ans.size() == 1) {
            ans.push_back(n);
        }
        return ans;
    }
};