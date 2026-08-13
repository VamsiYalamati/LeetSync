class Solution {
private:
    void dfs(int row, int col,
             vector<vector<int>>& vis,
             vector<vector<char>>& board,
             int dx[], int dy[]) {

        int n = board.size();
        int m = board[0].size();

        vis[row][col] = 1;

        for (int i = 0; i < 4; i++) {

            int newrow = row + dx[i];
            int newcol = col + dy[i];

            if (newrow >= 0 && newrow < n &&
                newcol >= 0 && newcol < m &&
                board[newrow][newcol] == 'O' &&
                vis[newrow][newcol] == 0) {

                dfs(newrow, newcol, vis, board, dx, dy);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        // Start DFS from boundary O's
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {

                    if (board[i][j] == 'O' &&
                        vis[i][j] == 0) {

                        dfs(i, j, vis, board, dx, dy);
                    }
                }
            }
        }

        // Flip surrounded O's
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (board[i][j] == 'O' && vis[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};