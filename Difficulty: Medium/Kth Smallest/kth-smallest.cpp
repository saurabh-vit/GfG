// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int num : arr) {
            minHeap.push(num);
        }
        for (int i = 0; i < k - 1; ++i) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};