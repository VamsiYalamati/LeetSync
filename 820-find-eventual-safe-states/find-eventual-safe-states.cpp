class Solution {
private:
    bool dfs(vector<vector<int>>& graph,
             vector<int>& vis,
             vector<int>& pathvis,
             vector<int>& safe,
             int node) {

        vis[node] = 1;
        pathvis[node] = 1;

        for (auto it : graph[node]) {

            if (!vis[it]) {

                if (dfs(graph, vis, pathvis, safe, it))
                    return true;
            }
            else if (pathvis[it]) {
                return true;
            }
        }

        pathvis[node] = 0;

        // This node doesn't lead to a cycle
        safe[node] = 1;

        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> vis(n, 0);
        vector<int> pathvis(n, 0);
        vector<int> safe(n, 0);

        for (int i = 0; i < n; i++) {

            if (!vis[i]) {
                dfs(graph, vis, pathvis, safe, i);
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (safe[i] == 1) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};