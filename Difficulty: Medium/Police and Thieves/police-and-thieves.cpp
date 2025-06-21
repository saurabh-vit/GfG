class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int n = arr.size();
        int count = 0;
        vector<int> police;
        vector<int> thief;
        for(int i = 0; i<n; i++){
            if(arr[i]=='P'){
                police.push_back(i);
            }else{
                thief.push_back(i);
            }
        }
        int i = 0, j = 0;
        while(i<police.size() && j<thief.size()){
            if(abs(police[i]-thief[j])<=k){
                count++;
                i++;
                j++;
            }else if(thief[j]<police[i]){
                j++;
            }else{
                i++;
            }
        }
        return count;
    }
};