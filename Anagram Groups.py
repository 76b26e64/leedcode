class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = defaultdict(list)
        for word in strs:
            tmpstr = ''.join(sorted(word))
            anagrams[tmpstr].append(word)

        return anagrams.values()
