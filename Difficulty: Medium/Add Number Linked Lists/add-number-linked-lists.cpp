class Solution {
  public:
    // Function to reverse a linked list
    Node* reverse(Node* head) {
        Node* prev = NULL;
        while (head) {
            Node* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }

    Node* addTwoLists(Node* head1, Node* head2) {
        // Reverse both lists
        head1 = reverse(head1);
        head2 = reverse(head2);

        int carry = 0;
        Node* dummy = new Node(0);
        Node* curr = dummy;

        // Add both lists
        while (head1 || head2 || carry) {
            int sum = carry;

            if (head1) {
                sum += head1->data;
                head1 = head1->next;
            }
            if (head2) {
                sum += head2->data;
                head2 = head2->next;
            }

            carry = sum / 10;
            curr->next = new Node(sum % 10);
            curr = curr->next;
        }

        // Reverse the result
        Node* result = reverse(dummy->next);

        // Remove leading zeros (if any)
        while (result && result->data == 0 && result->next)
            result = result->next;

        return result;
    }
};
