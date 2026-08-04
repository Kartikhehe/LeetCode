class Solution {
public:
    string solution(string s, int index){
        string word = "";
        if(index==s.size())return word;
        int i = index;
        while(i<s.size() && s[i]==' ')i++;
        for( ; i<s.size();i++){
            if(s[i]==' '){
                break;
            }
            word += s[i];
        }

        string first = solution(s,i);
        if(first.empty())return word;
        return first + " " + word;
    }


    string reverseWords(string s) {
        return solution(s, 0);
    }
};