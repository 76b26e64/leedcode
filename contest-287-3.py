"""
class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        candies_total = sum(candies)
        if k > candies_total:
            return 0 
        elif k == candies_total:
            return 1

        answer = 0
        max_answer = int(candies_total // k)

        candies_sorted = sorted(candies, reverse=True)

        for answer in reversed(range(1, max_answer+1)):
            pile = 0
            for candie in candies_sorted:
                if candie < answer:
                    break

                pile += int(candie // answer)

                if pile >= k:
                    return answer

        return 0

class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:

        candies_total = sum(candies)
        if k > candies_total:
            return 0 
        elif k == candies_total:
            return 1

        candies_num_list = [0] * 10000000
        valid_num_indexs = []
        for candie in candies:
            candies_num_list[candie] += 1
            if not candie in valid_num_indexs:
                valid_num_indexs.append(candie)

        answer = 0
        max_answer = int(candies_total // k)
        valid_num_indexs.sort(reverse=True)

        for answer in reversed(range(1, max_answer+1)):
            pile = 0
            for i in valid_num_indexs:
                if i < answer:
                    break
                pile += int((candies_num_list[i] * i) // answer)
                if pile >= k:
                    return answer

        return 0

class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        candies_total = sum(candies)
        if k > candies_total:
            return 0 
        elif k == candies_total:
            return 1

        left = 0
        right = int(candies_total // k)

        while left < right:
            middle = int((left + right + 1) // 2)
            cnt = 0
            for candie in candies:
                cnt += int(candie // middle)
            
            if cnt >= k:
                left = middle
            else:
                right = middle -1

        return left
"""

def binarySearchTest():
    target = 74
    #target = 73

    #left<right, right=middle-1 middle=(left+right)//2  Not finished
    #print("left<right, middle=(left+right)//2")
    #left<right, right=middle-1 middle=(left+right)//2  done
    #print("left<right, right=middle-1 middle=(left+right+1)//2")
    left = 1
    right = 100
    count = 0
    while left < right:
        count += 1
        middle = int((left + right) // 2)
        #middle = int((left + right +1) // 2)
        print("try:" + str(count) + " left=" + str(left) + " right=" + str(right) + " middle=" + str(middle))
        if middle == target:
            print("Found")
            break
        elif middle < target:
            left = middle
        else:
            #right = middle-1
            right = middle

    return 0

def devideTest():
    print("101/2="+ str(101/2))
    print("101//2="+ str(101//2))
    print("int(101/2)="+ str(int(101/2)))
    print("int(101//2)="+ str(int(101//2)))

devideTest()


#binarySearchTest()
