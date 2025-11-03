#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<vector<int>> revGraph(V);
        vector<int> outdegree(V, 0);
        
        // Step 1: Build reverse graph & count outdegrees
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            revGraph[v].push_back(u);
            outdegree[u]++;
        }
        
        // Step 2: Queue for terminal nodes (outdegree = 0)
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (outdegree[i] == 0)
                q.push(i);
        }
        
        // Step 3: Topological sort on reversed graph
        vector<int> safe;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe.push_back(node);
            
            for (int neighbor : revGraph[node]) {
                outdegree[neighbor]--;
                if (outdegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        
        // Step 4: Sort safe nodes before returning
        sort(safe.begin(), safe.end());
        return safe;
    }
};
