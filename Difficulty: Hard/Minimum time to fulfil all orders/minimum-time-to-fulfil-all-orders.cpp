class Solution {
  public:
    
    bool canMake(vector<int>& ranks, int n, int time) {
        int donuts = 0;
        
        for (int r : ranks) {
            int k = (sqrt(1 + 8LL * time / r) - 1) / 2;
            donuts += k;
            
            if (donuts >= n)
                return true;
        }
        return false;
    }
    
    int minTime(vector<int>& ranks, int n) {
        int minRank = *min_element(ranks.begin(), ranks.end());
        
        int low = 0;
        int high = minRank * n * (n + 1) / 2;
        int ans = high;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canMake(ranks, n, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
