class Solution {
  public:
    int solve(int n, string s) {
        // code here
        int available = n;
        int rejected = 0;

        vector<bool> usingComputer(26, false);
        vector<bool> seen(26, false);

        for (char c : s) {
            int idx = c - 'A';

            // First occurrence = arrival
            if (!seen[idx]) {
                seen[idx] = true;

                if (available > 0) {
                    available--;
                    usingComputer[idx] = true;
                } else {
                    rejected++;
                }
            }
            // Second occurrence = departure
            else {
                if (usingComputer[idx]) {
                    available++;
                    usingComputer[idx] = false;
                }
            }
        }

        return rejected;
    }
};
