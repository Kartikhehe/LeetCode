class Solution {
public:
    int maxProfit(vector<int>& p) {
        int r=0;for(int i=1;i<(int)p.size();i++)if(p[i]>p[i-1])r+=p[i]-p[i-1];return r;
    }
};