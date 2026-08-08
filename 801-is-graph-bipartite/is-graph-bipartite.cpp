class Solution {
private:
    bool dfs(vector<vector<int>>& graph, vector<int>& vis, int start,int colour) {
        vis[start] = colour;
        for (auto neigh : graph[start]) {
           if (vis[neigh] == -1) {
                if (dfs(graph, vis, neigh, colour ^ 1) == false) {
                    return false;
                }
            }
            else if (vis[neigh] == colour) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();
        vector<int> vis(n, -1);
        for (int i = 0; i < n; i++) {
            if(vis[i]==-1){
             if(dfs(graph,vis,i,0)==false){
                return false;
             }
            }
        }
        return true;
    }
};