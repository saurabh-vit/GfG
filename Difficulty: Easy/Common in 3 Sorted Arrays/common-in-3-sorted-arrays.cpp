class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        // code here
        int i = 0, j = 0, k = 0;
        vector<int> ans;
        while (i < a.size() && j < b.size() && k < c.size()) {
            // If all three are equal
            if (a[i] == b[j] && b[j] == c[k]) {
                // Avoid duplicates in result
                if (ans.empty() || ans.back() != a[i]) {
                    ans.push_back(a[i]);
                }
                i++; j++; k++;
            }
            // Move the pointer with smallest value
            else if (a[i] < b[j]) {
                i++;
            }
            else if (b[j] < c[k]) {
                j++;
            }
            else {
                k++;
            }
        }
        return ans;
    }
};