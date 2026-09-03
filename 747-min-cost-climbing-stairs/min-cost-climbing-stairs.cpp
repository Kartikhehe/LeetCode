class Solution {
public:
    int solution(vector<int>& cost, vector<int>& dp, int idx){
        int n = cost.size();
        if(idx == n-1)return 0;
        if(idx == n-2)return min(cost[n-1], cost[n-2]);

        if(dp[idx]!=-1)return dp[idx];

        return dp[idx] = min(cost[idx] + solution(cost, dp, idx+1), cost[idx+1] + solution(cost, dp, idx + 2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        return solution(cost, dp, 0);
    }
};