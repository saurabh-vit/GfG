/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int height(Node* root) {
        // code here
        if(!root){
            return -1;
        }
        int l = height(root->left);
        int r = height(root->right);
        
        return max(l, r)+1;
    }
};