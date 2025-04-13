class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:

        destinations_dict = defaultdict(list)
        for start, end in tickets:
            destinations_dict[start].append(end)

        for destinations in destinations_dict:
            destinations.sort()


        answer = []

        def dfs(start):
            answer.append(start)
            dfs(destinations_dict[start].pop(0))
        
        dfs("JFK")
        return answer