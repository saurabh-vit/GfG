class Solution {
  public:
    vector<string> graycode(int n) {
        // code here
        vector<string> result;
    result.push_back("0");
    result.push_back("1");

    // Build Gray code iteratively
    for (int i = 2; i <= n; i++) {
        int size = result.size();
        // Mirror the existing sequence
        for (int j = size - 1; j >= 0; j--) {
            result.push_back(result[j]);
        }
        // Prefix '0' to the first half
        for (int j = 0; j < size; j++) {
            result[j] = "0" + result[j];
        }
        // Prefix '1' to the second half
        for (int j = size; j < 2 * size; j++) {
            result[j] = "1" + result[j];
        }
    }

    return result;
   
    }
};