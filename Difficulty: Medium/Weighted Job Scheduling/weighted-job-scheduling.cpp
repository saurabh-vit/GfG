class Solution {
  public:
    int maxProfit(vector<vector<int>> &jobs) {
        // code here
        sort(jobs.begin(), jobs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        int n = jobs.size();
        vector<int> dp(n);
        dp[0] = jobs[0][2];

        for (int i = 1; i < n; i++) {
            int incl = jobs[i][2]; // profit including this job

            // Find the last non-overlapping job using binary search
            int l = 0, r = i - 1, lastNonOverlap = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (jobs[mid][1] <= jobs[i][0]) {
                    lastNonOverlap = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if (lastNonOverlap != -1)
                incl += dp[lastNonOverlap];

            dp[i] = max(incl, dp[i - 1]);
        }

        return dp[n - 1];
    }
};
