class Solution {
    int splitSubarrays(vector<int>& nums, int largestSum){
        int answer = 1;
        int temp = 0;
        for(int i = 0; i<nums.size(); i++){
            temp += nums[i];
            if(temp > largestSum){
                temp = nums[i];
                answer++;
            }
        }return answer;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(),nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        int answer = right;
        while(left <= right){
            int mid = (right - left)/2 + left;
            int split = splitSubarrays(nums, mid); //largest sum of subarray are left and right
            if(split <= k){
                answer = min(answer, mid);
                right = mid - 1;
            }else {
                
                  left = mid + 1;
            }
        }return answer;
    }
};