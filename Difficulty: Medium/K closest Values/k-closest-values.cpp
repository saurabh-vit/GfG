#include <bits/stdc++.h>
using namespace std;

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void inorder(Node* root, vector<int>& arr) {
        if (!root) return;
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }

    vector<int> getKClosest(Node* root, int target, int k) {
        vector<int> inorderVals;
        inorder(root, inorderVals);

        int n = inorderVals.size();
        int pos = lower_bound(inorderVals.begin(), inorderVals.end(), target) - inorderVals.begin();

        int left = pos - 1;
        int right = pos;
        vector<int> result;

        while (k-- > 0) {
            if (left >= 0 && right < n) {
                int diffLeft = abs(inorderVals[left] - target);
                int diffRight = abs(inorderVals[right] - target);

                if (diffLeft <= diffRight) {
                    result.push_back(inorderVals[left]);
                    left--;
                } else {
                    result.push_back(inorderVals[right]);
                    right++;
                }
            } 
            else if (left >= 0) {
                result.push_back(inorderVals[left--]);
            } 
            else if (right < n) {
                result.push_back(inorderVals[right++]);
            } 
            else break;
        }
        return result;  // driver code will sort it before printing
    }
};