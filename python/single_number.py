class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        result = 0;
        for item in A:
            result ^= item
        return result