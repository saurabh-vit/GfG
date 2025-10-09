/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> postOrder(Node* root) {
        // code here
        vector<int> result;
        if (!root) return result;
    
        stack<Node*> st;
        Node* lastVisited = nullptr;
        Node* curr = root;
    
        while (!st.empty() || curr != nullptr) {
            if (curr) {
                st.push(curr);
                curr = curr->left;
            } else {
                Node* peekNode = st.top();
                if (peekNode->right && lastVisited != peekNode->right)
                    curr = peekNode->right;
                else {
                    result.push_back(peekNode->data);
                    lastVisited = peekNode;
                    st.pop();
                }
            }
        }
        return result;
    }
};