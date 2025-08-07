class Solution {
  public:
    int timeToSeconds(const string& time) {
        int h = stoi(time.substr(0, 2));
        int m = stoi(time.substr(3, 2));
        int s = stoi(time.substr(6, 2));
        return h * 3600 + m * 60 + s;
    }

    int minDifference(vector<string> &arr) {
        vector<int> seconds;
        for (const string& time : arr) {
            seconds.push_back(timeToSeconds(time));
        }
        sort(seconds.begin(), seconds.end());
        int minDiff = INT_MAX;
        int n = seconds.size();
        for (int i = 1; i < n; ++i) {
            minDiff = min(minDiff, seconds[i] - seconds[i - 1]);
        }
        int wrapAroundDiff = 24 * 3600 - seconds[n - 1] + seconds[0];
        minDiff = min(minDiff, wrapAroundDiff);

        return minDiff;
    }
};