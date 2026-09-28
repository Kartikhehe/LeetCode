class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        for(int i = 0; i<nums.size(); i++){
            if(i!=0 && nums[i] == nums[i-1])continue;
            if(nums[i]>0)break;
            int first = i;
            int second = i+1;
            int third = nums.size()-1;
            int negation = -1 * nums[i];
            while(third > second){
                int rest = nums[second] + nums[third];
                if(rest == negation){
                    answer.push_back({nums[first], nums[second], nums[third]});
                    while(third> 0 && nums[third] == nums[third-1]){
                        third--;
                    }third--;
                    while(second< nums.size()-1 && nums[second] == nums[second+1]){
                        second++;
                    }second++;
                }else if(rest < negation){
                    second++;
                    continue;
                }else{
                    third--;
                    continue;
                }
            }
        }return answer;
    }
};