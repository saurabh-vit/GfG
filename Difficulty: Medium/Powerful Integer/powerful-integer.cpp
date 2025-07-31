class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        // code here
        map<int, int> diff;

        // Step 1: Mark starts and ends of intervals
        for (auto& it : intervals) {
            diff[it[0]]++;
            diff[it[1] + 1]--;  // Make it inclusive
        }

        int active = 0;
        int maxPowerful = -1;

        for (auto it = diff.begin(); it != diff.end(); ++it) {
            active += it->second;
            auto nextIt = next(it);

            if (active >= k && nextIt != diff.end()) {
                // The entire range [it->first, nextIt->first - 1] is powerful
                maxPowerful = max(maxPowerful, nextIt->first - 1);
            }
        }

        return maxPowerful;
    }
};