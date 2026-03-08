// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        int n = arr.size();
        int maxproduct = arr[0];
        int maxsofar = arr[0];
        int minsofar = arr[0];
        for (int i=1; i<n; i++) {
            if (arr[i]<0) {
                swap(maxsofar, minsofar);
            }
            maxsofar = max(arr[i], maxsofar * arr[i]);
            minsofar = min(arr[i], minsofar * arr[i]);
            maxproduct = max(maxproduct, maxsofar);
        }
        return maxproduct;
    }
};
