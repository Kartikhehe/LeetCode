class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        //range is 1 to n;
         sort(nums.begin(),nums.end());
         int temp = -1;
         for(auto it: nums){
            if(temp == it){
                return it;
            }temp = it;
         }return temp;
    }
};