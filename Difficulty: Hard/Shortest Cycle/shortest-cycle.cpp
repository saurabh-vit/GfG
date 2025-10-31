class Solution {
  public:
    int shortCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int shortest = INT_MAX;

        for (int src = 0; src < V; src++) {
            vector<int> dist(V, -1);
            vector<int> parent(V, -1);
            queue<int> q;

            dist[src] = 0;
            q.push(src);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (dist[v] == -1) { // Not visited
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        q.push(v);
                    } 
                    else if (parent[u] != v) {
                        // Found a cycle
                        int cycleLength = dist[u] + dist[v] + 1;
                        shortest = min(shortest, cycleLength);
                    }
                }
            }
        }
        return (shortest == INT_MAX) ? -1 : shortest;
    }
};
