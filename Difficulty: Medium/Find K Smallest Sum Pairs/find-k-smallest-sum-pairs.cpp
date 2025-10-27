#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPair(vector<int>& arr1, vector<int>& arr2, int k) {
        vector<vector<int>> ans;
        if (arr1.empty() || arr2.empty() || k == 0) return ans;

        // Min-heap: (sum, i, j)
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> minHeap;

        // push first element from arr1 with every element in arr2 (up to k)
        for (int j = 0; j < arr2.size() && j < k; ++j) {
            minHeap.emplace(arr1[0] + arr2[j], 0, j);
        }

        // Extract k smallest pairs
        while (k-- > 0 && !minHeap.empty()) {
            auto [sum, i, j] = minHeap.top();
            minHeap.pop();

            ans.push_back({arr1[i], arr2[j]});

            // Push next element from arr1 with same arr2[j]
            if (i + 1 < arr1.size()) {
                minHeap.emplace(arr1[i + 1] + arr2[j], i + 1, j);
            }
        }

        return ans;
    }
};
