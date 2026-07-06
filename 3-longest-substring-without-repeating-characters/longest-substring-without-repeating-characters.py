class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        char_map = {}
        start = 0
        max_length = 0
        
        for end in range(len(s)):
            # If character is found and is within current window
            if s[end] in char_map and char_map[s[end]] >= start:
                start = char_map[s[end]] + 1
            
            # Update/Add character index to map
            char_map[s[end]] = end
            
            # Calculate max length
            max_length = max(max_length, end - start + 1)
            
        return max_length