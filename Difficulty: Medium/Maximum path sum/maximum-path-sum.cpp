/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int maxSum;  // global variable to track maximum path sum

    int dfs(Node* root) {
        if (!root) return 0;

        // Compute maximum path sum from left and right subtrees
        // Ignore negative sums (they reduce total path sum)
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        // Update global maximum considering current node as root of path
        maxSum = max(maxSum, root->data + left + right);

        // Return the maximum sum path including current node (one side only)
        return root->data + max(left, right);
    }

    int findMaxSum(Node *root) {
        maxSum = INT_MIN;   // initialize to smallest integer
        dfs(root);
        return maxSum;
    }
};