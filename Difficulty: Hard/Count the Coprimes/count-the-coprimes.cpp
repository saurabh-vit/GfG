class Solution {
public:
    int cntCoprime(vector<int>& arr) {
        int mx = *max_element(arr.begin(), arr.end());
        vector<int> cnt(mx + 1), div(mx + 1), mu(mx + 1, 1);
        vector<bool> vis(mx + 1);
        
        for (int x : arr) cnt[x]++;

        for (int i = 1; i <= mx; ++i)
            for (int j = i; j <= mx; j += i)
                div[i] += cnt[j];

        for (int i = 2; i <= mx; ++i) {
            if (!vis[i]) {
                for (int j = i; j <= mx; j += i) {
                    mu[j] *= -1;
                    vis[j] = 1;
                }
                for (long long j = (long long)i * i; j <= mx; j += (long long)i * i)
                    mu[j] = 0;
            }
        }

        int ans = 0;
        for (int i = 1; i <= mx; ++i)
            if (mu[i] && div[i] > 1)
                ans += mu[i] * div[i] * (div[i] - 1) / 2;
        
        return ans;
    }
};