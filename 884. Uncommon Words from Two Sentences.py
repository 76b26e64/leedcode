class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        l1 = s1.split(' ')
        l2 = s2.split(' ')
        l = l1 + l2
        answer = []
        remove = []

        for word in l:
            if not word in remove:
                if word in answer:
                    answer.remove(word)
                    remove.append(word)
                else:
                    answer.append(word)

        return answer
