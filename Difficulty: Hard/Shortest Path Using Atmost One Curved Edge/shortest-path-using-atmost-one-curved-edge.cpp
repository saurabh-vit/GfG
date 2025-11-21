class Solution {
  public:
    int shortestPath(int V, int a, int b, vector<vector<int>> &edges) {
        
        using ll = long long;
        const ll INF = 1e18;
        
        // adjacency list: node -> {neighbor, {weight, curved?}}
        vector<vector<pair<int, pair<int,int>>>> adj(V);

        for (auto &e : edges) {
            int x = e[0], y = e[1], w1 = e[2], w2 = e[3];

            // straight edges (curved = 0)
            adj[x].push_back({y, {w1, 0}});
            adj[y].push_back({x, {w1, 0}});

            // curved edges (curved = 1)
            adj[x].push_back({y, {w2, 1}});
            adj[y].push_back({x, {w2, 1}});
        }

        // dist[node][curvedUsed]  → 0 or 1
        vector<vector<ll>> dist(V, vector<ll>(2, INF));

        // Min-heap for Dijkstra: {distance, {node, curvedUsed}}
        priority_queue<
            pair<ll, pair<int,int>>,
            vector<pair<ll, pair<int,int>>>,
            greater<pair<ll, pair<int,int>>>
        > pq;

        dist[a][0] = 0;
        pq.push({0, {a, 0}});

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            ll d = top.first;
            int node = top.second.first;
            int used = top.second.second;

            if (d > dist[node][used]) continue;

            for (auto &p : adj[node]) {
                int nxt = p.first;
                int w = p.second.first;
                int curved = p.second.second;

                int newUsed = used + curved;
                if (newUsed > 1) continue; // cannot use more than 1 curved

                if (dist[nxt][newUsed] > d + w) {
                    dist[nxt][newUsed] = d + w;
                    pq.push({dist[nxt][newUsed], {nxt, newUsed}});
                }
            }
        }

        long long ans = min(dist[b][0], dist[b][1]);
        return ans == INF ? -1 : ans;
    }
};
