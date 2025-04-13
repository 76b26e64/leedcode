class Solution:
    def countVowelPermutation(self, n: int) -> int:
        vowels = ["a", "e", "i", "o", "u"]
        enables = ["e", "ai", "aeou", "iu", "a"]
        l = len(vowels)
        memo = [[0] * l for _ in range(n)]

        for i in range(l):
            memo[0][i] = 1

        for i in range(1, n):
            for j in range(l):
                for k in range(l):
                    if vowels[k] in enables[j]:
                        memo[i][k] += memo[i-1][j]
                        memo[i][k] %= 1000000007

        answer = 0
        for i in range(l):
            answer += memo[n-1][i]
            answer %= 1000000007

        return answer
