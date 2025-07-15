class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        int n = a.size();
        if(n==0 || m==0) return 0;
        sort(a.begin(), a.end());
        int x = INT_MAX;
        for(int i = 0; i<=n-m; i++){
            x = min(x, a[i+m-1]-a[i]);
        }
        return x;
    }
};