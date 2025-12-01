/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    Node* sortedArrayToBST(vector<int>& arr) {
        // code here
        return helper(arr, 0, arr.size()-1);
    }
    Node* helper(vector<int> &arr, int st, int end){
        if(st>end){
            return nullptr;
        }
        int mid = st+(end-st)/2;
        Node* curr = new Node(arr[mid]);
        curr->left = helper(arr, st, mid-1);
        curr->right = helper(arr, mid+1, end);
        return curr;
    }
};