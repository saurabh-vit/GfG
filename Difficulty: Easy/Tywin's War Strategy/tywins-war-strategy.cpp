class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int luckyCount = 0;
        vector<int> adds;
    
        for (int soldiers : arr) {
            if (soldiers % k == 0) {
                luckyCount++;
            } else {
                adds.push_back(k - (soldiers % k));
            }
        }
    
        int required = (n + 1) / 2; // ceil(n / 2)
        if (luckyCount >= required) return 0;
    
        int need = required - luckyCount;
        sort(adds.begin(), adds.end());
    
        long long total = 0;
        for (int i = 0; i < need; i++) {
            total += adds[i];
        }
        return total;
    }
};