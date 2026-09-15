class Solution {
  public:

    void findLeaves(Node* root, int level, vector<int>& costs) {
        if (root == nullptr)
            return;

        // If this is a leaf node
        if (root->left == nullptr && root->right == nullptr) {
            costs.push_back(level);
            return;
        }

        findLeaves(root->left, level + 1, costs);
        findLeaves(root->right, level + 1, costs);
    }

    int getCount(Node *root, int k) {
        vector<int> costs;

        // Root is at level 1
        findLeaves(root, 1, costs);

        // Visit cheapest leaves first
        sort(costs.begin(), costs.end());

        int count = 0;

        for (int cost : costs) {
            if (cost > k)
                break;

            k -= cost;
            count++;
        }

        return count;
    }
};