class Solution {
  public:
    int maxSum(string &s) {
        int n = s.size();

        // Step 1: Manacher for odd palindromes
        vector<int> d1(n);
        int l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            int k = 1;
            if (i <= r) k = min(d1[l + r - i], r - i + 1);
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) k++;
            d1[i] = k;
            if (i + k - 1 > r) {
                l = i - k + 1;
                r = i + k - 1;
            }
        }

        vector<int> bestLeft(n, 0), bestRight(n, 0);

        // Step 2: Instead of looping rad = 1..R, just update bestLeft and bestRight for the farthest points
        for (int i = 0; i < n; i++) {
            int R = d1[i];
            int start = i - R + 1;
            int end   = i + R - 1;
            // The largest palindrome ending at 'end'
            bestLeft[end] = max(bestLeft[end], 2 * R - 1);
            // The largest palindrome starting at 'start'
            bestRight[start] = max(bestRight[start], 2 * R - 1);
        }

        // Step 3: Expand influence towards edges
        // For bestLeft: propagate backwards from each end point
        for (int i = n - 2; i >= 0; i--) {
            // If there's a palindrome ending at i+1, it implies there is a shorter one ending at i
            bestLeft[i] = max(bestLeft[i], bestLeft[i + 1] - 2);
        }
        for (int i = 1; i < n; i++) {
            bestLeft[i] = max(bestLeft[i], bestLeft[i - 1]);
        }

        // For bestRight: propagate forwards
        for (int i = 1; i < n; i++) {
            bestRight[i] = max(bestRight[i], bestRight[i - 1] - 2);
        }
        for (int i = n - 2; i >= 0; i--) {
            bestRight[i] = max(bestRight[i], bestRight[i + 1]);
        }

        // Step 4: Combine
        int ans = 0;
        for (int split = 0; split < n - 1; split++) {
            ans = max(ans, bestLeft[split] + bestRight[split + 1]);
        }
        return ans;
    }
};
