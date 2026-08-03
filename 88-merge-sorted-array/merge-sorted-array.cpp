class Solution {
public:
    void insertion(vector<int>& nums, int x,  vector<int> &idx, int sizee){
        int index = idx[0];
        while(index<sizee && nums[index] <= x){
            index++;
        }// now, nums[index] > x
        for(int i = nums.size()-1; i>= index + 1; i--){
            nums[i] = nums[i-1];
        }nums[index] = x;
        idx[0] = index;
        return;
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr = 0;
        vector<int> idx = {0};
        for(int i = 0;i<n;i++){
            insertion(nums1, nums2[i], idx, m + i);
        }

        return;
    }
};