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
    Node* swapKth(Node* head, int k) {
        // code here
        if (!head) return head;

        // Step 1: Count length
        int n = 0;
        Node* curr = head;
        while (curr) {
            n++;
            curr = curr->next;
        }

        // Step 2: If k is invalid or both nodes are same
        if (k > n) return head;
        if (2 * k - 1 == n) return head;

        // Step 3: Find kth node from start
        Node* prev1 = nullptr;
        Node* node1 = head;
        for (int i = 1; i < k; i++) {
            prev1 = node1;
            node1 = node1->next;
        }

        // Step 4: Find kth node from end (n-k+1 from start)
        Node* prev2 = nullptr;
        Node* node2 = head;
        for (int i = 1; i < n - k + 1; i++) {
            prev2 = node2;
            node2 = node2->next;
        }

        // Step 5: Adjust previous pointers
        if (prev1) prev1->next = node2;
        if (prev2) prev2->next = node1;

        // Step 6: Swap next pointers
        Node* temp = node1->next;
        node1->next = node2->next;
        node2->next = temp;

        // Step 7: Fix head if needed
        if (k == 1) head = node2;
        if (k == n) head = node1;

        return head;
    }
};