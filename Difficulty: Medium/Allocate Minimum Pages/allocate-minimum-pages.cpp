class Solution {
  public:
    bool isPossible(vector<int>& arr, int k, int mid) {
        int students = 1;
        int pages = 0;
        
        for (int pagesInBook : arr) {
            if (pages + pagesInBook > mid) {
                students++;
                pages = pagesInBook;
                if (students > k) return false;
            } else {
                pages += pagesInBook;
            }
        }
        return true;
    }

    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n) return -1;   // Not enough books
        
        int low = *max_element(arr.begin(), arr.end());   // largest book
        int high = accumulate(arr.begin(), arr.end(), 0); // sum of all pages
        int result = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, k, mid)) {
                result = mid;      // valid allocation
                high = mid - 1;    // try smaller max
            } else {
                low = mid + 1;     // increase pages
            }
        }
        return result;
    }
};