class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:

        timePoints_int = []
        for time in timePoints:
            timePoints_int.append((int(time[0:2]) * 60) + int(time[3:5]))

        timePoints_int.sort()
        timePoints_int.append(timePoints_int[0] + 1440)

        min_diff = float('inf')
        for i in range(1, len(timePoints_int)):
            min_diff = min(min_diff, timePoints_int[i] - timePoints_int[i-1])

        return min_diff
