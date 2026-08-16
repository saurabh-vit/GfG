class Solution {
  public:
    int minProd(vector<int>& arr) {
        int n = arr.size();

        int negCount = 0;
        int minNeg = INT_MAX;
        int minPos = INT_MAX;
        int zeroCount = 0;

        long long prod = 1;

        for(int i = 0; i < n; i++) {
            int curr = arr[i];

            if(curr < 0) {
                negCount++;
                prod *= curr;
                minNeg = min(minNeg, -curr);
            }
            else if(curr > 0) {
                prod *= curr;
                minPos = min(minPos, curr);
            }
            else {
                zeroCount++;
            }
        }

        // No negative number
        if(negCount == 0) {
            if(zeroCount > 0)
                return 0;

            return minPos;
        }

        // Even number of negatives
        if(negCount % 2 == 0) {
            prod /= -minNeg;
        }

        return prod;
    }
};