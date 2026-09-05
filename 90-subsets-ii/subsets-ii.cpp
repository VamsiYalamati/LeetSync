class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, vector<int>& subset, int index) {

        ans.push_back(subset);

        for(int i = index; i < nums.size(); i++) {

            // Skip duplicates at same level
            if(i > index && nums[i] == nums[i-1])
                continue;

            subset.push_back(nums[i]);

            solve(nums, subset, i + 1);

            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> subset;

        solve(nums, subset, 0);

        return ans;
    }
};