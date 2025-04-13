class Solution:
    def countPairs(self, nums: List[int]) -> int:
        answer = 0
        n = len(nums)
        for i in range(n):
            a = nums[i]
            for j in range(i+1, n):
                b = nums[j]

                if a == b:
                    answer += 1
                    continue

                a_digits = list(str(a))
                b_digits = list(str(b))

                diff_digit_len = abs(len(a_digits) - len(b_digits))
                if diff_digit_len != 0:
                    if len(a_digits) > len(b_digits):
                        b_digits = (['0'] * diff_digit_len) + b_digits
                    else:
                        a_digits = (['0'] * diff_digit_len) + a_digits

                diff_count = 0
                diff_indexs = []
                for k in range(len(a_digits)):
                    if a_digits[k] != b_digits[k]:
                        diff_count += 1
                        diff_indexs.append(k)

                if diff_count == 0:
                    answer += 1
                elif diff_count == 2:
                    if a_digits[diff_indexs[0]] == b_digits[diff_indexs[1]] and a_digits[diff_indexs[1]] == b_digits[diff_indexs[0]]:
                        answer += 1

        return answer
