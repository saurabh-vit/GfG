class Solution {
  public:
    int josephus(int n, int k) {
        // code here
        int ans = 0;   // J(1, k) = 0 (0-based index)
    
    for (int i = 2; i <= n; i++) {
        ans = (ans + k) % i;
    }
    
    return ans + 1;
    }
};