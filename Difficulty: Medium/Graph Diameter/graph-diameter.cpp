class Solution {
  public:
    int diameter(int V, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        // Helper BFS function to find the farthest node and its distance
        auto bfs_far = [&](int src) {
            vector<int> dist(V, -1);
            queue<int> q;
            q.push(src);
            dist[src] = 0;
            
            int farNode = src, maxDist = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                
                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                        if (dist[v] > maxDist) {
                            maxDist = dist[v];
                            farNode = v;
                        }
                    }
                }
            }
            return pair<int,int>(farNode, maxDist);
        };
        
        // Step 1: BFS from any node (0) to find farthest node u
        auto p = bfs_far(0);
        int u = p.first;
        
        // Step 2: BFS from u to find the farthest node distance -> diameter
        auto q = bfs_far(u);
        return q.second;
    }
};