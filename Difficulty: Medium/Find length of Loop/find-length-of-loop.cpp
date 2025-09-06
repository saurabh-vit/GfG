/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        if(!head || !head->next) return 0;
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                return countloop(slow);
            }
        }
        return 0;
    }
  private:
    int countloop(Node* nodeInLoop){
        int count = 1;
        Node* temp = nodeInLoop->next;
        
        while(temp != nodeInLoop){
            count++;
            temp = temp->next;
        }
        return count;
    }
};