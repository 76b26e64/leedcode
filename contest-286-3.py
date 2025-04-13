"""
2217. Find Palindrome With Fixed Length
User Accepted:2490
User Tried:4228
Total Accepted:2602
Total Submissions:11727
Difficulty:Medium
Given an integer array queries and a positive integer intLength, return an array answer where answer[i] is either the queries[i]th smallest positive palindrome of length intLength or -1 if no such palindrome exists.

A palindrome is a number that reads the same backwards and forwards. Palindromes cannot have leading zeros.

 

Example 1:

Input: queries = [1,2,3,4,5,90], intLength = 3
Output: [101,111,121,131,141,999]
Explanation:
The first few palindromes of length 3 are:
101, 111, 121, 131, 141, 151, 161, 171, 181, 191, 201, ...
The 90th palindrome of length 3 is 999.
Example 2:

Input: queries = [2,4,6], intLength = 4
Output: [1111,1331,1551]
Explanation:
The first six palindromes of length 4 are:
1001, 1111, 1221, 1331, 1441, and 1551.
 

Constraints:

1 <= queries.length <= 5 * 104
1 <= queries[i] <= 109
1 <= intLength <= 15
"""

class Solution:
    def kthPalindrome(self, queries: List[int], intLength: int) -> List[int]:
        answer = [] 
        for index in queries:
            if (intLength % 2) != 0:
                intLenHalf = int((intLength+1) // 2)
            else:
                intLenHalf = int(intLength // 2)

            if intLenHalf == 1:
                min = 1
                palindrome_num = 9
            else:
                min = (10 ** (intLenHalf-1))
                palindrome_num = 9 * (10 ** (intLenHalf-1))

            if index > palindrome_num:
                answer.append(-1)
                continue
            
            upper = min + index-1
            
            if (intLength % 2) != 0:
                tmp = int(upper // 10)
                rev_str = str(tmp)[::-1]
                answer.append((upper * (10 ** (intLenHalf-1))) + int(rev_str)) 
            else:
                tmp = upper
                rev_str = str(tmp)[::-1]
                answer.append((upper * (10 ** (intLenHalf))) + int(rev_str)) 
                

        return answer
"""
class Solution:
    def kthPalindrome(self, queries: List[int], intLength: int) -> List[int]:
        answer = [] 

        for index in queries:
            if (intLength % 2) == 0:
                intLenHalf = int(intLength / 2)
                
                palindrome_num = 9 * (10 ** (intLenHalf - 1))
                
                if index > palindrome_num:
                    answer.append(-1)
                    continue

                index -= 1
                palindrome_X = 10 ** (intLenHalf - 1) + index
                tmp_str = str(palindrome_X)
                rev_str = tmp_str[::-1]
                answer.append((palindrome_X * (10 ** (intLenHalf))) + int(rev_str)) 

            else:
                intLenHalf = int((intLength-1) / 2)
                palindrome_num = 9 * (10 ** (intLenHalf))
                
                if index > palindrome_num:
                    answer.append(-1)
                    continue
               
                if intLength != 1:
                    index -= 1
                palindrome_X = 10 ** (intLenHalf - 1) + index
                index_1 = int(index % 10)
                index_2 = int(index // 10)
            
                palindrome_X = int(10 ** (intLenHalf - 1)) + index_2
                tmp_str = str(palindrome_X)
                rev_str = tmp_str[::-1]
                ans_up  = (palindrome_X * (10 ** (intLenHalf+1))) 
                ans_mid = (index_1 * (10 ** (intLenHalf))) 
                ans_low = int(rev_str)
                
                ans = int(ans_up + ans_mid + ans_low)
                answer.append(ans) 

        return answer       
"""