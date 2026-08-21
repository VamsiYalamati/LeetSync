class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> first(26, n), last(26, -1);

        // First and last occurrence of each character
        for (int i = 0; i < n; i++) {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = i;
        }

        vector<pair<int, int>> intervals;

        // Build valid interval starting from each first occurrence
        for (int i = 0; i < n; i++) {

            if (i != first[s[i] - 'a'])
                continue;

            int end = last[s[i] - 'a'];
            bool valid = true;

            for (int j = i; j <= end; j++) {

                if (first[s[j] - 'a'] < i) {
                    valid = false;
                    break;
                }

                end = max(end, last[s[j] - 'a']);
            }

            if (valid)
                intervals.push_back({i, end});
        }

        // Sort by ending index
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });

        vector<string> ans;
        int prevEnd = -1;

        // Greedy selection of non-overlapping intervals
        for (auto it : intervals) {
            int start = it.first;
            int end = it.second;

            if (start > prevEnd) {
                ans.push_back(s.substr(start, end - start + 1));
                prevEnd = end;
            }
        }

        return ans;
    }
};