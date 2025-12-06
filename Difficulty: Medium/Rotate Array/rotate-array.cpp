class Solution {
public:
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d = d % n;

        vector<int> temp;
        for(int i = d; i < n; i++) temp.push_back(arr[i]);
        for(int i = 0; i < d; i++) temp.push_back(arr[i]);

        arr = temp;
    }
};
