class Solution {
public:
    vector<string> ans;

    vector<string> keypad = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void solve(string &digits, string &output, int index){

        if(index == digits.size()){
            ans.push_back(output);
            return;
        }

        string letters = keypad[digits[index]-'0'];

        for(char ch : letters){

            output.push_back(ch);

            solve(digits, output, index+1);

            output.pop_back();      // Backtracking
        }
    }

    vector<string> letterCombinations(string digits){

        if(digits.empty()) return {};

        string output="";

        solve(digits, output, 0);

        return ans;
    }
};