class Solution {
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int low = *min_element(heights.begin(), heights.end());
        int high = *max_element(heights.begin(), heights.end());
    
        // Step 2: Define a helper function to calculate cost for a given target height
        auto getCost = [&](int target) {
            long long total = 0;
            for (int i = 0; i < heights.size(); ++i) {
                total += 1LL * abs(heights[i] - target) * cost[i];
            }
            return total;
        };
        long long result = LLONG_MAX;
        while (low <= high) {
            int mid = (low + high) / 2;
            long long costMid = getCost(mid);
            long long costLeft = mid > low ? getCost(mid - 1) : LLONG_MAX;
            long long costRight = mid < high ? getCost(mid + 1) : LLONG_MAX;
            result = min({result, costMid, costLeft, costRight});
            if (costLeft < costMid) {
                high = mid - 1;
            } else if (costRight < costMid) {
                low = mid + 1;
            } else {
                break;  // Found minimum
            }
        }
        return (int)result;
    }
};
