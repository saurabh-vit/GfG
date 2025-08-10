class Solution {
  public:
    int countPS(string &s) {
        // code here
        int n = s.size();
        int count = 0;
        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 >= 2) // length >= 2
                    count++;
                left--;
                right++;
            }
        };
        for (int i = 0; i < n; i++) {
            expand(i, i);
            expand(i, i + 1);
        }
        return count;
    }
};