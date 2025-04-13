class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        max_value = 0
        max_length = 0
        current_length = 0

        for i in range(len(nums)):
            if nums[i] > max_value:
                max_value = nums[i]
                current_length = 1
                max_length = 1
            elif nums[i] == max_value:
                current_length += 1
                max_length = max(max_length, current_length)
            else:
                current_length = 0

        return max_length
