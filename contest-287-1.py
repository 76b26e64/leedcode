from gc import collect


class Solution:
    def convertTime(self, current: str, correct: str) -> int:

        answer = 0
        current_list = current.split(':')
        correct_list = correct.split(':')

        current_hour = int(current_list[0])
        current_min = int(current_list[1])
        correct_hour = int(correct_list[0])
        correct_min = int(correct_list[1])

        if correct_min < current_min: 
            current_hour += 1
            correct_min += 60

        if correct_min > current_min:
            diff_min = correct_min - current_min
            if diff_min >= 45:
                   current_min += 45
                   answer += 3

            diff_min = correct_min - current_min
            if 45 > diff_min >= 30:
                   current_min += 30
                   answer += 2
            
            diff_min = correct_min - current_min
            if 30 > diff_min >= 15:
                   current_min += 15
                   answer += 1

            diff_min = correct_min - current_min
            if 15 > diff_min >= 10:
                   current_min += 10
                   answer += 2

            diff_min = correct_min - current_min
            if 10 > diff_min >= 5:
                   current_min += 5
                   answer += 1
            
            diff_min = correct_min - current_min
            if 5 > diff_min >= 1:
                   answer += diff_min

        if correct_hour > current_hour:
            answer += correct_hour - current_hour

        elif correct_hour < current_hour: 
            correct_hour += 24
            answer += correct_hour - current_hour

        return answer