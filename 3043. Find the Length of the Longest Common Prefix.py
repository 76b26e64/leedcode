class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        set1 = DefaultDict(set)
        set2 = DefaultDict(set)
        max_lens = [0,0]

        for arrs, sets in [(arr1, set1), (arr2, set2)]:
            for arr in arrs:
                while arr > 0:
                    sets[len(str(arr))].add(arr)
                    arr //= 10

        max_len = min(max(set1.keys()), max(set2.keys()))
        for l in range(max_len, 0, -1):
            if set1[l] & set2[l]:
                return l

        return 0
