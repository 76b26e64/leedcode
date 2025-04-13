class Solution:
    def maxScore(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])

        if rows == 1:
            return max(grid[0])

        values_set = set([grid[r][c] for r in range(rows) for c in range(cols)])
        values_list = sorted(list(values_set))[::-1]
        values_rows = defaultdict(list)

        for value in values_list:
            values_rows[value] = [r for r in range(rows) if value in grid[r]]

        def select_number(rows, remains, score):
            if not remains:
                return score

            val = remains[0]
            remains = remains[1:]
            score_list = []

            for row in values_rows[val]:
                if row in rows:
                    score_list.append(select_number(rows | {row}, remains, score+val))

            if not score_list:
                score_list.append(select_number(rows, remains, score))

            return max(score_list)

        return select_number(set(), values_list, 0)
