class Solution {
  public:
    vector<int> nextPalindrome(vector<int>& num) {
        int n = num.size();

        // ✅ FIX: Handle all 9s case
        bool all9 = true;
        for (int x : num) {
            if (x != 9) {
                all9 = false;
                break;
            }
        }
        if (all9) {
            vector<int> res(n + 1, 0);
            res[0] = 1;
            res[n] = 1;
            return res;
        }

        vector<int> res = num;

        int mid = n / 2;
        int i = mid - 1;
        int j = (n % 2) ? mid + 1 : mid;

        bool leftSmaller = false;

        // Step 1: Check if left < right
        while (i >= 0 && res[i] == res[j]) {
            i--;
            j++;
        }

        if (i < 0 || res[i] < res[j]) {
            leftSmaller = true;
        }

        // Step 2: Mirror left → right
        while (i >= 0) {
            res[j] = res[i];
            i--;
            j++;
        }

        // Step 3: If already greater
        if (!leftSmaller) return res;

        // Step 4: Add carry
        int carry = 1;
        i = mid - 1;

        if (n % 2 == 1) {
            res[mid] += carry;
            carry = res[mid] / 10;
            res[mid] %= 10;
            j = mid + 1;
        } else {
            j = mid;
        }

        while (i >= 0 && carry) {
            res[i] += carry;
            carry = res[i] / 10;
            res[i] %= 10;
            res[j] = res[i];
            i--;
            j++;
        }

        return res;
    }
};