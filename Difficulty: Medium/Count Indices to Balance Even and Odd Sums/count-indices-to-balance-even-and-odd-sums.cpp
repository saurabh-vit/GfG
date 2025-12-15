class Solution {
  public:
    int cntWays(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<long long> prefEven(n, 0), prefOdd(n, 0);
        for(int i=0; i<n; i++){
            if(i > 0){
                prefEven[i] = prefEven[i-1];
                prefOdd[i] = prefOdd[i-1];
            }
            if(i % 2 == 0) prefEven[i] += arr[i];
            else prefOdd[i] += arr[i];
        }

        long long totalEven = prefEven[n-1];
        long long totalOdd = prefOdd[n-1];
        int count = 0;

        for(int i=0; i<n; i++){
            long long leftEven = (i > 0) ? prefEven[i-1] : 0;
            long long leftOdd  = (i > 0) ? prefOdd[i-1]  : 0;

            long long rightEven = totalOdd - prefOdd[i];      // odd becomes even
            long long rightOdd  = totalEven - prefEven[i];    // even becomes odd

            long long newEven = leftEven + rightEven;
            long long newOdd  = leftOdd + rightOdd;

            if(newEven == newOdd) count++;
        }

        return count;
    }
};