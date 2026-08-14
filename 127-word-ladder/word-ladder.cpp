class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        unordered_set<string> mp(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        while(!q.empty()){
            auto [word,dis]=q.front();
            q.pop();
            if(word==endWord)return dis;
            for(int i=0;i<word.size();i++){
                string original=word;
                for(char j='a';j<='z';j++){
                    original[i]=j;
                 if(mp.find(original)!=mp.end()){
                    q.push({original,dis+1});
                    mp.erase(original);
                 }
                }
            }
        }
        return 0;
    }
};