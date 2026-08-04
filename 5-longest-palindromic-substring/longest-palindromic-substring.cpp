class Solution {
public:
    string oddP(string s, int idx){
        int n = s.size();
        int left = idx;
        int right = idx;
        while(left>=0 && right < n && s[left]==s[right]){
            left--;
            right++;
        }

        return s.substr(left+1, right-left-1);
    }

    string evenP(string s, int left, int right){
        int n = s.size();
        while(left>=0 && right < n && s[left]==s[right]){
            left--;
            right++;
        }

        return s.substr(left+1, right-left-1);
    }

    string longestPalindrome(string s) {
        int n = s.size();
        if(n==0)return "";
        string answer = string(1, s[0]);
        for(int i = 0; i< n; i++){
            string tempOdd = oddP(s,i);
            if(tempOdd.size()>answer.size()){
                answer = tempOdd;
            }

            if(i!=n-1 && s[i]==s[i+1]){
                string tempEven = evenP(s, i, i+1);
                if(tempEven.size()>answer.size()){
                    answer = tempEven;
                }
            }
        }return answer;
    }
};