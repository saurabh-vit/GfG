class Solution {
public:
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        function<int(int)> find = [&](int x) {
            if (parent[x] == x)
                return x;
            return parent[x] = find(parent[x]);
        };

        int extra = 0;

        for (auto &e : edges) {
            int u = find(e[0]);
            int v = find(e[1]);

            if (u == v) {
                extra++;
            } else {
                parent[u] = v;
            }
        }

        int components = 0;

        for (int i = 0; i < n; i++) {
            if (find(i) == i)
                components++;
        }

        int needed = components - 1;

        if (extra >= needed)
            return needed;

        return -1;
    }
};