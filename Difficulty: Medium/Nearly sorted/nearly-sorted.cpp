#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nearlySorted(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < min(k + 1, n); i++) {
            pq.push(arr[i]);
        }
        int index = 0;
        for (int i = k + 1; i < n; i++) {
            arr[index++] = pq.top();
            pq.pop();
            pq.push(arr[i]);
        }
        while (!pq.empty()) {
            arr[index++] = pq.top();
            pq.pop();
        }
    }
};