class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        unordered_set<int> squares;
    
    // Step 1: Store all squares in a set
    for (int num : arr) {
        squares.insert(num * num);
    }

    int n = arr.size();
    
    // Step 2: Check all unique pairs (a, b)
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int a2 = arr[i] * arr[i];
            int b2 = arr[j] * arr[j];
            int sum = a2 + b2;

            // Check if the sum is present as c²
            if (squares.find(sum) != squares.end()) {
                return true;
            }
        }
    }

    return false;
    }
};