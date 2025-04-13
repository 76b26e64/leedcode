#624. Maximum Distance in Arrays

class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        min1 = arrays[0][0]
        max1 = arrays[0][-1]
        answer = -float('inf')

        for arr in arrays:
            answer = max(answer, max(max1-arr[0],arr[-1]-min1))
            min1 = min(min1,arr[0])
            max1 = max(max1,arr[-1])

        return answer
