class Solution {
  public:
    int minCost(int n, int i, int d, int c) {
        // code here
        vector<long long> dp(n + 1, 0);

        // dq stores indices k.
        // Values are dp[k] + 2*k*d in increasing order.
        deque<int> dq;

        dp[0] = 0;

        for (int x = 1; x <= n; x++) {

            // Option 1: insert one character
            dp[x] = dp[x - 1] + i;

            // Add x-1 as a possible starting length for
            // copy-paste followed by deletions.
            int k = x - 1;

            if (k > 0) {
                long long val = dp[k] + 2LL * k * d;

                while (!dq.empty()) {
                    int last = dq.back();
                    long long lastVal =
                        dp[last] + 2LL * last * d;

                    if (lastVal <= val)
                        break;

                    dq.pop_back();
                }

                dq.push_back(k);
            }

            // Valid k must satisfy:
            // ceil(x/2) <= k < x
            int left = (x + 1) / 2;

            while (!dq.empty() && dq.front() < left)
                dq.pop_front();

            // Option 2:
            // k -> 2k using copy, then delete 2k-x characters
            if (!dq.empty()) {
                int best = dq.front();

                long long cost =
                    dp[best]
                    + c
                    + (2LL * best - x) * d;

                dp[x] = min(dp[x], cost);
            }
        }

        return dp[n];
    }
};
