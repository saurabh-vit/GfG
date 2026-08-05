class Solution {
public:
    long long solve(vector<int>& arr, long long x) {
        long long cnt = 0;
        long long sum = 0;
        int st = 0;

        for (int end = 0; end < arr.size(); end++) {
            sum += arr[end];

            while (sum > x) {
                sum -= arr[st];
                st++;
            }

            cnt += (end - st + 1);
        }

        return cnt;
    }

    int countSubarray(vector<int>& arr, int l, int r) {
        return solve(arr, r) - solve(arr, l - 1);
    }
};