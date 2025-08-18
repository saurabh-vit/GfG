class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        int n = citations.size();
        int h = 0;
        sort(citations.begin(), citations.end());
        for(int i = 0; i<n; i++){
            int curr = n-i;
            if(citations[i] >= curr){
                h = curr;
                break;
            }
        }
        return h;
    }
};