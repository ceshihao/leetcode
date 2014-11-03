class Solution:
    # @return an integer
    def reverse(self, x):
        result = 0
        if x < 0:
            flag = -1
            x *= -1
        else:
            flag = 1
        
        while x !=0:
            result = result * 10 + (x % 10)
            x /= 10
        
        INT_MAX = 2147483647
        INT_MIN = -2147483648
        if result * flag > INT_MAX:
            return INT_MAX
        elif result * flag < INT_MIN:
            return INT_MIN
        else:
            return result * flag