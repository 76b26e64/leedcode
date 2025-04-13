from sortedcontainers import SortedList
class Solution:
    def resultsArray(self, queries: List[List[int]], k: int) -> List[int]:
        answer = []
        distances = SortedList()
        for i in range(len(queries)):
            distance = abs(queries[i][0]) + abs(queries[i][1])
            distances.add(distance)
            if i < k-1:
                answer.append(-1)
            else:
                answer.append(distances[k-1])

        return answer
