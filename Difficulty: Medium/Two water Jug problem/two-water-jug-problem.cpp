class Solution {
  public:
    // Helper function to compute gcd
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    // Count steps when starting with 'fromCap' jug
    int pourSteps(int fromCap, int toCap, int d) {
        int from = fromCap; // fill from jug
        int to = 0;         // to jug empty
        int step = 1;       // first operation: fill from jug

        while (from != d && to != d) {
            int temp = min(from, toCap - to); // pour water
            to += temp;
            from -= temp;
            step++;

            if (from == d || to == d) break;

            if (from == 0) { // refill from jug
                from = fromCap;
                step++;
            }
            if (to == toCap) { // empty to jug
                to = 0;
                step++;
            }
        }
        return step;
    }

    int minSteps(int m, int n, int d) {
        // Feasibility check
        if (d > max(m, n)) return -1;
        if (d % gcd(m, n) != 0) return -1;

        // Try both directions and return minimum
        return min(pourSteps(m, n, d), pourSteps(n, m, d));
    }
};
