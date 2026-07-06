class Solution {
  public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        // Code here
        int i = 0, j = 0;
        int n = a.size(), m = b.size();
        int s1 = 0, s2 = 0, ans = 0;
        while(i < n && j < m){
            if(a[i] < b[j]){
                s1 += a[i];
                i++;
            }
            else if(a[i] > b[j]){
                s2 += b[j];
                j++;
            }
            else{
                ans += max(s1, s2) + a[i];
                s1 = s2 = 0;
                i++;
                j++;
            }
        }
        
        while(i < n)
            s1 += a[i++];
        
        while(j < m)
            s2 += b[j++];
        
        ans += max(s1, s2);
        
        return ans;
    }
};