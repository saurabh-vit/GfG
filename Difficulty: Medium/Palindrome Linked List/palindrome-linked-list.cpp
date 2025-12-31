class Solution {
public:
    bool isPalindrome(Node* head) {
        if (!head || !head->next) return true;

        // Step 1: Find middle
        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        Node* prev = NULL;
        Node* curr = slow;
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Step 3: Compare both halves
        Node* left = head;
        Node* right = prev;

        while (right) {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->next;
        }

        return true;
    }
};
