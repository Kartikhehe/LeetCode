class Solution {
public:
    int paths(int x, int y, int m, int n, vector<vector<int>> &dp){
        if(x==m-1 || y==n-1)return 1;
        if(dp[x][y]!=-1)return dp[x][y];
        return dp[x][y] = paths(x+1, y, m,n,dp) + paths(x, y+1, m, n,dp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return paths(0,0, m, n, dp);

    }
};