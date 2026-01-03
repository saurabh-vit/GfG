/*
struct Node {
    int data;
    Node *next;
    Node *bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
  
    // Merge two sorted lists using bottom pointer
    Node* merge(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;

        Node* result;

        if (a->data < b->data) {
            result = a;
            result->bottom = merge(a->bottom, b);
        } else {
            result = b;
            result->bottom = merge(a, b->bottom);
        }

        result->next = NULL; // Important
        return result;
    }

    // Flatten function
    Node* flatten(Node* root) {
        // Base case
        if (!root || !root->next)
            return root;

        // Recursively flatten right list
        root->next = flatten(root->next);

        // Merge current list with flattened right list
        root = merge(root, root->next);

        return root;
    }
};

