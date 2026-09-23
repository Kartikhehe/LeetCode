#include <vector>
#include <algorithm>

class Solution {
public:
    int maxCoins(std::vector<int>& nums) {
        int n = nums.size();
        
        // Pad array with 1 at both boundaries
        std::vector<int> padded(n + 2, 1);
        for (int i = 0; i < n; i++) {
            padded[i + 1] = nums[i];
        }

        // dp[i][j] stores max coins from bursting balloons in interval (i, j)
        std::vector<std::vector<int>> dp(n + 2, std::vector<int>(n + 2, 0));

        // len is the length of the interval
        for (int len = 1; len <= n; ++len) {
            for (int left = 1; left <= n - len + 1; ++left) {
                int right = left + len - 1;
                
                // k is the LAST balloon to burst in interval [left, right]
                for (int k = left; k <= right; ++k) {
                    int coins = padded[left - 1] * padded[k] * padded[right + 1];
                    coins += dp[left][k - 1] + dp[k + 1][right];
                    
                    dp[left][right] = std::max(dp[left][right], coins);
                }
            }
        }

        return dp[1][n];
    }
};