class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int targetidx = n - k + 1;
        priority_queue<int> pq;

        for(int i = 0; i<n-k+1; i++){
            pq.push(nums[i]);
        }

        for(int i = n-k+1; i<n ; i++){
            if(pq.top() > nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top();
        
    }
};