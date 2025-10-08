/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int preIndex;
    unordered_map<int, int> postIndexMap;

    Node* build(vector<int>& pre, vector<int>& post, int left, int right) {
        if (preIndex >= pre.size() || left > right)
            return nullptr;

        Node* root = new Node(pre[preIndex++]);
        
        // If it's a leaf node, return
        if (left == right || preIndex >= pre.size())
            return root;

        // Find the next preorder element in post[]
        int idx = postIndexMap[pre[preIndex]];

        // Build left and right subtrees
        root->left = build(pre, post, left, idx);
        root->right = build(pre, post, idx + 1, right - 1);

        return root;
    }

    Node* constructTree(vector<int>& pre, vector<int>& post) {
        preIndex = 0;
        postIndexMap.clear();

        // store postorder value → index for O(1) lookup
        for (int i = 0; i < post.size(); i++) {
            postIndexMap[post[i]] = i;
        }

        return build(pre, post, 0, post.size() - 1);
    }
};