class Solution:
    def nearestPalindromic(self, n: str) -> str:

        digits = len(n)
        number = int(n)

        if number <= 9:
            #1桁の時は -1の値が答え
            return str(number - 1)
        if number == (10 ** (digits-1)) or number == (10 ** (digits-1))+1:
            #100 or 101の時は 99が答え
            return str((10 ** (digits-1))-1)
        if number == (10 ** (digits-1))-1:
            #99.. の時は101が答え
            return str(10 ** (digits-1)+1)

        center_digit = digits // 2  #中心の桁数
        if digits % 2 == 0:
            #偶数桁 は2桁の考え
            high = int(n[center_digit])
        else:
            #奇数桁 は3桁の考え
            high = int(n[center_digit-1])

        low = int(n[center_digit+1])
        n_list = list(n)
        #繰上げの確認
        if abs(high - low) >= abs(10+high-low):
            # 繰上げ処理
            #ToDo 繰上げ時の上位の桁数が９の時を考慮しなければならない
            if n_list[center_digit] == "9":
                if abs(high - low) != abs(10+high-low)+1:
                    #繰上げ分の値を+1する必要があり、それにより差分が等しくなる場合は、何もしない
                    for i in range(center_digit-1, -1, -1):
                        n_list[i] = str(int(n_list[i])+1)
                        if n_list[i] != "10":
                            break
                        else:
                            n_list[i] = "0":


            n_list[center_digit] = str(int(n_list[center_digit])+1)

        if digits % 2 == 0:
            for i in range(1, center_digit+1):
                n_list[center_digit+i] = n_list[center_digit-(i-1)]
        else:
            for i in range(center_digit+1):
                n_list[center_digit+i] = n_list[center_digit-i]

        ret = ""
        for c in n_list:
            ret += c

        return ret
