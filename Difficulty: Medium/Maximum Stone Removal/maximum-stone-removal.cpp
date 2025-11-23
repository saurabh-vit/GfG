class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones) {
        // Code here
        unordered_map<int, int> parent;
        function<int(int)> find = [&](int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        };
        auto unite = [&](int a, int b) {
            int pa = find(a);
            int pb = find(b);
            if (pa != pb) parent[pb] = pa;
        };
        // Initialize DSU for each row and column
        for (auto &s : stones) {
            int row = s[0];
            int col = s[1] + 10001;   // shift columns to avoid collision with rows
            if (!parent.count(row)) parent[row] = row;
            if (!parent.count(col)) parent[col] = col;
            unite(row, col); // connect row to column
        }
        unordered_set<int> components;
        for (auto &s : stones) {
            int root = find(s[0]);
            components.insert(root);
        }
        return stones.size() - components.size();
    }
};