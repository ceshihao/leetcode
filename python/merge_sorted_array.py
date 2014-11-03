class Solution:
    # @param A  a list of integers
    # @param m  an integer, length of A
    # @param B  a list of integers
    # @param n  an integer, length of B
    # @return nothing
    def merge(self, A, m, B, n):
        ia = m - 1
        ib = n - 1
        index = m + n - 1
        while ia >= 0 and ib >= 0:
            if A[ia] < B[ib] or ia ==-1:
                A[index] = B[ib]
                index -= 1
                ib -= 1
            else:
                A[index] = A[ia]
                index -= 1
                ia -= 1
        while ib >= 0:
            A[index] = B[ib]
            index -= 1
            ib -= 1
        return A