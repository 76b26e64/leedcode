class Solution:
    def checkTwoChessboards(self, coordinate1: str, coordinate2: str) -> bool:
        c11 = ord(coordinate1[0]) % 2
        c12 = int(coordinate1[1]) % 2
        c21 = ord(coordinate2[0]) % 2
        c22 = int(coordinate2[1]) % 2

        if c11 == c21:
            if c12 == c22:
                return True
            else:
                return False
        else:
            if c12 == c22:
                return False
            else:
                return True
