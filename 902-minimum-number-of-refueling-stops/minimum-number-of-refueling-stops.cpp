class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int current = startFuel;
        priority_queue<int> pq;
        int curridx = 0;
        int count = 0;
        while(current < target){
            while(curridx < stations.size() && stations[curridx][0] <= current){
                pq.push(stations[curridx][1]);
                curridx++;
            }if(pq.empty())return -1;
            current += pq.top(); pq.pop();
            count++;
        }return count;
    }
};