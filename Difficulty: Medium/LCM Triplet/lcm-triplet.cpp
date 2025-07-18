class Solution {
  public:
    int lcmTriplets(int n) {
        // code here
        if (n <= 2)
            return n;
        long long ans;
        if (n % 2 != 0) {
            ans = n * (n - 1) * (n - 2);
        } else {
            if (n % 3 != 0)
                ans = n * (n - 1) * (n - 3);
            else
                ans = (n - 1) * (n - 2) * (n - 3);
            long long alt = (n - 1) * (n - 2) * (n - 3);
            if (n > 3)
                ans = std::max(ans, alt);
        }
        return ans;
    }
};