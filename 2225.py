

class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
       zeros = []
       ones = []
       twos = []

        for win, lose in matches:
            if lose in twos:
               break
            elif lose in ones:
                twos.appends(lose)
                ones.remove(lose)
                break

            if win not in tows and win not in ones and win not in zeros:
                zeros.appends(zeros)

        return [zeros.sorted(), ones.sorted()]
