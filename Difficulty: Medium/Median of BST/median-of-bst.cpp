/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void inorder(Node* root, vector<int>& arr) {
        if (!root) return;
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
    
    int findMedian(Node* root) {
        vector<int> arr;
        inorder(root, arr);
        int n = arr.size();
        
        if (n % 2 == 0) 
            return arr[n/2 - 1];   // even → V(n/2)
        else 
            return arr[n/2];       // odd → V((n+1)/2)
    }
};
