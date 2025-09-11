class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int n = arr.size();
        if (n <= 1) return 0;           // Already at last index
        if (arr[0] == 0) return -1;
        int maxReach = arr[0];  // The farthest we can go initially
        int steps = arr[0];     // Steps we can still take
        int jumps = 1;
        for (int i = 1; i < n; i++) {
            if (i == n - 1) return jumps;
            maxReach = max(maxReach, i + arr[i]);
            steps--;
            if (steps == 0) {
                jumps++;
                if (i >= maxReach) return -1;
                steps = maxReach - i;
            }
        }
        return -1;
    }
};
