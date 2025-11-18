class Solution {
public:
    int countPaths(int V, vector<vector<int>>& edges) {
        const long long INF = 1e18;
        vector<vector<pair<int,int>>> adj(V);

        for (auto &e : edges) {
            int u = e[0], v = e[1], t = e[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        vector<long long> dist(V, INF);
        vector<long long> ways(V, 0);

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (auto &p : adj[u]) {
                int v = p.first;
                int wt = p.second;

                long long newDist = d + wt;

                // Case A: Found shorter path
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }
                // Case B: Found another shortest path
                else if (newDist == dist[v]) {
                    ways[v] += ways[u];
                }
            }
        }

        return ways[V - 1];
    }
};