class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        // code here
        set<int> disallowed(arr.begin(), arr.end());
    
        // Create a list of allowed digits
        vector<int> allowedDigits;
        for (int d = 0; d <= 9; d++) {
            if (disallowed.find(d) == disallowed.end()) {
                allowedDigits.push_back(d);
            }
        }
        
        // Calculate total n-digit numbers
        long long total = 0;
        if (n == 1) {
            total = 9;
        } else {
            total = 9 * pow(10, n - 1);
        }
        
        // Calculate numbers without any arr[] digit
        long long withoutArr = 0;
        int allowedSize = allowedDigits.size();
        
        // If no allowed digits remain, all numbers include arr[] digits
        if (allowedSize == 0) {
            return total;
        }
        
        // First digit cannot be 0
        int firstDigitOptions = 0;
        for (int d : allowedDigits) {
            if (d != 0) {
                firstDigitOptions++;
            }
        }
        
        if (n == 1) {
            withoutArr = firstDigitOptions;
        } else {
            withoutArr = firstDigitOptions * pow(allowedSize, n - 1);
        }
        
        // Numbers containing at least one digit from arr[] = total - withoutArr
        return total - withoutArr;
    }
};
