class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        answer = []
        prefix_xor = [0] * (len(arr)+1)

        for i in range(len(arr)):
            prefix_xor[i+1] = prefix_xor[i] ^ arr[i]

        for n in range(len(queries)):
            i, j = queries[n]
            answer.append(prefix_xor[j+1] ^ prefix_xor[i])

        return answer
