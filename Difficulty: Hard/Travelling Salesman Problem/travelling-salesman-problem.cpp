class Solution {
  public:
    int tsp(vector<vector<int>>& cost) {
        // code here
        int n = (int)cost.size();
        if (n == 0) return 0;
        if (n == 1) return 0;
    
        const int INF = 1e9;
        int N = 1 << n;
        vector<vector<int>> dp(N, vector<int>(n, INF));
    
        // Start at city 0; only city 0 visited
        dp[1][0] = 0; // mask bit i means city i visited
    
        for (int mask = 1; mask < N; ++mask) {
            if (!(mask & 1)) continue; // must include start city 0
            for (int u = 0; u < n; ++u) {
                if (!(mask & (1 << u))) continue;
                int cur = dp[mask][u];
                if (cur >= INF) continue;
                // Try to go to an unvisited city v
                for (int v = 0; v < n; ++v) {
                    if (mask & (1 << v)) continue;
                    int nextMask = mask | (1 << v);
                    dp[nextMask][v] = min(dp[nextMask][v], cur + cost[u][v]);
                }
            }
        }
    
        int full = (1 << n) - 1;
        int ans = INF;
        // End at any city u, then return to 0
        for (int u = 1; u < n; ++u) {
            if (dp[full][u] >= INF) continue;
            ans = min(ans, dp[full][u] + cost[u][0]);
        }
        return ans == INF ? -1 : ans;
    }
};