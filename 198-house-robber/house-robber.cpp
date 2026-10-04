class Solution {
    int robmoney(vector<int> & nums, int idx, vector<int> &dp){

        if(idx >= nums.size()){
            return 0;
        }

        if(dp[idx] != -1)return dp[idx];

        //pick
        int pick = nums[idx] + robmoney(nums, idx + 2,dp);
        //not pick
        int notpick = robmoney(nums, idx + 1, dp);


        return dp[idx] = max(pick, notpick);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return robmoney(nums, 0, dp);
    }
};