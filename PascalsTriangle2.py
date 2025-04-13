class Solution:
    def getCurrentRow(self, upperRow, currentIndex, rowIndex: int) -> List[int]:
        ans = [1] * (currentIndex+1)
        upperRowLen = len(upperRow)
        ansLen = len(ans)
        for i in range(ansLen):
            if i == 0:
                ans[i] = upperRow[i]
            elif i == ansLen-1:
                ans[i] = upperRow[i-1]
            else:
                ans[i] = upperRow[i-1] + upperRow[i]
                   

        if currentIndex == rowIndex:
            return ans
        else:
            return self.getCurrentRow(ans, currentIndex + 1, rowIndex)

    def getRow(self, rowIndex: int) -> List[int]:
            ans = [1]
            if rowIndex == 0:
                return ans

            return self.getCurrentRow(ans, 1, rowIndex) 