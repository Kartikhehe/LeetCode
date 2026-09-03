class Solution {
    char choosechar(char ch1, char ch2){
        if(ch1=='a' || ch2 == 'a' ){
            if(ch1=='b' || ch2 == 'b' ){
                return 'c';
            }else{
                return 'b';
            }
        }else{
            return 'a';
        }return 'a';
    }

public:
    string modifyString(string s) {
        if(s[0]=='?'){s[0] = s.size()==1 ? 'a' : (s[1]=='a' ? 'b' : 'a'); }
        for(int i = 1; i< s.size()-1; i++){
            if(s[i]=='?'){
                s[i] = choosechar(s[i-1], s[i+1]);
             }
        }
        if(s[s.size()-1]== '?'){
            s[s.size()-1] = choosechar(s[s.size()-2], '?');
        }
        return s;
    }
};