class Solution {
  public:
    vector<int> constructArr(vector<int>& arr) {
        using ll = long long;
        int m = arr.size();

        // m = n*(n-1)/2  => solve for n
        int n = (1 + sqrt(1 + 8LL * m)) / 2;

        // n = 1 -> no sums, return any size-1 array
        if (n <= 1) return {1};

        // n = 2 -> single sum s = a0 + a1; choose any split, e.g., {1, s-1}
        if (n == 2) return {1, (int)(arr[0] - 1)};

        // Use the order:
        // arr[0] = a0+a1, arr[1] = a0+a2, ... arr[n-2] = a0+a(n-1), arr[n-1] = a1+a2
        ll S1 = arr[0];       // a0 + a1
        ll S2 = arr[1];       // a0 + a2
        ll S3 = arr[n - 1];   // a1 + a2   (first element of second block)

        ll a0 = (S1 + S2 - S3) / 2;  // guaranteed integer if input is valid

        vector<int> res(n);
        res[0] = (int)a0;
        // For i>=1: arr[i-1] = a0 + ai  => ai = arr[i-1] - a0
        for (int i = 1; i < n; ++i) {
            res[i] = (int)((ll)arr[i - 1] - a0);
        }
        return res;
    }
};