// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> maxheap;
        for(int i = 0; i<arr.size(); i++){
            maxheap.push(arr[i]);
            if(maxheap.size()>k){
                maxheap.pop();
            }
        }
        return maxheap.top();
    }
};