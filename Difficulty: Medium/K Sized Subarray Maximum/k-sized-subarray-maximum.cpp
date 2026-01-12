class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        deque<int> dq;  // stores indices
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            // 1. Remove elements out of this window
            if(!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // 2. Remove all smaller elements from back
            while(!dq.empty() && arr[dq.back()] < arr[i]) {
                dq.pop_back();
            }

            // 3. Add current element index
            dq.push_back(i);

            // 4. Store result when window is complete
            if(i >= k - 1) {
                ans.push_back(arr[dq.front()]);
            }
        }

        return ans;
    }
};