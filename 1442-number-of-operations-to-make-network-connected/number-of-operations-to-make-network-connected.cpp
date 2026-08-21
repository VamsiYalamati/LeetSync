class disjointset {
    vector<int> parent, rank;

public:
    disjointset(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i < n + 1; i++) {
            parent[i] = i;
        }
    }
    int findparent(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findparent(parent[node]);
    }
    void unionofnodes(int v, int u) {
        int upv = findparent(v);
        int upu = findparent(u);
        if (upv == upu) {
            return;
        } else if (rank[upv] == rank[upu]) {
            parent[upu] = upv;
            rank[upv]++;
        } else if (rank[upv] < rank[upu]) {
            parent[upv] = upu;
        } else if (rank[upv] > rank[upu]) {
            parent[upu] = upv;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        disjointset ds(n);
        int extraconnections = 0; 
            for (auto it : connections) {
                int adjnode = it[1];
                int node = it[0];
                if (ds.findparent(node) == ds.findparent(adjnode)) {
                    extraconnections++;
                }
                ds.unionofnodes(node, adjnode);
            }
        
        int components = 0;
        for (int i = 0; i <n; i++) {
            if (ds.findparent(i) ==i) {
                components++;
            }
        }
        if (extraconnections >=components - 1) {
            return components - 1;
        }
        else return -1;
    }
};