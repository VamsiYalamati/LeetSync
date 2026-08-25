class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> freq(26, 0);
        vector<int> ans;

        // Store frequency of pattern
        for (char ch : p) {
            freq[ch - 'a']++;
        }

        int left = 0, right = 0;
        int count = p.size();

        while (right < s.size()) {

            // Current character enters the window
            if (freq[s[right] - 'a'] > 0)
                count--;

            freq[s[right] - 'a']--;

            // Window size becomes equal to pattern size
            if (right - left + 1 == p.size()) {

                // Found an anagram
                if (count == 0)
                    ans.push_back(left);

                // Remove left character from window
                freq[s[left] - 'a']++;

                if (freq[s[left] - 'a'] > 0)
                    count++;

                left++;
            }

            right++;
        }

        return ans;
    }
};