class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string answer = "";
        int repeat = 0;
        string prev = "";

        while (a > 0 || b > 0 || c > 0) {
            // Check if 'a' is the best valid choice
            if ((a >= b && a >= c && (repeat < 2 || prev != "a")) ||
                (prev == "b" && repeat == 2 && a >= c && a > 0) ||
                (prev == "c" && repeat == 2 && a >= b && a > 0)) {
                answer += "a"; a--;
                if (prev == "a") { repeat++; }
                else { repeat = 1; prev = "a"; }
            } 
            // Check if 'b' is the best valid choice
            else if ((b >= a && b >= c && (repeat < 2 || prev != "b")) ||
                     (prev == "a" && repeat == 2 && b >= c && b > 0) ||
                     (prev == "c" && repeat == 2 && b >= a && b > 0)) {
                answer += "b"; b--;
                if (prev == "b") { repeat++; }
                else { repeat = 1; prev = "b"; }
            } 
            // Check if 'c' is the best valid choice
            else if ((c >= a && c >= b && (repeat < 2 || prev != "c")) ||
                     (prev == "a" && repeat == 2 && c >= b && c > 0) ||
                     (prev == "b" && repeat == 2 && c >= a && c > 0)) {
                answer += "c"; c--;
                if (prev == "c") { repeat++; }
                else { repeat = 1; prev = "c"; }
            } 
            // Only break when NO valid character can be placed
            else {
                break;
            }
        }
        return answer;
    }
};