class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = n * m - 1;
    
        auto getVal = [&](int idx) {
            return mat[idx / m][idx % m];
        };
    
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int midVal = getVal(mid);
            if (midVal == x) return true;
    
            int lowVal = getVal(low);
            int highVal = getVal(high);
    
            if (lowVal <= midVal) {  
                // Left half is sorted
                if (lowVal <= x && x < midVal)
                    high = mid - 1;
                else
                    low = mid + 1;
            } else {  
                // Right half is sorted
                if (midVal < x && x <= highVal)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return false;
    }
};
