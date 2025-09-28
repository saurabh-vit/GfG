class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size();
        int bestLen = 0, bestStart = 0;

        for (int i = 0; i < n; i++) {
            int currMin = arr[i], currMax = arr[i];
            for (int j = i; j < n; j++) {
                currMin = min(currMin, arr[j]);
                currMax = max(currMax, arr[j]);

                if (currMax - currMin <= x) {
                    if (j - i + 1 > bestLen) {
                        bestLen = j - i + 1;
                        bestStart = i;
                    }
                } else {
                    break; // no need to extend further
                }
            }
        }

        return vector<int>(arr.begin() + bestStart, arr.begin() + bestStart + bestLen);
    }
};