class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        // code here
        if (prices.empty()) return 0;

        int n = prices.size();
        int hold = -prices[0];
        int sold = 0;          
        int rest = 0;
    
        for (int i = 1; i < n; ++i) {
            int prev_sold = sold;
            sold = hold + prices[i];
            hold = max(hold, rest - prices[i]);
            rest = max(rest, prev_sold);
        }
        return max(sold, rest);
    }
};