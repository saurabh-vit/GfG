class Solution {
  public:
    int maxKPower(int n, int k) {
        int ans = INT_MAX;
        // Step 1: Prime factorise k
        for(int i = 2; i*i <= k; i++) {
            if(k % i == 0) {
                int count_in_k = 0;
                while(k % i == 0) {
                    count_in_k++;
                    k /= i;
                }
                // Step 2: Count power of i in n!
                int count_in_nfact = 0;
                int temp = n;
                while(temp) {
                    temp /= i;
                    count_in_nfact += temp;
                }
                // Step 3: Calculate possible x for this prime
                ans = min(ans, count_in_nfact / count_in_k);
            }
        }
        // Step 4: If k is prime > sqrt(k)
        if(k > 1) {
            int count_in_nfact = 0;
            int temp = n;
            while(temp) {
                temp /= k;
                count_in_nfact += temp;
            }
            ans = min(ans, count_in_nfact / 1);
        }
        return ans;
    }
};