class Solution {
private:
    bool dfs(int node, vector<vector<int>>& adj,
             vector<int>& vis, vector<int>& ans) {

        // Currently being visited -> cycle found
        if (vis[node] == 1)
            return false;

        // Already completely processed
        if (vis[node] == 2)
            return true;

        // Mark as currently visiting
        vis[node] = 1;

        for (auto neigh : adj[node]) {
            if (!dfs(neigh, adj, vis, ans))
                return false;
        }

        // Completely processed
        vis[node] = 2;
        ans.push_back(node);

        return true;
    }

public:
    vector<int> findOrder(int numCourses,
                          vector<vector<int>>& prerequisites) {

        vector<vector<int>> adjlist(numCourses);

        // prerequisite = [course, prerequisite]
        for (auto pre : prerequisites) {
            int a = pre[1];
            int b = pre[0];

            adjlist[a].push_back(b);
        }

        vector<int> vis(numCourses, 0);
        vector<int> ans;

        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                if (!dfs(i, adjlist, vis, ans))
                    return {};
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};