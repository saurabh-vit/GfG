class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list and indegree array
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        
        // Step 2: Perform Topological Sort (Kahn’s Algorithm)
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        
        vector<int> topo;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }
        
        // Step 3: Build adjacency matrix to check if edge already exists
        vector<vector<bool>> hasEdge(V, vector<bool>(V, false));
        for (auto &e : edges)
            hasEdge[e[0]][e[1]] = true;
        
        // Step 4: Count all pairs (u, v) where u comes before v in topo order
        int count = 0;
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                int u = topo[i];
                int v = topo[j];
                if (!hasEdge[u][v])  // if edge doesn’t already exist
                    count++;
            }
        }
        
        return count;
    }
};
