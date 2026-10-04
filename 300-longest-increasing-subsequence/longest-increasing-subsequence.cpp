class Solution {
    int longestsubseq(vector<int> &nums, int idx, int limitidx, vector<vector<int>> &dp){
        
        int n = nums.size();
        if(idx == n-1){
            return (limitidx!=-1 && nums[limitidx] >= nums[n-1]) ? 0: 1;
        }

        if(limitidx!=-1 && dp[idx][limitidx]!=-1)return dp[idx][limitidx];
        
        //pick
        int pick = INT_MIN;
        if(limitidx ==-1 || nums[idx] > nums[limitidx])pick= longestsubseq(nums, idx+1, idx,dp);
        // not pick
        int notpick = longestsubseq(nums, idx+1, limitidx, dp);
        if(limitidx!=-1)dp[idx][limitidx] = max(pick + 1, notpick);
        return max(pick + 1, notpick);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return longestsubseq(nums, 0, -1, dp);

        //smallest number should be more than the INT_MIN here
    }
};