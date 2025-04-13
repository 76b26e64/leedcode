class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        visited = [0 for _ in range(len(isConnected))]
        visit = []
        province = 0
        for i in range(len(isConnected)):
            if visited[i] == 0:
                visit.append(i)
                province += 1
                visited[i] = 1

            while visit:
                node = visit.pop()
                for city, connect in enumerate(isConnected[node]):
                    if connect == 1 and visited[city] == 0:
                        visit.append(city)
                        visited[city] = 1

        return province
