class Solution {
  public:
    int mergeAndCount(vector<int> &arr, int left, int mid, int right) {
        int count = 0;
        int j = mid + 1;

        // Count reverse pairs
        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)arr[i] > 2LL * arr[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        // Merge step
        vector<int> temp;
        int i = left;
        j = mid + 1;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j])
                temp.push_back(arr[i++]);
            else
                temp.push_back(arr[j++]);
        }
        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= right) temp.push_back(arr[j++]);

        for (int k = left; k <= right; k++) {
            arr[k] = temp[k - left];
        }

        return count;
    }

    int mergeSortAndCount(vector<int> &arr, int left, int right) {
        if (left >= right) return 0;

        int mid = left + (right - left) / 2;
        int count = mergeSortAndCount(arr, left, mid);
        count += mergeSortAndCount(arr, mid + 1, right);
        count += mergeAndCount(arr, left, mid, right);

        return count;
    }
    
    int countRevPairs(vector<int> &arr) {
        // Code here
        return mergeSortAndCount(arr, 0, arr.size() - 1);
    }
};