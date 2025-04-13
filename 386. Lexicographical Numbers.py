class Solution:
    def lexicalOrder(self, n: int) -> List[int]:

        answer= []
        def dfs(number):
            if number > n:
                return
            for i in range(10):
                if 1 <= number+i <=n :
                    answer.append(number+i)
                    dfs((number+i)*10)
            return

        dfs(0)
        return answer
