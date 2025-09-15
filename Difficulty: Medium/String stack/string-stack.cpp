class Solution {
public:
    bool stringStack(string &pat, string &tar) {
        int i = pat.size() - 1;
        int j = tar.size() - 1;
        while (i >= 0 && j >= 0) {
            if (pat[i] == tar[j]) {
                i -= 1;   // move both pointers
                j -= 1;
            } else {
                i -= 2;   // skipping two chars from pattern
            }
            if (j == -1) {
                return true;
            }
        }
        return false;
    }
};