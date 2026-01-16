class Solution {
public:
    int minMen(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> intervals;

        // Step 1: Build valid intervals
        for(int i = 0; i < n; i++) {
            if(arr[i] != -1) {
                int l = max(0, i - arr[i]);
                int r = min(n - 1, i + arr[i]);
                intervals.push_back({l, r});
            }
        }

        // Sort by starting time
        sort(intervals.begin(), intervals.end());

        int count = 0;
        int currEnd = 0;
        int i = 0;

        while(currEnd < n) {
            int maxReach = -1;

            // Try to extend coverage
            while(i < intervals.size() && intervals[i].first <= currEnd) {
                maxReach = max(maxReach, intervals[i].second);
                i++;
            }

            // ❗ Cannot cover current hour
            if(maxReach < currEnd) {
                return -1;
            }

            count++;
            currEnd = maxReach + 1;
        }

        return count;
    }
};
