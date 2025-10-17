/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
    int sum = 0;

    void helper(Node* root) {
        if (!root) return;
        
        helper(root->right);

        int original = root->data;
        root->data = sum;
        
        sum += original;

        helper(root->left);
    }

    void transformTree(Node *root) {
        sum = 0;
        helper(root);
    }
};
