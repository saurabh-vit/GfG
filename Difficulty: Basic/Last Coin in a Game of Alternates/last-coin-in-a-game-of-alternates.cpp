class Solution {
  public:
    int coin(vector<int>& arr) {
        // code here
        int i = 0;
        int j = arr.size() - 1;
        while (i < j) {
            if (arr[i] >= arr[j]) {
                i++;   // pick left coin
            } else {
                j--;   // pick right coin
            }
        }

        return arr[i];
    }
};