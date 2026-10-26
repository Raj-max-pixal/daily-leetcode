from collections import Counter
from typing import List

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not s or not words:
            return []
        
        word_len = len(words[0])
        num_words = len(words)
        total_len = word_len * num_words
        word_count = Counter(words)
        result = []
        
        # Iterate over each possible offset to handle all alignments
        for i in range(word_len):
            left = i
            right = i
            current_count = Counter()
            matched_words = 0
            
            while right + word_len <= len(s):
                # Extract the next word from the right end of the window
                word = s[right:right + word_len]
                right += word_len
                
                if word in word_count:
                    current_count[word] += 1
                    matched_words += 1
                    
                    # If we have too many instances of this word, shrink from the left
                    while current_count[word] > word_count[word]:
                        left_word = s[left:left + word_len]
                        current_count[left_word] -= 1
                        matched_words -= 1
                        left += word_len
                        
                    # If the number of matched words equals total words, we found a valid starting index
                    if matched_words == num_words:
                        result.append(left)
                else:
                    # Reset the window if the word is not in the words list
                    current_count.clear()
                    matched_words = 0
                    left = right
                    
        return result