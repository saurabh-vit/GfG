//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myAtoi(const string& s) {
        // Your code here
        int i = 0, n=s.length();
        while (i<n && s[i] ==' '){
            i++;
        }
        int sign = 1; 
        if (i<n && (s[i]=='+' || s[i]=='-')){
            if (s[i]=='-'){
                sign=-1;
            } 
            i++; 
        }
        long long result = 0;
        while (i < n && isdigit(s[i])){
            result = result * 10 + (s[i] - '0');
            if (result * sign > INT_MAX){
                return INT_MAX;
            } else if (result*sign < INT_MIN){
                return INT_MIN;
            } 
            i++; 
        } 
        return static_cast<int>(result*sign);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends