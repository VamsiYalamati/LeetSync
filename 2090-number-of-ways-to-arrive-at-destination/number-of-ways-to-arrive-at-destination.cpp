class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adjlist(n);
        for (auto it : roads) {
            adjlist[it[0]].push_back({it[1], it[2]});
            adjlist[it[1]].push_back({it[0], it[2]});
        }
        vector<long long> ans(n, 1e18), visit(n, 0);
        ans[0] = 0;
        visit[0] = 1;
        priority_queue<tuple<long long, int>, vector<tuple<long long, int>>,
                       greater<tuple<long long, int>>>
            pq;
        pq.push({0, 0});
        // distance,source
        while (!pq.empty()) {
            auto [distance, node] = pq.top();
            pq.pop();
            if (distance > ans[node])
                continue;
            for (auto it : adjlist[node]) {
                if (distance + it.second < ans[it.first]) {
                    ans[it.first] = distance + it.second;
                    visit[it.first] = visit[node];
                    pq.push({distance + it.second, it.first});
                } else if (distance + it.second == ans[it.first]) {
                    visit[it.first] =
                        (visit[it.first] + visit[node]) % 1000000007;
                }
            }
        }
        return visit[n - 1];
    }
};