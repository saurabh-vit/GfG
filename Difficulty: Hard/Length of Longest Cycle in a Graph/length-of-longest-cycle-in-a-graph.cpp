class Solution {
public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj(V, -1);
        
        // Build graph
        for (auto &e : edges) {
            adj[e[0]] = e[1];
        }
        
        vector<int> visited(V, 0);
        int maxCycle = -1;
        
        for (int i = 0; i < V; i++) {
            if (visited[i]) continue;
            
            unordered_map<int, int> dist;
            int node = i;
            int step = 0;
            
            while (node != -1) {
                if (visited[node]) break;
                
                visited[node] = 1;
                dist[node] = step++;
                
                int next = adj[node];
                
                // Cycle detected
                if (next != -1 && dist.find(next) != dist.end()) {
                    int cycleLength = step - dist[next];
                    maxCycle = max(maxCycle, cycleLength);
                    break;
                }
                
                node = next;
            }
        }
        
        return maxCycle;
    }
};