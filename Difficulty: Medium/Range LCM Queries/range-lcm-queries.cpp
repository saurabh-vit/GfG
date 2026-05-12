class Solution {
    long long gcd(long long a, long long b) {
        while (b) {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    vector<long long> seg;

    void build(int idx, int l, int r, vector<int>& arr) {
        if (l == r) {
            seg[idx] = arr[l];
            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx + 1, l, mid, arr);
        build(2 * idx + 2, mid + 1, r, arr);

        seg[idx] = lcm(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    void update(int idx, int l, int r, int pos, int val) {
        if (l == r) {
            seg[idx] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(2 * idx + 1, l, mid, pos, val);
        else
            update(2 * idx + 2, mid + 1, r, pos, val);

        seg[idx] = lcm(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    long long query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return 1;

        if (ql <= l && r <= qr)
            return seg[idx];

        int mid = (l + r) / 2;

        long long left = query(2 * idx + 1, l, mid, ql, qr);
        long long right = query(2 * idx + 2, mid + 1, r, ql, qr);

        return lcm(left, right);
    }

  public:
    vector<long long> RangeLCMQuery(vector<int> &arr, vector<vector<int>> &queries) {
        
        int n = arr.size();

        seg.resize(4 * n);

        build(0, 0, n - 1, arr);

        vector<long long> ans;

        for (auto &q : queries) {

            if (q[0] == 1) {

                int index = q[1];
                int value = q[2];

                update(0, 0, n - 1, index, value);
            }
            else {

                int L = q[1];
                int R = q[2];

                ans.push_back(query(0, 0, n - 1, L, R));
            }
        }

        return ans;
    }
};