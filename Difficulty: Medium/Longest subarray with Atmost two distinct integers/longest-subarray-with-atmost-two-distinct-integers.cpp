class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n = arr.size();
        unordered_map<int, int> count;
        int maxlen = 0, l = 0;
        for(int i = 0; i<n; i++){
            count[arr[i]]++;
            while(count.size()>2){
                count[arr[l]]--;
                if(count[arr[l]]==0){
                    count.erase(arr[l]);
                }
                l++;
            }
            maxlen = max(maxlen, i-l+1);
        }
        return maxlen;
    }
};