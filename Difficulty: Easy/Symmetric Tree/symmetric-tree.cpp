/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    bool isSymmetric(Node* root) {
        // Code here
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
  private:
    bool isMirror(Node* left, Node* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        return (left->data == right->data) &&
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }
};