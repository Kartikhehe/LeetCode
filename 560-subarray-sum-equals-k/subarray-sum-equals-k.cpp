class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int sum = 0;
        int answer = 0;
        mpp[0] = 1;
        for(int i =0; i<nums.size(); i++){
            sum += nums[i];
            int target = sum - k;
            answer += mpp[target];
            if(mpp.find(sum)==mpp.end()){
                mpp[sum] = 1;
            }else{
                mpp[sum]++;
            }
        }
        return answer;
    }
};