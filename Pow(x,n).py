class Solution:
    memo = 1
    def __init__(self):
        sys.setrecursionlimit(2147483647)
    
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return self.memo
        elif n > 0:
            self.memo *= x 
            return self.myPow(x, n-1)
        else:
            self.memo /= x 
            return self.myPow(x, n+1)