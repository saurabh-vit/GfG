class Solution {
  public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        int n = men.size();
        
        vector<int> partnerM(n, -1); // man -> woman
        vector<int> partnerW(n, -1); // woman -> man
        vector<int> next(n, 0);      // next woman to propose
        
        // rank[w][m] = preference rank of man m for woman w
        vector<vector<int>> rank(n, vector<int>(n));
        
        // Precompute ranking for women
        for (int w = 0; w < n; w++) {
            for (int i = 0; i < n; i++) {
                rank[w][women[w][i]] = i;
            }
        }
        
        queue<int> freeMen;
        for (int i = 0; i < n; i++) {
            freeMen.push(i);
        }
        
        while (!freeMen.empty()) {
            int m = freeMen.front();
            freeMen.pop();
            
            int w = men[m][next[m]];
            next[m]++;
            
            if (partnerW[w] == -1) {
                // Woman is free
                partnerW[w] = m;
                partnerM[m] = w;
            } else {
                int m1 = partnerW[w];
                
                // Check preference
                if (rank[w][m] < rank[w][m1]) {
                    // She prefers new man
                    partnerW[w] = m;
                    partnerM[m] = w;
                    
                    partnerM[m1] = -1;
                    freeMen.push(m1);
                } else {
                    // She rejects new man
                    freeMen.push(m);
                }
            }
        }
        
        return partnerM;
    }
};