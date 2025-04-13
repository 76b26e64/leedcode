class Solution:
    def findTheLongestSubstring(self, s: str) -> int:

        current_count = [0] * 5
        max_length = 0

        for left in range(len(s)):
            current_count = [0] * 5
            for right in range(left, len(s)):
                if s[right] == "a":
                    current_count[0] += 1
                elif s[right] == "i":
                    current_count[1] += 1
                elif s[right] == "u":
                    current_count[2] += 1
                elif s[right] == "e":
                    current_count[3] += 1
                elif s[right] == "o":
                    current_count[4] += 1

                if current_count[0] % 2 == 0 and current_count[1] % 2 == 0 and current_count[2] % 2 == 0 and current_count[3] % 2 == 0 and current_count[4] % 2 == 0:
                    max_length = max(max_length, right-left+1)

        return max_length
