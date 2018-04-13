class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int res = 0, m = matrix.size(), n = matrix[0].size();
        vector<int> height(n + 1, 0);
        for (int i = 0; i < m; ++i) {
            stack<int> s;
            for (int j = 0; j < n + 1; ++j) {
                if (j < n) {
                    height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
                }
                while (!s.empty() && height[s.top()] >= height[j]) {
                    int cur = s.top(); s.pop();
                    res = max(res, height[cur] * (s.empty() ? j : (j - s.top() - 1)));
                }
                s.push(j);
            }
        }
        return res;
    }
};
