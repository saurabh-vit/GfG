#include <bits/stdc++.h>
using namespace std;

class SpecialQueue {
    deque<int> q;
    deque<int> minDeque;
    deque<int> maxDeque;

public:
    void enqueue(int x) {
        q.push_back(x);
        while (!minDeque.empty() && minDeque.back() > x)
            minDeque.pop_back();
        minDeque.push_back(x);
        while (!maxDeque.empty() && maxDeque.back() < x)
            maxDeque.pop_back();
        maxDeque.push_back(x);
    }

    void dequeue() {
        if (q.empty()) return;
        int frontVal = q.front();
        q.pop_front();
        if (!minDeque.empty() && minDeque.front() == frontVal)
            minDeque.pop_front();
        if (!maxDeque.empty() && maxDeque.front() == frontVal)
            maxDeque.pop_front();
    }

    int getFront() {
        return q.front();
    }

    int getMin() {
        return minDeque.front();
    }

    int getMax() {
        return maxDeque.front();
    }
};