class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;
        int temp = 0;
        for(int i = 0; i < nums.size(); i++){
            temp += nums[i];
             maxsum = max(maxsum, temp);
            if(temp<0){temp = 0;}
           
        }return maxsum;
    }
};