class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        int n = prices.size();
        sort(prices.begin(), prices.end());
        int min_cost = 0;
        int start = 0, end = n - 1;
        while (start <= end) {
            min_cost += prices[start];
            start++;
            end -= k;
        }
        int max_cost = 0;
        start = n - 1;
        end = 0;
        while (end <= start) {
            max_cost += prices[start];
            start--;
            end += k; 
        }
        
        return {min_cost, max_cost};
    }
};