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
    int height(Node* root, int &d){
        if(!root){
            return 0;
        }
        int leftd = height(root->left, d);
        int rightd = height(root->right, d);
        d = max(d, leftd+rightd);
        return 1+max(leftd, rightd);
    }
  
    int diameter(Node* root) {
        // code here
        int d = 0;
        height(root, d);
        return d;
    }
};