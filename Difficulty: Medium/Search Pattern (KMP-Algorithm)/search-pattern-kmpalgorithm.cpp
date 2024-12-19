//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> buildLPS(const string& pat) {
        int m = pat.size();
        vector<int> lps(m, 0);
        int len=0;
        int i=1;
        while (i<m) {
            if (pat[i]==pat[len]) {
                len++;
                lps[i]=len;
                i++;
            }else{
                if (len!=0) {
                    len =lps[len-1];
                }else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        return lps;
    }
    vector<int> search(string& pat, string& txt) {
        vector<int> result;
        int n = txt.size(), m = pat.size();
        if (m > n) return result;
        vector<int> lps = buildLPS(pat);
        int i=0, j=0;
        while (i<n) {
            if (txt[i] ==pat[j]) {
                i++;
                j++;
            }
            if (j==m) {
                result.push_back(i-j);
                j = lps[j-1];
            } else if (i<n && txt[i] !=pat[j]) {
                if (j !=0) {
                    j = lps[j-1];
                } else {
                    i++;
                }
            }
        }
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends