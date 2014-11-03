class Solution:
    # @param a list of integers
    # @return an integer
    def removeDuplicates(self, A):
        if len(A) > 1:
            length = 0
            for index in range(1,len(A)):
                if A[length] != A[index]:
                    length += 1
                    A[length] = A[index]
            length += 1
        else:
            length = len(A)
        return length