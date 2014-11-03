class Solution:
    # @param x, a float
    # @param n, a integer
    # @return a float
    def pow(self, x, n):
        if n == 0:
            result = 1.0
        elif n < 0:
            result = 1.0/pow(x, -1*n)
        else:
            result = x * pow(x, n-1)
        
        return result
