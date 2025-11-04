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
    vector<int> topView(Node *root) {
        vector<int> ans;
        if (!root) return ans;

        // Queue for BFS traversal (stores pair of node and horizontal distance)
        queue<pair<Node*, int>> q;
        map<int, int> m; // Maps horizontal distance → node data

        q.push({root, 0});

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            Node* currNode = curr.first;
            int hd = curr.second;

            // Store the first node encountered at each horizontal distance
            if (m.count(hd) == 0) {
                m[hd] = currNode->data;
            }

            // Add child nodes with updated horizontal distance
            if (currNode->left)
                q.push({currNode->left, hd - 1});
            if (currNode->right)
                q.push({currNode->right, hd + 1});
        }

        // Extract values in order of increasing horizontal distance
        for (auto it : m) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
