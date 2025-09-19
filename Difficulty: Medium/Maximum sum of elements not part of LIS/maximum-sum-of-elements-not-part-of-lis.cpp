class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> lisLen(n, 1), lisSum(n);
        int total = 0;
        for(int i = 0; i < n; ++i) {
            lisSum[i] = arr[i];
            total += arr[i];
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(arr[j] < arr[i]) {
                    if(lisLen[j] + 1 > lisLen[i]) {
                        lisLen[i] = lisLen[j] + 1;
                        lisSum[i] = lisSum[j] + arr[i];
                    } else if(lisLen[j] + 1 == lisLen[i]) {
                        lisSum[i] = min(lisSum[i], lisSum[j] + arr[i]);
                    }
                }
            }
        }

        int maxLen = 0, minSum = INT_MAX;
        for(int i = 0; i < n; ++i) {
            if(lisLen[i] > maxLen) {
                maxLen = lisLen[i];
                minSum = lisSum[i];
            } else if(lisLen[i] == maxLen) {
                minSum = min(minSum, lisSum[i]);
            }
        }

        return total - minSum;
    }
};
