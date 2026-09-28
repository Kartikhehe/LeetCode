class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        int c1=0,c2=0,e1=INT_MIN,e2=INT_MIN;
        for(int x:a){
            if(x==e1)c1++;
            else if(x==e2)c2++;
            else if(!c1){e1=x;c1=1;}
            else if(!c2){e2=x;c2=1;}
            else{c1--;c2--;}
        }
        c1=count(a.begin(),a.end(),e1); c2=count(a.begin(),a.end(),e2);
        vector<int> res;
        if(c1>a.size()/3)res.push_back(e1);
        if(c2>a.size()/3)res.push_back(e2);
        return res;

    }
};