class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        int n = mat1.size();
        int count=0;
        unordered_map<int, int> freq;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                freq[mat2[i][j]]++;
            }
        }
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j) {
                int complement = x - mat1[i][j];
                if (freq.count(complement)) count += freq[complement];
            }
        }
        return count;
    }
};