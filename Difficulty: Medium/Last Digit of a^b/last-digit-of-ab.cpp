class Solution {
public:
    int getLastDigit(string a, string b) {
        if (b == "0") return 1;

        vector<vector<int>> cycles = {
            {0},          // 0
            {1},          // 1
            {2, 4, 8, 6}, // 2
            {3, 9, 7, 1}, // 3
            {4, 6},       // 4
            {5},          // 5
            {6},          // 6
            {7, 9, 3, 1}, // 7
            {8, 4, 2, 6}, // 8
            {9, 1}        // 9
        };

        int lastDigit = a.back() - '0';
        vector<int>& cycle = cycles[lastDigit];

        int len = cycle.size();

        int mod = 0;
        for (char c : b) {
            mod = (mod * 10 + (c - '0')) % len;
        }

        if (mod == 0) mod = len;

        return cycle[mod - 1];
    }
};