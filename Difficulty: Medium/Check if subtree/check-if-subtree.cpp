/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    // Function to check if S is a subtree of tree T.
    bool isidentical(Node* t, Node* s){
        if(!t && !s)    return true;
        if(!t || !s)    return false;
        if(t->data != s->data)  return false;
        return isidentical(t->left, s->left) && isidentical(t->right, s->right);
    }
    
    bool isSubTree(Node* t, Node* s) {
        // Your code here
        if(!s)  return true;
        if(!t)  return false;
        if(t->data == s->data && isidentical(t, s)){
            return true;
        }
        return isSubTree(t->left, s) || isSubTree(t->right, s);
    }
};