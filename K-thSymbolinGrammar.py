class Solution:

    memo = 0

    def helper(self, n: int, k: int, x: int):

        if (2 ** n-1) < k <= (2 ** n):
            answer = answer





        if n == x:
            ans = "0" + bin(self.memo)[2:]
            return int(ans[k-1])

        self.memo = self.memo << x | ((~self.memo + (1 << (x-1))) & (1 << x) - 1)
        return self.helper(n, k, x+1)

    """    
    def kthGrammar(self, n: int, k: int) -> int:
        if k == 1:
            return 0

        row_len = 2 ** (n-1)
        flip = 0
        while row_len > 1:
            row_len_half = row_len / 2
            if k > row_len_half:
                k -= row_len_half 
                flip += 1

            if k == 1:
                break                
            
            row_len = row_len_half

        if (flip % 2) == 0:
            return 0
        else:
            return 1   
    """    
    def kthGrammar(self, n: int, k: int) -> int:
        if k == 1:
            return 0

        row_len = 2 ** (n-1)
        flip = 0
        while row_len > 1:
            row_len_half = row_len / 2
            if k > row_len_half:
                k -= row_len_half 
                flip += 1

            if k == 1:
                break                
            
            row_len = row_len_half

        if (flip % 2) == 0:
            return 0
        else:
            return 1  

    def kthGrammar(self, n: int, k: int) -> int:
        if n == 1:
            return 0

        row_len_half = (2 ** (n-1)) / 2
        if k > row_len_half:
            k -= row_len_half 
            ret = 1 if self.kthGrammar(n-1, k) == 0 else 0
        else:
            ret = 1 if self.kthGrammar(n-1, k) == 1 else 0
        
        return ret