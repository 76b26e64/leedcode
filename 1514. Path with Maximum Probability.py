class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        distances = [0] * n
        distances[start_node] = 1
        for i in range(n-1):
            update = 0
            for j in range(len(edges)):
                u, v = edges[j]
                if distances[u] * succProb[j] > distances[v]:
                    distances[v] = distances[u] * succProb[j]
                    update = 1
                if distances[v] * succProb[j] > distances[u]:
                    distances[u] = distances[v] * succProb[j]
                    update = 1

            if not update:
                break

        return distances[end_node]
