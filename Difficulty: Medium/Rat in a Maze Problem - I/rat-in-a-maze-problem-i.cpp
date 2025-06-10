class Solution {
  public:
    vector<string> result;
    void solve(vector<vector<int>>& maze, int n, int r, int c, string path, vector<vector<bool>> visited){
        if(r<0 || r>=n || c<0 || c>=n){
            return;
        }
        if(maze[r][c]==0 || visited[r][c]){
            return;
        }
        if(r==n-1 && c==n-1){
            result.push_back(path);
            return;
        }
        visited[r][c] = true;
        solve(maze, n, r + 1, c, path + 'D', visited);
        solve(maze, n, r, c - 1, path + 'L', visited);
        solve(maze, n, r, c + 1, path + 'R', visited);
        solve(maze, n, r - 1, c, path + 'U', visited);
        visited[r][c] = false;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        result.clear();
        int n = maze.size();
        if(n==0){
            return {};
        }
        if(maze[0][0]==0){
            return {};
        }
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        solve(maze, n, 0, 0, "", visited);
        sort(result.begin(), result.end());
        return result;
    }
};