class Solution {
public:
    
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        return prev;
    }
    
    Node* compute(Node* head) {
        if (!head || !head->next)
            return head;
        
        // Step 1: Reverse the list
        head = reverseList(head);
        
        // Step 2: Remove nodes smaller than max seen so far
        int maxSoFar = head->data;
        Node* curr = head;
        
        while (curr && curr->next) {
            if (curr->next->data < maxSoFar) {
                Node* temp = curr->next;
                curr->next = temp->next;
                delete temp;
            } else {
                curr = curr->next;
                maxSoFar = curr->data;
            }
        }
        
        // Step 3: Reverse again
        head = reverseList(head);
        
        return head;
    }
};