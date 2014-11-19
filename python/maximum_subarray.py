class Solution:
    # @param A, a list of integers
    # @return an integer
    def maxSubArray(self, A):
        if len(A) == 0:
            return null
        sum = 0
        result = A[0]
        for num in A:
            sum += num
            result = max(sum, result)
            sum = max(sum, 0)
        return result