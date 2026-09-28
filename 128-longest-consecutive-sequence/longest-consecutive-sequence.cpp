class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int cnt = 0;
        for(int i =0 ; i<nums.size(); i++){
            if(i==0 || nums[i] == nums[i-1]+1){
                cnt++;
                ans = max(ans, cnt);
            }else if(nums[i]== nums[i-1]){
                continue;
            }else{
                cnt = 1;
            }
        }return ans;
    }
};