class Solution {
  public:
    int maxArea(vector<vector<int>> &mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<int> height(cols, 0);
        int maxArea = 0;

        auto largestRectangleArea = [&](vector<int>& heights) {
            stack<int> st;
            int n = heights.size();
            int area = 0;
            for (int i = 0; i <= n; i++) {
                int h = (i == n ? 0 : heights[i]);
                while (!st.empty() && h < heights[st.top()]) {
                    int height = heights[st.top()];
                    st.pop();
                    int width = st.empty() ? i : (i - st.top() - 1);
                    area = max(area, height * width);
                }
                st.push(i);
            }
            return area;
        };

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                height[j] = (mat[i][j] == 0) ? 0 : height[j] + 1;
            }
            maxArea = max(maxArea, largestRectangleArea(height));
        }
        return maxArea;
    }
};