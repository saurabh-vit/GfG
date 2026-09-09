class Solution {
  public:
    int findMax(int n) {
        string s = to_string(n);
        int ans = n;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0')
                continue;

            string temp = s;

            // Decrease current digit by 1
            temp[i]--;

            // Make all digits after it 9
            for (int j = i + 1; j < s.size(); j++) {
                temp[j] = '9';
            }

            int num = stoi(temp);

            if (digitSum(num) > digitSum(ans) ||
                (digitSum(num) == digitSum(ans) && num > ans)) {
                ans = num;
            }
        }

        return ans;
    }

    int digitSum(int n) {
        int sum = 0;

        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }
};