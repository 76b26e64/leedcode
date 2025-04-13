from re import A


class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        elif n == 2:
            return 2
        else:
            before_2 = 1
            before_1 = 2
            while i <= n:
                answer = before_1 + before_2
                before_2 = before_1
                before_1 = answer
                i += 1

            return answer
    """
    memo = {}
    def climbStair(self, current, n: int) -> int:
        if current == n:
            return self.memo[n-1] + self.memo[n-2]
        
        self.memo[n] = self.memo[n-1] + self.memo[n-2]
        return self.climbStair(current + 1, n)
    
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        elif == 2:
            return 2
        else:
            self.memo[1] = 1 
            self.memo[2] = 2 
            return self.climbStair(3, n)
    """
    
    """ 
    def climbStairs(self, n: int) -> int:
        ans = 0
        two_steps_max = n // 2
        for two_steps_num in range(two_steps_max+1):
            one_steps_num = n - (two_steps_num * 2)
            ans += math.factorial(one_steps_num + two_steps_num) // (math.factorial(one_steps_num) * math.factorial(two_steps_num))
            
        return ans   
    """ 