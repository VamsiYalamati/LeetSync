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
};


class Solution {
public:

    int removeStones(vector<vector<int>>& stones) {

        int maxRow = 0;
        int maxCol = 0;

        for(auto stone : stones) {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }

        int offset = maxRow + 1;

        DisjointSet ds(maxRow + maxCol + 2);

        unordered_set<int> nodes;

        // Connect row with column
        for(auto stone : stones) {

            int row = stone[0];
            int col = stone[1] + offset;

            ds.unionBySize(row, col);

            nodes.insert(row);
            nodes.insert(col);
        }

        // Count components
        int components = 0;

        for(auto node : nodes) {

            if(ds.findParent(node) == node) {
                components++;
            }
        }

        return stones.size() - components;
    }
};