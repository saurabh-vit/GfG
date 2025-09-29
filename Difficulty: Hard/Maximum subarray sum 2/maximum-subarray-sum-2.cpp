class Solution {
  public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        // code here
        int n = arr.size();
        vector<long long> prefix(n+1, 0);
        for (int i = 0; i < n; i++)
            prefix[i+1] = prefix[i] + arr[i];

        deque<int> dq;
        long long ans = LLONG_MIN;

        for (int r = a; r <= n; r++) {
            dq.push_back(r - a);

            while (!dq.empty() && dq.front() < r - b) dq.pop_front();

            ans = max(ans, prefix[r] - prefix[dq.front()]);
            while (!dq.empty() && prefix[dq.back()] >= prefix[r - a + 1])
                dq.pop_back();
        }
        return ans;
    }
};