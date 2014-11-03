class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int ia = m - 1;
        int ib = n - 1;
        int index = m + n -1;
        while (ia >= 0 && ib >= 0)
        {
            if (A[ia] < B[ib])
                A[index--] = B[ib--];
            else
                A[index--] = A[ia--];
        }
        while (ib >= 0)
            A[index--] = B[ib--];
    }
};