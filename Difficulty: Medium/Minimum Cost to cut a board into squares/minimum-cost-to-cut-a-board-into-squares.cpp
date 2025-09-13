class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        //  code here
        sort(x.begin(), x.end(), greater<int>());
        sort(y.begin(), y.end(), greater<int>());
        int i = 0, j = 0;
        int horizontalSegments = 1, verticalSegments = 1;
        long long totalCost = 0;
        while (i < x.size() && j < y.size()) {
            if (x[i] > y[j]) {
                totalCost += 1LL * x[i] * horizontalSegments;
                verticalSegments++;
                i++;
            } else {
                totalCost += 1LL * y[j] * verticalSegments;
                horizontalSegments++;
                j++;
            }
        }
        while (i < x.size()) {
            totalCost += 1LL * x[i] * horizontalSegments;
            verticalSegments++;
            i++;
        }
        while (j < y.size()) {
            totalCost += 1LL * y[j] * verticalSegments;
            horizontalSegments++;
            j++;
        }
        return (int)totalCost;
    }
};
