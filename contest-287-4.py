class Encrypter:
class Encrypter:
    g_dictionary = []
    g_encrypts = {}

    def __init__(self, keys: List[str], values: List[str], dictionary: List[str]):
        self.g_dictionary = dictionary

        for i in range(len(keys)):
            self.g_encrypts[keys[i]] = values[i]
        

    def encrypt(self, word1: str) -> str:
        ret = ""
        for c in word1:
            ret += self.g_encrypts[c]
        
        return ret

    def decrypt(self, word2: str) -> int:
        ret = 0
        for word in self.g_dictionary:
            enc = self.encrypt(word)
            if enc == word2:
                ret += 1

        return ret
    