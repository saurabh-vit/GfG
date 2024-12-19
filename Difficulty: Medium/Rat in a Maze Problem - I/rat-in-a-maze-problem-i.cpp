//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void findPaths(vector<vector<int>> &mat, int n, int x, int y, string path, vector<string> &paths) {
        if (x == n-1 && y == n-1) {
            paths.push_back(path);
            return;
        }
        if (x < 0 || y < 0 || x >= n || y >= n || mat[x][y] == 0) {
            return;
        }
        mat[x][y] = 0;
        if (x + 1 < n && mat[x + 1][y] == 1) {
            findPaths(mat, n, x + 1, y, path + "D", paths);
        }
        if (y - 1 >= 0 && mat[x][y - 1] == 1) {
            findPaths(mat, n, x, y - 1, path + "L", paths);
        }
        if (y + 1 < n && mat[x][y + 1] == 1) {
            findPaths(mat, n, x, y + 1, path + "R", paths);
        }
        if (x - 1 >= 0 && mat[x - 1][y] == 1) {
            findPaths(mat, n, x - 1, y, path + "U", paths);
        }
        mat[x][y] = 1;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string> paths;
        int n = mat.size();
        if (mat[0][0] == 0) {
            return paths;
        }
        findPaths(mat, n, 0, 0, "", paths);
        sort(paths.begin(), paths.end());
        return paths;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends