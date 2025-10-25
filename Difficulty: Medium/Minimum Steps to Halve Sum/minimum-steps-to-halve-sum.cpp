#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& arr) {
        priority_queue<double> pq; // max-heap for greedy selection
        double sum = 0;

        for (int num : arr) {
            sum += num;
            pq.push(num);
        }

        double target = sum / 2.0;
        int operations = 0;

        while (sum > target) {
            double largest = pq.top(); pq.pop(); // take largest
            double half = largest / 2.0;
            sum -= (largest - half);           // reduce sum
            pq.push(half);                     // push back halved value
            operations++;                      // count operation
        }

        return operations;
    }
};