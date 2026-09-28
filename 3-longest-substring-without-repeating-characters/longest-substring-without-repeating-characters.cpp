class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex;
        int maxLen = 0;
        int left = 0; // Left pointer of the sliding window
        
        for (int right = 0; right < s.length(); right++) {
            // If the character is already in the map and falls inside the current window
            if (charIndex.find(s[right]) != charIndex.end() && charIndex[s[right]] >= left) {
                // Move the left pointer just past the last occurrence of the repeated character
                left = charIndex[s[right]] + 1;
            }
            
            // Update the last seen index of the character
            charIndex[s[right]] = right;
            
            // Calculate the maximum length found so far
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};