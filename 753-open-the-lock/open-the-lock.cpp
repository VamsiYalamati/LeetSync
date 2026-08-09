class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        if (dead.count("0000")) {
            return -1;
        }
        string start = "0000";
        queue<string> q;
        q.push(start);
visited.insert(start);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string curr = q.front();
                q.pop();
                if (curr == target) {
                    return level;
                }
                for (int i = 0; i < 4; i++) {
                    string next = curr;
                    next[i] = (next[i] - '0' + 1) % 10 + '0';
                    if (dead.find(next)==dead.end() && visited.find(next)==visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                    next = curr;
                    next[i] = (next[i] - '0' + 9) % 10 + '0';
                    if (dead.find(next)==dead.end()&& visited.find(next)==visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }level++;
        }
        return -1;
    }
};