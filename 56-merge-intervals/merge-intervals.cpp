class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> answer;
        sort(intervals.begin(), intervals.end());
        int tempfirst = -1;
        int templast = -1;
        for(auto it: intervals){
            int start = it[0];
            int end = it[1];
            if(templast>=start && templast!=-1){
                templast = max(end,templast);
            }else{
                if(tempfirst!=-1 && templast!=-1){
                    answer.push_back({tempfirst, templast});
                }tempfirst = start;
                templast = end;
            }
        }if(tempfirst!=-1 && templast!=-1){
            answer.push_back({tempfirst, templast});
        }

        return answer;
    }
};