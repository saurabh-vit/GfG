class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int count = 0, left = 0;
        unordered_map<int, int> freq;
        for(int i = 0; i<n; i++){
            freq[arr[i]]++;
            while(freq.size()>k){
                freq[arr[left]]--;
                if(freq[arr[left]]==0){
                    freq.erase(arr[left]);
                }
                left++;
            }
            count += (i-left+1);
        }
        return count;
    }
};