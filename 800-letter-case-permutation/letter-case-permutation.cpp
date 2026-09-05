class Solution {
public:
    vector<string> ans;

    void solve(string &s, string output, int index) {

        // Base Case
        if(index == s.size()) {
            ans.push_back(output);
            return;
        }

        // Digit -> only one choice
        if(isdigit(s[index])) {
            solve(s, output + s[index], index + 1);
        }

        // Letter -> two choices
        else {

            // Lowercase
            solve(s, output + (char)tolower(s[index]), index + 1);

            // Uppercase
            solve(s, output + (char)toupper(s[index]), index + 1);
        }
    }

    vector<string> letterCasePermutation(string s) {

        solve(s, "", 0);

        return ans;
    }
};