/*
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    // Function to merge two sorted linked lists
    Node* merge(Node* l1, Node* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        Node* result = nullptr;

        if (l1->data <= l2->data) {
            result = l1;
            result->next = merge(l1->next, l2);
        } else {
            result = l2;
            result->next = merge(l1, l2->next);
        }
        return result;
    }

    // Function to find middle of the linked list
    Node* getMiddle(Node* head) {
        if (!head) return head;

        Node* slow = head;
        Node* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    Node* mergeSort(Node* head) {
        // Base case
        if (!head || !head->next) return head;

        // Step 1: Split into halves
        Node* mid = getMiddle(head);
        Node* rightHead = mid->next;
        mid->next = nullptr; // break the list

        // Step 2: Recursively sort halves
        Node* left = mergeSort(head);
        Node* right = mergeSort(rightHead);

        // Step 3: Merge sorted halves
        return merge(left, right);
    }
};