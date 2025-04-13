class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:

        if not stones:
            return 0

        n = len(stones)
        if n == 1:
            return 0

        same_stones = [[] for _ in range(n)]
        for i in range(len(stones)):
            for j in range(i+1, len(stones)):
                if (stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]):
                    same_stones[i].append(j)
                    same_stones[j].append(i)

        visited = [False] * n
        def dfs(stone):
            visited[stone] = True
            for neighbor in same_stones[stone]:
                if not visited[neighbor]:
                    dfs(neighbor)

        connected_components = 0
        for i in range(n):
            if not visited[i]:
                dfs(i)
                connected_components += 1

        return n - connected_components
