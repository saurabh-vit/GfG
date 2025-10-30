// User function Template for C++

class Solution {
  public:
    int countNodes(Node* root) {
        // Write your code here
        if(!root){
            return 0;
        }
        int lt = countNodes(root->left);
        int rt = countNodes(root->right);
        return lt+rt+1;
    }
};