class Solution:
    def findLength(self, nums1: List[int], nums2: List[int]) -> int:

        n1 = len(nums1)
        n2 = len(nums2)
        memo = [[0] * (n2+1) for _ in range(n1+1)]

        answer = 0
        for i1 in range(n1-1, -1, -1):
            for i2 in range(n2-1, -1, -1):
                if nums1[i1] == nums2[i2]:
                    memo[i1][i2] = memo[i1+1][i2+1] + 1
                else:
                    memo[i1][i2] = 0
            answer = max(answer, max(memo[i1]))

        return answer
