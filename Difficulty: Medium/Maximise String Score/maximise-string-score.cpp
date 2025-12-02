class Solution {
  public:
    int maxScore(std::string &s, std::vector<std::vector<char>> &jumps) {
        using ll = long long;
        const int n = (int)s.size();
        if (n <= 1) return 0;

        std::array<int, 256> charIdx; 
        charIdx.fill(-1);
        std::vector<unsigned char> chars; 
        for (unsigned char c : s) {
            if (charIdx[c] == -1) {
                charIdx[c] = (int)chars.size();
                chars.push_back(c);
            }
        }
        const int m = (int)chars.size();

        std::array<std::vector<unsigned char>, 256> go;
        static bool seen[256][256];
        for (int i = 0; i < 256; i++) 
            for (int j = 0; j < 256; j++) 
                seen[i][j] = false;
        
        for (auto &p : jumps) {
            if (p.size() < 2) continue;
            unsigned char a = (unsigned char)p[0];
            unsigned char b = (unsigned char)p[1];
            if (!seen[a][b]) {
                go[a].push_back(b);
                seen[a][b] = true;
            }
        }

        std::vector<ll> pref(n+1, 0);
        for (int i = 0; i < n; i++) pref[i+1] = pref[i] + (int)(unsigned char)s[i];

        std::vector<std::vector<int>> freq(m, std::vector<int>(n+1, 0));
        for (int i = 0; i < n; ++i) {
            int ci = charIdx[(unsigned char)s[i]];
            for (int k = 0; k < m; ++k) freq[k][i+1] = freq[k][i];
            freq[ci][i+1] = freq[ci][i] + 1;
        }

        const int INF = 1e9;
        std::vector<std::vector<int>> nextPos(n+1, std::vector<int>(m, INF));
        for (int c = 0; c < m; ++c) nextPos[n][c] = INF;
        for (int i = n - 1; i >= 0; --i) {
            nextPos[i] = nextPos[i+1];
            int ci = charIdx[(unsigned char)s[i]];
            nextPos[i][ci] = i;
        }

        auto calcScore = [&](int i, int j) -> ll {
            unsigned char t = (unsigned char)s[j];
            int tidx = charIdx[t];
            ll total = pref[j] - pref[i];
            ll cnt   = freq[tidx][j] - freq[tidx][i];
            return total - cnt * (ll)t;
        };

        std::vector<ll> dp(n, 0);
        for (int i = n - 1; i >= 0; --i) {
            ll best = 0;
            unsigned char c1 = (unsigned char)s[i];
            int c1idx = charIdx[c1];

            int j_same = nextPos[i+1][c1idx];
            if (j_same != INF) 
                best = std::max(best, calcScore(i, j_same) + dp[j_same]);

            for (unsigned char c2 : go[c1]) {
                int c2idx = charIdx[c2];
                if (c2idx == -1) continue;
                int j = nextPos[i+1][c2idx];
                if (j != INF)
                    best = std::max(best, calcScore(i, j) + dp[j]);
            }

            dp[i] = best;
        }

        return (int)dp[0];
    }
};
