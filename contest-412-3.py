class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        for _ in range(k):
            index = nums.index(min(nums))
            nums[index] *= multiplier
            nums[index] %= 1000000007

        return nums
