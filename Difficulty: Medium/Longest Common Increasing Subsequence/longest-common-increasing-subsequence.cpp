class Solution {
  public:
    int LCIS(vector<int> &a, vector<int> &b) {
        // code here
        int n = a.size(), m = b.size();
        vector<int> lcis(m, 0);
    
        for(int i = 0; i < n; i++) {
            int current_max = 0;
    
            for(int j = 0; j < m; j++) {
                if(a[i] == b[j]) {
                    lcis[j] = current_max + 1;
                }
                else if(b[j] < a[i]) {
                    current_max = max(current_max, lcis[j]);
                }
            }
        }
    
        return *max_element(lcis.begin(), lcis.end());
    }
};