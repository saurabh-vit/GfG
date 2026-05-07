/*
Definition for Node
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool isIdentical(Node* a, Node* b){
        
        // If both trees are empty
        if(a == NULL && b == NULL){
            return true;
        }
        
        // If one is empty and other is not
        if(a == NULL || b == NULL){
            return false;
        }
        
        // Check current node and both subtrees
        return (a->data == b->data) &&
               isIdentical(a->left, b->left) &&
               isIdentical(a->right, b->right);
    }
    
    bool isSubTree(Node *root1, Node *root2) {
        // code here
        if(root2 == NULL){
            return true;
        }
        
        // Main tree becomes empty
        if(root1 == NULL){
            return false;
        }
        
        // If trees match from current node
        if(isIdentical(root1, root2)){
            return true;
        }
        
        // Check in left or right subtree
        return isSubTree(root1->left, root2) ||
               isSubTree(root1->right, root2);
    }
};