class Solution:
    # @return an integer
    def atoi(self, str):
        result = 0
        flag = 1
        if len(str) == 0:
            return result
        
        while str[0] == " ":
            str = str[1:len(str)]
        
        if len(str) == 0:
            return result
        elif str[0] == "-":
            flag = -1
            str = str[1:len(str)]
        elif str[0] == "+":
            flag = 1
            str = str[1:len(str)]
        elif str[0] in ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]:
            flag = 1
        else:
            return result
        
        for w in str:
            if str[0] not in ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]:
                break
            result = result * 10 + int(str[0])
            str = str[1:len(str)]
        INT_MAX = 2147483647
        INT_MIN = -2147483648
        if result * flag > INT_MAX:
            return INT_MAX
        elif result * flag < INT_MIN:
            return INT_MIN
        else:
            return result * flag