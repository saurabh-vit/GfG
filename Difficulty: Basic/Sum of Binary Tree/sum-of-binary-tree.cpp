/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Function to return a list containing the level order traversal in spiral form.
class Solution {
  public:
    int sumBT(Node* root) {
        // code here
        if(!root){
            return 0;
        }
        int leftsum = sumBT(root->left);
        int rightsum = sumBT(root->right);
        return leftsum+rightsum+root->data;
    }
};