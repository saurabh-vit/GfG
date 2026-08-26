class Solution {
  public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {
        // code here
        vector<long long> dist(V, 0);

        // Relax all edges V times
        for (int i = 0; i < V; i++) {
            bool updated = false;

            for (auto &edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    updated = true;

                    // Update on V-th iteration => negative cycle
                    if (i == V - 1)
                        return true;
                }
            }

            if (!updated)
                break;
        }

        return false;
    }
};