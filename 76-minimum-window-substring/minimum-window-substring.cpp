class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        if (m < n) return "";

        vector<int> mpp(128, 0);
        int required = 0;

        for (char c : t) {
            if (mpp[c] == 0) required++;
            mpp[c]++;
        }

        int left = 0, right = 0;
        int minLen = INT_MAX;
        int startIdx = 0;

        while (right < m) {
            char rightChar = s[right];
            mpp[rightChar]--;
            if (mpp[rightChar] == 0) {
                required--;
            }

            while (required == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                char leftChar = s[left];
                mpp[leftChar]++;
                if (mpp[leftChar] > 0) {
                    required++;
                }
                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};