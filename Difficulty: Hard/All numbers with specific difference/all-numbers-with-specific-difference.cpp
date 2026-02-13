class Solution {
  public:
    
    long long digitSum(long long x) {
        long long sum = 0;
        while (x > 0) {
            sum += x % 10;   // get last digit
            x /= 10;        // remove last digit
        }
        return sum;
    }
    
    int getCount(int n, int d) {
        long long low = 1, high = n;
        long long firstValid = -1;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (mid - digitSum(mid) >= d) {
                firstValid = mid;      // possible answer
                high = mid - 1;        // try smaller number
            } else {
                low = mid + 1;
            }
        }
        
        if (firstValid == -1) 
            return 0;
            
        return n - firstValid + 1;
    }
};
