class Solution {
  public:

    pair<int, int> bfs(int start, vector<vector<int>> &adj) {
        int n = adj.size();

        vector<int> dist(n + 1, -1);
        queue<int> q;

        q.push(start);
        dist[start] = 0;

        int farthest = start;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u - 1]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);

                    if (dist[v] > dist[farthest]) {
                        farthest = v;
                    }
                }
            }
        }

        return {farthest, dist[farthest]};
    }

    int partyHouse(vector<vector<int>> &adj) {
        // Step 1: Find one endpoint of the diameter
        auto first = bfs(1, adj);
        int endpoint = first.first;

        // Step 2: Find the diameter
        auto second = bfs(endpoint, adj);
        int diameter = second.second;

        // Minimum maximum distance = ceil(diameter / 2)
        return (diameter + 1) / 2;
    }
};