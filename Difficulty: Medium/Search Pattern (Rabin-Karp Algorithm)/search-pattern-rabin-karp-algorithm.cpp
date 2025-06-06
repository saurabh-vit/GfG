class Solution {
  public:
    // Build LPS (Longest Prefix Suffix) array
    vector<int> buildLPS(string &pat) {
        int m = pat.size();
        vector<int> lps(m, 0);
        int len = 0;
        int i = 1;

        while(i < m){
            if(pat[i] == pat[len]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len != 0){
                    len = lps[len - 1];
                }else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    vector<int> search(string &pat, string &txt) {
        vector<int> ans;
        int m = pat.size(), n = txt.size();

        if(m > n) return ans;

        vector<int> lps = buildLPS(pat);

        int i = 0, j = 0;
        while(i < n){
            if(pat[j] == txt[i]){
                i++;
                j++;
            }

            if(j == m){
                ans.push_back(i - j + 1); // 1-based indexing
                j = lps[j - 1]; // continue searching for next match
            }else if(i < n && pat[j] != txt[i]){
                if(j != 0){
                    j = lps[j - 1];
                }else{
                    i++;
                }
            }
        }

        return ans;
    }
};
