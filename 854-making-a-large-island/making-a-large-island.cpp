class DisjointSet {
    vector<int> parent, size;

public:

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if(parent[node] == node) {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {

        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) {
            return;
        }

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    int getSize(int node) {
        return size[findParent(node)];
    }
};


class Solution {
public:

    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        DisjointSet ds(n * n);

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Step 1: Create components of existing 1s
        for(int r = 0; r < n; r++) {

            for(int c = 0; c < n; c++) {

                if(grid[r][c] == 0) {
                    continue;
                }

                int node = r * n + c;

                for(int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr >= 0 && nr < n &&
                       nc >= 0 && nc < n &&
                       grid[nr][nc] == 1) {

                        int adjNode = nr * n + nc;

                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }

        int ans = 0;

        // Step 2: Try converting every 0 into 1
        for(int r = 0; r < n; r++) {

            for(int c = 0; c < n; c++) {

                if(grid[r][c] == 1) {
                    continue;
                }

                set<int> components;

                for(int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr >= 0 && nr < n &&
                       nc >= 0 && nc < n &&
                       grid[nr][nc] == 1) {

                        int node = nr * n + nc;

                        components.insert(ds.findParent(node));
                    }
                }

                int currentSize = 1;

                for(auto component : components) {
                    currentSize += ds.getSize(component);
                }

                ans = max(ans, currentSize);
            }
        }

        // Handles the case where there is no 0
        for(int i = 0; i < n * n; i++) {
            ans = max(ans, ds.getSize(i));
        }

        return ans;
    }
};