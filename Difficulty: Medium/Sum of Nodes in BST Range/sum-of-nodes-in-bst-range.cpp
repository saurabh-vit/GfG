/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int nodeSum(Node* root, int l, int r) {
        // code here
        if (!root) return 0;

        // If current node is smaller than l, skip left subtree
        if (root->data < l)
            return nodeSum(root->right, l, r);

        // If current node is greater than r, skip right subtree
        if (root->data > r)
            return nodeSum(root->left, l, r);

        // If within range, include this node and search both subtrees
        return root->data + nodeSum(root->left, l, r) + nodeSum(root->right, l, r);
    }
};
