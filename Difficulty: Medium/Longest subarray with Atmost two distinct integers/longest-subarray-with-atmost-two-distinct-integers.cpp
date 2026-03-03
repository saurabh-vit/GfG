class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n = arr.size();
        unordered_map<int, int> freq;
        int j = 0;
        int ans = 0;
        for(int i = 0; i<n; i++){
            freq[arr[i]]++;
            while(freq.size()>2){
                freq[arr[j]]--;
                if(freq[arr[j]]==0){
                    freq.erase(arr[j]);
                }
                j++;
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};