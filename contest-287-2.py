class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        answer = [[],[]]
        members = [-1] * 100001
            
        for match in matches:
            winner = match[0]
            if members[winner] == -1:
                members[winner] = 0
                
            loser = match[1]
            if members[loser] == -1:
                members[loser] =1
            else:
                members[loser] +=1

        for i in range(100001):
            if members[i] == 0:
                answer[0].append(i) 
            elif members[i] == 1:
                answer[1].append(i) 

        return answer