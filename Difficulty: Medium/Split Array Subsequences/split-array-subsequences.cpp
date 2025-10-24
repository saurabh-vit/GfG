#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPossible(vector<int>& arr, int k) {
        int n = arr.size();
        if (n < k) return false; // cannot form even one subsequence of length k

        // Min-heap storing pairs {last_number_of_subsequence, length_of_subsequence}
        using pii = pair<int, int>;
        auto cmp = [](const pii &a, const pii &b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        };
        priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);

        for (int x : arr) {
            // Remove all subsequences that can't be extended by 'x'
            while (!pq.empty() && pq.top().first + 1 < x) {
                auto [val, len] = pq.top();
                pq.pop();
                if (len < k) return false; // ended too early
            }

            if (pq.empty() || pq.top().first == x) {
                // start a new subsequence with 'x'
                pq.push({x, 1});
            } else {
                // extend an existing subsequence ending at x-1
                auto [val, len] = pq.top();
                pq.pop();
                pq.push({x, len + 1});
            }
        }
        while (!pq.empty()) {
            if (pq.top().second < k) return false;
            pq.pop();
        }

        return true;
    }
};