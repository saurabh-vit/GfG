class Solution {
public:
    vector<int> printNearNodes(Node *root, int low, int high) {
        vector<int> ans;
        if (!root) return ans;

        // Traverse left subtree if values might be in range
        if (root->data > low) {
            vector<int> left = printNearNodes(root->left, low, high);
            ans.insert(ans.end(), left.begin(), left.end());
        }

        // If current node is within range, include it
        if (root->data >= low && root->data <= high) {
            ans.push_back(root->data);
        }

        // Traverse right subtree if values might be in range
        if (root->data < high) {
            vector<int> right = printNearNodes(root->right, low, high);
            ans.insert(ans.end(), right.begin(), right.end());
        }

        return ans;
    }
};
