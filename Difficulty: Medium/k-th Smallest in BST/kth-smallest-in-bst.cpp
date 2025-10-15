/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void inorder(Node* root, int &k, int &ans) {
        if (!root) return;
        
        inorder(root->left, k, ans);  // Left
        
        k--;
        if (k == 0) {
            ans = root->data;
            return;
        }
        
        inorder(root->right, k, ans); // Right
    }
    int kthSmallest(Node *root, int k) {
        // code here
        int ans = -1;
        inorder(root, k, ans);
        return ans;
    }
};