class Solution {
public:
    int kBitFlips(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> isFlipped(n, 0); // to mark where flips start
        int flip = 0, ans = 0;
        
        for (int i = 0; i < n; i++) {
            // Remove effect of a flip that ended k steps before
            if (i >= k) {
                flip ^= isFlipped[i - k];
            }
            
            // If current effective bit is 0, we must flip here
            if ((arr[i] ^ flip) == 0) {
                if (i + k > n) return -1; // not enough space left to flip
                ans++;
                flip ^= 1;          // toggle flip state
                isFlipped[i] = 1;   // mark flip start at i
            }
        }
        return ans;
    }
};
