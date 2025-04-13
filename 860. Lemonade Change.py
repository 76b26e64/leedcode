class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        bill_counter = [0] * 3

        for payment in bills:
            if payment == 5:
                bill_counter[0] += 1
            elif payment == 10:
                bill_counter[1] += 1
                bill_counter[0] -= 1
                if bill_counter[0] < 0:
                    return False
            else:
                #$20
                bill_counter[2] += 1
                if bill_counter[1] >= 1:
                    bill_counter[1] -= 1
                    bill_counter[0] -= 1
                    if bill_counter[0] < 0:
                        return False
                else:
                    bill_counter[0] -= 3
                    if bill_counter[0] < 0:
                        return False

        return True
