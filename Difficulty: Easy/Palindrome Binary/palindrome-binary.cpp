class Solution {
  public:
    bool isBinaryPalindrome(int n) {
        // code here
        string binary = "";
        while (n > 0) {
            binary += (n % 2) + '0';
            n /= 2;
        }
        int i = 0, j = binary.size() - 1;
        while (i < j) {
            if (binary[i] != binary[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};