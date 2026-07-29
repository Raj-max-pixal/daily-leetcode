class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return ""

        start = 0
        end = 0

        # Helper function to expand outwards from a given left and right center
        def expand_around_center(left: int, right: int) -> int:
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            # Return the length of the palindrome found
            return right - left - 1

        for i in range(len(s)):
            # Find longest odd-length palindrome centered at i
            len1 = expand_around_center(i, i)
            
            # Find longest even-length palindrome centered between i and i+1
            len2 = expand_around_center(i, i + 1)
            
            # Take the maximum of the two lengths
            max_len = max(len1, len2)

            # If we found a longer palindrome, update the global start and end pointers
            if max_len > end - start:
                start = i - (max_len - 1) // 2
                end = i + max_len // 2

        # Extract and return the longest palindromic substring
        return s[start:end + 1]