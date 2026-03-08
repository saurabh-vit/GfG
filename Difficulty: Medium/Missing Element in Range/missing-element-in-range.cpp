class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // code here
        sort(arr.begin(), arr.end());
        vector<int> ans;
        int j = 0;
        for(int i = low; i<=high; i++){
            while(j<arr.size() && arr[j]<i){
                j++;
            }
            if(j>=arr.size() || arr[j] != i){
                ans.push_back(i);
            } 
        }
        return ans;
    }
};