class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        deque<int> dq;
        vector<int> answer;
        for(int i = 0; i< arr.size(); i++){
            int num = arr[i];
            while(dq.empty()==false && arr[dq.front()] <= num){
                dq.pop_front();
            }dq.push_front(i);
            while(dq.back() <= i - k)dq.pop_back();
            if(i>=k-1)answer.push_back(arr[dq.back()]);
        }return answer;
    }
};