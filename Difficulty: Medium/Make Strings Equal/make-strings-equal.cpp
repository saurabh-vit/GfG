class Solution {
  public:
    int minCost(string &s, string &t, vector<vector<char>> &transform,
                vector<int> &cost) {

        int n = s.size();
        const long long INF = 1e15;

        // Distance matrix
        long long dist[26][26];

        // Initialize distances
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                dist[i][j] = (i == j ? 0 : INF);
            }
        }

        // Add given edges
        for (int i = 0; i < transform.size(); i++) {
            int u = transform[i][0] - 'a';
            int v = transform[i][1] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // Floyd–Warshall on 26 letters
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        long long ans = 0;

        // For each position, find minimum cost to equalize characters
        for (int i = 0; i < n; i++) {
            int a = s[i] - 'a';
            int b = t[i] - 'a';

            long long best = INF;

            for (int c = 0; c < 26; c++) {
                if (dist[a][c] < INF && dist[b][c] < INF) {
                    best = min(best, dist[a][c] + dist[b][c]);
                }
            }

            if (best == INF) return -1; // impossible

            ans += best;
        }

        return ans;
    }
};