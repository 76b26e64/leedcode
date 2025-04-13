class Solution:
    def countPairs(self, nums: List[int]) -> int:
        answer = 0
        n = len(nums)
        for i in range(n):
            for j in range(i+1, n):
                a = nums[i]
                b = nums[j]

                if a == b:
                    answer += 1
                    continue

                diff_count = 0
                a_diff_vals = []
                b_diff_vals = []

                while a > 0 or b > 0 :
                    if a % 10 != b % 10:
                        diff_count += 1
                        a_diff_vals.append(a%10)
                        b_diff_vals.append(b%10)

                    a = int(a/10)
                    b = int(b/10)
                    if diff_count == 4:
                        break

                if diff_count == 0:
                    answer += 1
                elif 2 <= diff_count <= 3:
                    a_diff_vals.sort()
                    b_diff_vals.sort()
                    if a_diff_vals == b_diff_vals and a==b:
                        answer += 1
                elif diff_count == 4:
                    if a_diff_vals[0] == b_diff_vals[1] and a_diff_vals[1] == b_diff_vals[0] and a_diff_vals[2] == b_diff_vals[3] and a_diff_vals[3] == b_diff_vals[2]:
                        if a==b:
                            answer += 1
                    elif a_diff_vals[0] == b_diff_vals[2] and a_diff_vals[2] == b_diff_vals[0] and a_diff_vals[1] == b_diff_vals[3] and a_diff_vals[3] == b_diff_vals[1]:
                        if a==b:
                            answer += 1
                    elif a_diff_vals[0] == b_diff_vals[3] and a_diff_vals[3] == b_diff_vals[0] and a_diff_vals[1] == b_diff_vals[2] and a_diff_vals[2] == b_diff_vals[1]:
                        if a==b:
                            answer += 1

        return answer
