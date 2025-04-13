class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        num = len(original)
        if num != (m*n):
            return []

        answer = []
        i = 0
        for mm in range(m):
            answer.append(original[i:i+n])
            i += n
        return answer
