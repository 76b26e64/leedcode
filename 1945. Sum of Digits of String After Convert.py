class Solution:
    def getLucky(self, s: str, k: int) -> int:
        convert_s = ""
        for c in s:
            convert_s += str(ord(c)-ord("a")+ 1)

        total = 0
        for _ in range(k):
            total = 0
            for c in convert_s:
                total += int(c)
            convert_s = str(total)

        return total
