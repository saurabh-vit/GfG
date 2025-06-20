class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if (n % k != 0) return false;

        map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }

        for (auto it = freq.begin(); it != freq.end(); ++it) {
            int num = it->first;
            int count = it->second;
            if (count > 0) {
                // Try to form a group starting from num
                for (int i = 0; i < k; ++i) {
                    if (freq[num + i] < count)
                        return false;
                    freq[num + i] -= count;
                }
            }
        }

        return true;
    }
};