class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        answer = 0
        islands_queue = deque()
        for x in range(len(grid2)):
            for y in range(len(grid2[0])):
                if grid2[x][y] == 1:
                    grid2[x][y] = 0
                    islands_queue.append((x, y))
                    subisland = True
                    while islands_queue:
                        xx, yy = islands_queue.popleft()
                        if grid1[xx][yy] == 0:
                            subisland = False
                        for xx, yy in ((xx-1, yy), (xx+1, yy), (xx, yy-1), (xx, yy+1)):
                            if 0 <= xx <= len(grid2)-1 and  0 <= yy <= len(grid2[0])-1 and grid2[xx][yy] == 1:
                                # キューに格納する前に訪問済にしないと、重複する可能性がある
                                grid2[xx][yy] = 0
                                islands_queue.append((xx, yy))
                    if subisland == True:
                        answer += 1
        return answer
