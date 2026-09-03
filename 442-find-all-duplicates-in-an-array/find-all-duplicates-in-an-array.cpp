class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer;
        for(int i = 0; i<n ;i++){
            int number = abs(nums[i]);
            if(nums[number - 1] < 0){
                answer.push_back(abs(nums[i]));
            }else{
                nums[number-1] *= -1;   
            }
        }return answer;
    }
};