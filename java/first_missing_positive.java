public class Solution {
    public int firstMissingPositive(int[] A) {
        int length = A.length;
        for (int i=0; i<length; )
        {
            if (A[i]>0 && A[i]<=length && A[i]!=A[A[i]-1])
            {
                int tmp = A[A[i]-1];
                A[A[i]-1] = A[i];
                A[i] = tmp;
            }
            else
                ++i;
        }
        for (int i=0; i<length; ++i)
        {
            if (A[i] != i+1)
                return i+1;
        }
        return length+1;
    }
}