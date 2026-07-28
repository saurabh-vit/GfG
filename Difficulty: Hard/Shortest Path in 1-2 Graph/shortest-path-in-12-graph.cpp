class Solution {
  public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {
        vector<vector<pair<int,int>>> adj(V);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int d = it.first;
            int u = it.second;

            if (d > dist[u]) continue;

            for (auto &x : adj[u]) {
                int v = x.first;
                int w = x.second;

                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[dest] == INT_MAX ? -1 : dist[dest];
    }
};