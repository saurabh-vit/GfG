//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        vector<int> left(n, -1), right(n, n), res(n + 1, INT_MIN);
        stack<int> s;
        for(int i=0; i<n; i++){
            while(!s.empty()&&arr[s.top()]>=arr[i]) s.pop();
            if (!s.empty()) left[i] = s.top();
            s.push(i);
        }
        while (!s.empty()) s.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            if (!s.empty()) right[i] = s.top();
            s.push(i);
        }
        for (int i = 0; i < n; i++) {
            int windowSize = right[i] - left[i] - 1;
            res[windowSize] = max(res[windowSize], arr[i]);
        }
        for (int i = n - 1; i >= 1; i--) {
            res[i] = max(res[i], res[i + 1]);
        }
        res.erase(res.begin());
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends