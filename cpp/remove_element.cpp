class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int length = 0;
        for (int i=0; i<n; ++i)
        {
            if (A[i] != elem)
            {
                A[length] = A[i]; 
                length++;
            }
        }
        return length;
    }
};