class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        // code here
        vector<long long> freq(k, 0);
        long long ans = 0;
        for (int x : arr) {
            int rem = x % k;
            if (rem == 0)
                ans += freq[0];
            else
                ans += freq[k - rem];
            freq[rem]++;
        }
        return ans;
    }
};