/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        if (!head || !head->next) return head;

        // Dummy nodes for 0, 1, and 2 lists
        Node* zeroHead = new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);

        Node* zero = zeroHead;
        Node* one = oneHead;
        Node* two = twoHead;

        // Partition nodes into 3 lists
        Node* curr = head;
        while (curr) {
            if (curr->data == 0) {
                zero->next = curr;
                zero = zero->next;
            } else if (curr->data == 1) {
                one->next = curr;
                one = one->next;
            } else {
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }

        // Connect three lists together: 0s → 1s → 2s
        zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
        one->next = twoHead->next;
        two->next = nullptr;

        // New head is start of zero list if present, else one list, else two list
        Node* newHead = zeroHead->next;

        // Delete dummy heads
        delete zeroHead;
        delete oneHead;
        delete twoHead;

        return newHead;
    }
};