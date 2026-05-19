class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        if(start == end)
            return 0;
        
        vector<int> dist(1000, 1e9);
        queue<int> q;
        
        q.push(start);
        dist[start] = 0;
        
        while(!q.empty()) {
            
            int curr = q.front();
            q.pop();
            
            for(int num : arr) {
                
                int next = (curr * num) % 1000;
                
                // If found shorter path
                if(dist[curr] + 1 < dist[next]) {
                    
                    dist[next] = dist[curr] + 1;
                    
                    // If reached target
                    if(next == end)
                        return dist[next];
                    
                    q.push(next);
                }
            }
        }
        
        return -1;
    }
};