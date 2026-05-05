class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        // code here
        int n = arr.size();
        long long result = 0;
    
        // Iterate over each bit position
        for (int bit = 0; bit < 32; bit++) {
            long long count1 = 0;
    
            // Count numbers having this bit set
            for (int num : arr) {
                if (num & (1 << bit)) {
                    count1++;
                }
            }
    
            long long count0 = n - count1;
    
            // Contribution of this bit
            result += (count1 * count0) * (1LL << bit);
        }
    
        return result;
    }
};