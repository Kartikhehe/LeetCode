class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //brute force
        //sorting = n log n

        //better appraoch
        //use a priority queue. 
        priority_queue<int> pq;
        for(int i = 0; i< nums.size() ; i++){
            pq.push(nums[i]);
        }

        int answer;

        for(int i = 0; i< k ; i++){
            answer = pq.top();
            pq.pop();
        }

        return answer;
    }
};