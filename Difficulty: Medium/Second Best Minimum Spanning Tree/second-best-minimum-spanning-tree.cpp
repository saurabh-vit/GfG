#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    struct DSU {
        vector<int> p, r;
        DSU(int n): p(n), r(n,0) { for(int i=0;i<n;i++) p[i]=i; }
        int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
        bool unite(int a,int b){
            a=find(a); b=find(b);
            if(a==b) return false;
            if(r[a]<r[b]) swap(a,b);
            p[b]=a;
            if(r[a]==r[b]) r[a]++;
            return true;
        }
    };

    int secondMST(int V, vector<vector<int>> &edges) {
        int E = edges.size();
        if (V <= 1) return -1;

        // Prepare sorted edges (u, v, w, orig_index)
        vector<array<int,4>> ed;
        ed.reserve(E);
        for (int i = 0; i < E; ++i)
            ed.push_back({edges[i][0], edges[i][1], edges[i][2], i});
        sort(ed.begin(), ed.end(), [](const auto &a, const auto &b){
            if (a[2] != b[2]) return a[2] < b[2];
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] < b[1];
        });

        // Kruskal: build one MST and mark used edges by sorted-index
        DSU dsu(V);
        vector<bool> used_in_sorted(E, false);
        vector<vector<pair<int,int>>> mstAdj(V);
        long long mst_weight = 0;
        int taken = 0;
        for (int i = 0; i < E && taken < V-1; ++i) {
            int u = ed[i][0], v = ed[i][1], w = ed[i][2];
            if (dsu.unite(u, v)) {
                used_in_sorted[i] = true;
                mstAdj[u].push_back({v, w});
                mstAdj[v].push_back({u, w});
                mst_weight += w;
                ++taken;
            }
        }
        if (taken != V-1) return -1; // graph not connected

        // Helper: find path from a -> b in MST and return vector of edge weights on that path.
        // We'll use BFS (or DFS) since V <= 100, O(V) per query is fine.
        auto getPathEdgeWeights = [&](int a, int b) {
            vector<int> parent(V, -1), pedge(V, 0);
            queue<int> q;
            q.push(a);
            parent[a] = a; // root marker
            while (!q.empty() && parent[b] == -1) {
                int u = q.front(); q.pop();
                for (auto &pr : mstAdj[u]) {
                    int v = pr.first, w = pr.second;
                    if (parent[v] == -1) {
                        parent[v] = u;
                        pedge[v] = w;
                        q.push(v);
                    }
                }
            }
            vector<int> pathEdges;
            if (parent[b] == -1) return pathEdges; // not connected (shouldn't happen)
            int cur = b;
            while (cur != a) {
                pathEdges.push_back(pedge[cur]);
                cur = parent[cur];
            }
            return pathEdges; // weights along path from b->a (order not important)
        };

        // For each non-MST edge, consider removing each edge on the resulting cycle
        long long second_best = LLONG_MAX;
        for (int i = 0; i < E; ++i) {
            if (used_in_sorted[i]) continue; // skip edges already in this MST
            int u = ed[i][0], v = ed[i][1], w = ed[i][2];
            vector<int> pathEdgeWeights = getPathEdgeWeights(u, v);
            if (pathEdgeWeights.empty()) continue; // shouldn't happen in connected MST
            // Try removing each edge on the path
            for (int w_on_path : pathEdgeWeights) {
                long long cand = mst_weight - w_on_path + w;
                if (cand > mst_weight && cand < second_best) second_best = cand;
            }
        }

        if (second_best == LLONG_MAX) return -1;
        return (int) second_best;
    }
};
