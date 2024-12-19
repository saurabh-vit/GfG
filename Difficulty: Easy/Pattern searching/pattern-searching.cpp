//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    bool searchPattern(string& txt, string& pat) {
        return txt.find(pat) != string::npos;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        string str, pat;
        cin >> str;
        cin >> pat;
        Solution obj;
        if (obj.searchPattern(str, pat) == true)
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends