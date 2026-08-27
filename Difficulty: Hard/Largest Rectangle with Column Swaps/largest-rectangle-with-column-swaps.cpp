class Solution {
public:
    int maxArea(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> height(m, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {

            // Calculate consecutive 1s ending at row i
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1)
                    height[j]++;
                else
                    height[j] = 0;
            }

            // Sort column heights
            vector<int> temp = height;
            sort(temp.begin(), temp.end());

            // Try every possible width
            for (int j = 0; j < m; j++) {
                int width = m - j;
                int area = temp[j] * width;
                ans = max(ans, area);
            }
        }

        return ans;
    }
};