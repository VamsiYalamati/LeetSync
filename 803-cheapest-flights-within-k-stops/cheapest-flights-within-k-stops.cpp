class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adjlist(n);
        for (auto it : flights) {
            adjlist[it[0]].push_back({it[1], it[2]});
        }
        queue<tuple<int, int, int>> q;
        q.push({0, src,0});
        vector<int> ans(n, 1e9);
        ans[src]=0;
        while (!q.empty()) {
            auto [stop,node,dist]=q.front();
            q.pop();
            if(stop>k)continue;
            for(auto it:adjlist[node]){
                int adjnode=it.first;
                int dis=it.second;
                if(dist+dis<ans[adjnode]){
                    ans[adjnode]=dist+dis;
                    q.push({stop+1,adjnode,ans[adjnode]});
                }
            }
        }
        if (ans[dst] == 1e9)
            return -1;
        else
            return ans[dst];
    }
};