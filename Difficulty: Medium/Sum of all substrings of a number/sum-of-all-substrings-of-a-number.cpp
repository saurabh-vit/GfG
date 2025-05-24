class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
        int n = s.length();
    long long result = s[0] - '0'; // Initialize with first digit
    long long prev = result;
    
    for (int i = 1; i < n; ++i) {
        int num = s[i] - '0';
        prev = prev * 10 + num * (i + 1);
        result += prev;
    }

    return static_cast<int>(result);
    }
};