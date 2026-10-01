class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        for(int i = 0; i<n ;i++){
            int asteroid = asteroids[i];
            bool broken = false;
            if(asteroid < 0 && !st.empty()){
                while(st.empty()==false){
                    int topmost = st.top();
                    if(topmost<0)break;
                    if(topmost > abs(asteroid)){
                        broken = true;
                        break;
                    }else if(topmost < abs(asteroid)){
                        st.pop();
                    }else {
                        broken = true;
                        st.pop();
                        break;
                    }
                }
            }if(!broken)st.push(asteroid);
        }

        vector<int> answer;
        while(st.empty()==false){
            answer.push_back(st.top());
            st.pop();
        }

        reverse(answer.begin(), answer.end());
        return answer;


    }
};