class Solution {
public:
    string chooseSwap(string &s) {
        vector<int> first(26, -1);

        for (int i = 0; i < s.size(); i++) {
            if (first[s[i] - 'a'] == -1)
                first[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.size(); i++) {
            int cur = s[i] - 'a';

            for (int ch = 0; ch < cur; ch++) {
                if (first[ch] > i) {
                    char x = s[i];
                    char y = 'a' + ch;

                    for (char &c : s) {
                        if (c == x)
                            c = y;
                        else if (c == y)
                            c = x;
                    }

                    return s;
                }
            }
        }

        return s;
    }
};