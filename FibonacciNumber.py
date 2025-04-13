class Solution:

    memo = {}

    def fib(self, n: int) -> int:

        if n in self.memo:
            return self.memo[n]

        if n < 2:
            return n
        else:
            answer = self.fib(n-1) + self.fib(n-2) 
            self.memo[n] = answer
            return answer