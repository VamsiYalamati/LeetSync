class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;
    unordered_set<string> st;
    string beginWord;

    void dfs(string word, vector<string>& path) {

        if (word == beginWord) {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        for (auto& p : parent[word]) {
            path.push_back(p);
            dfs(p, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {

        this->beginWord = beginWord;

        st = unordered_set<string>(
            wordList.begin(),
            wordList.end()
        );

        if (st.find(endWord) == st.end()) {
            return {};
        }

        st.erase(beginWord);

        queue<string> q;
        q.push(beginWord);

        bool found = false;

        while (!q.empty() && !found) {

            int size = q.size();

            unordered_set<string> usedThisLevel;

            for (int k = 0; k < size; k++) {

                string current = q.front();
                q.pop();

                string word = current;

                for (int i = 0; i < word.size(); i++) {

                    char original = word[i];

                    for (char c = 'a'; c <= 'z'; c++) {

                        if (c == original)
                            continue;

                        word[i] = c;

                        if (st.find(word) != st.end()) {

                            // current -> word
                            parent[word].push_back(current);

                            // First time discovering word
                            if (usedThisLevel.find(word) ==
                                usedThisLevel.end()) {

                                usedThisLevel.insert(word);
                                q.push(word);
                            }

                            if (word == endWord) {
                                found = true;
                            }
                        }
                    }

                    word[i] = original;
                }
            }

            // Remove only after the complete level
            for (auto& word : usedThisLevel) {
                st.erase(word);
            }
        }

        vector<string> path;
        path.push_back(endWord);

        dfs(endWord, path);

        return ans;
    }
};