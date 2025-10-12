/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int moves = 0;

    int dfs(Node* root) {
        if (!root) return 0;

        // Get balance from left and right subtrees
        int left = dfs(root->left);
        int right = dfs(root->right);

        // Add the absolute moves required for both subtrees
        moves += abs(left) + abs(right);

        // Return this node's net balance of candies
        // +ve → extra candies to give to parent
        // -ve → candies needed from parent
        return root->data + left + right - 1;
    }
    
    int distCandy(Node* root) {
        // code here
        moves = 0;
        dfs(root);
        return moves;
    }
};