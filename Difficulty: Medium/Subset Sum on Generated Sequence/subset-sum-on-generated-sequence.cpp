class Solution {
  public:
    bool isPossible(vector<int>& arr, int s, int x) {
        // code here
        vector<long long> nums;

        long long total = s;

        nums.push_back(s);

        for (int a : arr) {
            long long next = total + a;

            if (next > x) {
                break;
            }

            nums.push_back(next);
            total += next;
        }

        long long rem = x;

        // Greedy from largest to smallest
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] <= rem) {
                rem -= nums[i];
            }

            if (rem == 0)
                return true;
        }

        return false;
    }
};