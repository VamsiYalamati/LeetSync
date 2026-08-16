class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>> pq;
        int n = grid.size();
        if (grid[0][0] == 1)
            return -1;
       vector<vector<int>> ans(n,vector<int>(n,1e9));
       ans[0][0]=1;
        pq.push({1, 0, 0});
        while (!pq.empty()) {
            auto [distance, row, col] = pq.top();
            pq.pop();
            for (int i = -1; i < 2; i++) {
                for (int j = -1; j < 2; j++) {
                    int newrow = row + i;
                    int newcol = col + j;
                    if (newrow >= 0 && newrow < n && newcol >=0 && newcol < n &&
                        grid[newrow][newcol] == 0) {
                        if (distance + 1 < ans[newrow][newcol]) {
                            ans[newrow][newcol] = distance + 1;
                            pq.push({ans[newrow][newcol], newrow, newcol});
                        }
                    }
                }
            }
        }
        if (ans[n - 1][n - 1] == 1e9)
            return -1;
        else
            return ans[n - 1][n - 1];
    }
};