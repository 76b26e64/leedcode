#217. Contains Duplicate

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        vals = set()
        for num in nums:
            if num in vals:
                return True
            else:
                vals.add(num)

        return False
