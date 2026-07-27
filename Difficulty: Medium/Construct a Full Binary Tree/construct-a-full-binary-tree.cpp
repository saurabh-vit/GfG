/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
    int idx;
    unordered_map<int, int> mp;

    Node* build(vector<int> &pre, vector<int> &preMirror, int l, int r) {
        Node* root = new Node(pre[idx++]);

        if (idx >= pre.size() || l == r)
            return root;

        int pos = mp[pre[idx]];

        root->left = build(pre, preMirror, pos, r);
        root->right = build(pre, preMirror, l + 1, pos - 1);

        return root;
    }

  public:
    Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {
        idx = 0;
        int n = preMirror.size();

        for (int i = 0; i < n; i++)
            mp[preMirror[i]] = i;

        return build(pre, preMirror, 0, n - 1);
    }
};