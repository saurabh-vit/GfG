class Solution {
public:
    int findPivot(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > arr[high])
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }

    int countLE(vector<int>& arr, int l, int r, int x) {
        if (l > r) return 0;
        return upper_bound(arr.begin() + l, arr.begin() + r + 1, x)
               - (arr.begin() + l);
    }

    int countLessEqual(vector<int>& arr, int x) {
        int n = arr.size();
        int pivot = findPivot(arr);

        // Left sorted part: [0 ... pivot-1]
        int leftCount = countLE(arr, 0, pivot - 1, x);

        // Right sorted part: [pivot ... n-1]
        int rightCount = countLE(arr, pivot, n - 1, x);

        return leftCount + rightCount;
    }
};