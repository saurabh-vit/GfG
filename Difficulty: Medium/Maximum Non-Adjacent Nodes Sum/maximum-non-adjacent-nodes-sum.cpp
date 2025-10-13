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
    pair<int,int> solve(Node* root) {
        if(!root) return {0, 0};
    
        auto left = solve(root->left);
        auto right = solve(root->right);
    
        int includeRoot = root->data + left.second + right.second; // use data
        int excludeRoot = max(left.first, left.second) + max(right.first, right.second);
    
        return {includeRoot, excludeRoot};
    }

    int getMaxSum(Node *root) {
        auto res = solve(root);
        return max(res.first, res.second);
    }
};
