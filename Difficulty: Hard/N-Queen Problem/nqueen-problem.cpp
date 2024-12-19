//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solveNQueensHelper(int n, int row, vector<int>& board, set<int>& cols, set<int>& diagonals1, set<int>& diagonals2, vector<vector<int>>& results) {
        if (row == n) {
            results.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (cols.count(col) || diagonals1.count(row - col) || diagonals2.count(row + col)) {
                continue;
            }
            board[row] = col + 1;
            cols.insert(col);
            diagonals1.insert(row - col);
            diagonals2.insert(row + col);
            solveNQueensHelper(n, row + 1, board, cols, diagonals1, diagonals2, results);
            board[row] = 0;
            cols.erase(col);
            diagonals1.erase(row - col);
            diagonals2.erase(row + col);
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> results;
        vector<int> board(n, 0);
        set<int> cols;
        set<int> diagonals1;
        set<int> diagonals2;
        solveNQueensHelper(n, 0, board, cols, diagonals1, diagonals2, results);
        return results;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends