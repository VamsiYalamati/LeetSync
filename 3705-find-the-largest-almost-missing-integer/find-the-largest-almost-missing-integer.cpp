class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int> count(51, 0);
        int n = nums.size();
        for (int i = 0; i <=n - k; i++) {
            unordered_set<int> st;
            for (int j = i; j < i + k; j++) {
                st.insert(nums[j]);
            }
            for (auto it : st) {
                count[it]++;
            }
        }
        int ans=-1;
        for(int i=0;i<=50;i++){
            if(count[i]==1){
                ans=i;
            }
        }
        return ans;
    }
};