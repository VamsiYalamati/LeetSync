class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>& ans,vector<int>& set,int ind,int n){
        if(ind==n){
            ans.push_back(set);
            return;
        }
        set.push_back(nums[ind]);
        solve(nums,ans,set,ind+1,n);
        set.pop_back();
        solve(nums,ans,set,ind+1,n);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> set;
        solve( nums,ans,set,0,n);
        return ans;
    }
};