class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int length = 0;
        if ( n == 0 || n==1)
            return n;
        else
        {
            for(int i = 1; i<n; i++)
            {
                if (A[i] != A[length])
                {
                    A[++length] = A[i];
                }
            }
            return length + 1;
        }

    }
};