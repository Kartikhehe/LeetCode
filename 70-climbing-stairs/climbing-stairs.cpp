class Solution {
public:

    // int climbStairs1(int n, vector<int>&dp) {
    //     if(n==1)return 1;
    //     if(n==2)return 2;
    //     if(dp[n]!=-1)return dp[n];
    //     return dp[n] = climbStairs1(n-1,dp) + (climbStairs1(n-2,dp));
    // }

    int climbStairs(int n) {
        if(n==2)return 2;
        if(n==1)return 1;
        vector<int> dp(n+1, -1);
        
        int prev2 = 1; 
        int prev1 = 2;
        int curr = prev2;
        for(int i = 3; i<=n;i++){
            curr = prev2 + prev1;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};