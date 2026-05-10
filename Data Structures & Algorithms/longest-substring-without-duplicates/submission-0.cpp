class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Use an array for faster lookup than unordered_map
        vector<int> lastSeen(128, -1); 
        int max_len = 0, start = 0;

        for (int end = 0; end < s.size(); end++) {
            // If char was seen, move 'start' to the right of the previous occurrence
            if (lastSeen[s[end]] >= start) {
                start = lastSeen[s[end]] + 1;
            }
            // Update last seen position and calculate length
            lastSeen[s[end]] = end;
            max_len = max(max_len, end - start + 1);
        }
        return max_len;
    }
};