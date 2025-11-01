class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        // code here
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        
        // Build graph
        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }
        
        queue<int> q;
        vector<int> order;
    
        // Start with courses having no prerequisites
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
    
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            order.push_back(curr);
    
            for (int neighbor : adj[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
    
        if ((int)order.size() != n)
            return {};
    
        return order;
    }
};