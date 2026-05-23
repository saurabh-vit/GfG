/* Structure for Tree Node
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
    int solve(Node* root) {
        if(root == NULL)
            return 0;
        
        int oldValue = root->data;
        
        int leftSum = solve(root->left);
        int rightSum = solve(root->right);
        
        // Update current node
        root->data = leftSum + rightSum;
        
        // Return total sum including original value
        return oldValue + leftSum + rightSum;
    }
    
    void toSumTree(Node *node)
    {
        solve(node);
    }
};