class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        int duplicate = -1, missing = -1;

        // Step 1: Find duplicate using index marking
        for (int i = 0; i < n; i++) {
            int x = abs(arr[i]);

            if (arr[x - 1] < 0) {
                duplicate = x;          // visited before -> duplicate
            } else {
                arr[x - 1] *= -1;       // mark visited
            }
        }

        // Step 2: Find missing (index which is still positive)
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                missing = i + 1;
                break;
            }
        }

        return {duplicate, missing};
    }
};
