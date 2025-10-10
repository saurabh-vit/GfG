/*
class Node {
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
    vector<int> zigZagTraversal(Node* root) {
        // code here
        vector<int> result;
        if (!root) return result;
    
        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;
    
        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);
    
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
    
                // Index to insert based on traversal direction
                int index = leftToRight ? i : size - i - 1;
                level[index] = node->data;
    
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
    
            // Add this level to final result
            for (int val : level) result.push_back(val);
    
            // Switch direction for next level
            leftToRight = !leftToRight;
        }
    
        return result;
    }
};