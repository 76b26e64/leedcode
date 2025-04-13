class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        distances = []

        for i in range(len(nums)-1):
            for j in range(i+1, len(nums)):
                distance = abs(nums[i]-nums[j])
                insort_left(distances, distance)

        return distances[k-1]
