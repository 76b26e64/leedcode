from sortedcontainers import SortedList

class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        def create_hash(x, y):
            return x+(y*100000)

        hashmap = set()
        for ob in obstacles:
            hashmap.add(create_hash(ob[0], ob[1]))

        forward = [(0, 1), (1,0), (0, -1), (-1, 0)]
        direction = 0
        x = y = 0
        answer = 0
        for command in commands:
            if command == -2:
                direction = (direction + 3) % 4
                continue
            elif command == -1:
                direction = (direction + 1) % 4
                continue

            dx, dy = forward[direction]
            for _ in range(command):
                next_x, next_y = x + dx, y + dy
                if create_hash(next_x, next_y) in hashmap:
                    break
                x, y = next_x, next_y
                answer = max(answer, (x ** 2) + (y ** 2))

        return answer
