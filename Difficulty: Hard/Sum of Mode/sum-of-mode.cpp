class Solution {
  public:
    int sumOfModes(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int,int> freq;              // element -> frequency
        map<int, set<int>> freqToVals;            // frequency -> set of values

        auto add = [&](int val) {
            int f = freq[val];
            if (f > 0) {
                freqToVals[f].erase(val);
                if (freqToVals[f].empty()) freqToVals.erase(f);
            }
            freq[val]++;
            freqToVals[freq[val]].insert(val);
        };

        auto remove = [&](int val) {
            int f = freq[val];
            freqToVals[f].erase(val);
            if (freqToVals[f].empty()) freqToVals.erase(f);
            freq[val]--;
            if (freq[val] > 0) {
                freqToVals[freq[val]].insert(val);
            }
        };

        long long ans = 0;

        // First window
        for (int i = 0; i < k; i++) add(arr[i]);

        // Get mode for first window
        ans += *freqToVals.rbegin()->second.begin();

        // Slide window
        for (int i = k; i < n; i++) {
            remove(arr[i-k]);
            add(arr[i]);
            ans += *freqToVals.rbegin()->second.begin();
        }

        return ans;
    }
};