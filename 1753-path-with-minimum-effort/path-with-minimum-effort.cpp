class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        using P = pair<int, pair<int, int>>;
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> dist(rows, vector<int>(cols, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            int effort = current.first;
            int row = current.second.first;
            int col = current.second.second;
            if (row == rows - 1 && col == cols - 1) {
                return effort;
            }
            int dx[4] = {-1, 0, 1, 0};
            int dy[4] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int n_row = dx[i] + row;
                int n_col = dy[i] + col;
                if (n_row >= 0 && n_row < rows && n_col >= 0 && n_col < cols) {
                    int newEffort = abs(heights[n_row][n_col] - heights[row][col]);
                    newEffort = max(effort, newEffort);
                    if (newEffort < dist[n_row][n_col]) {
                        dist[n_row][n_col] = newEffort;
                        pq.push({newEffort, {n_row, n_col}});
                    }
                }
            }
        }
        return -1;
    }
};