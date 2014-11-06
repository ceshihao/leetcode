import java.util.*;
public class Solution {
    public void sortColors(int[] A) {
        int red = 0, white = 0;
        for (int i=0; i<A.length; ++i)
        {
            if (A[i] == 0)
            {
                int tmp = A[i];
                A[i] = A[white];
                A[white++] = A[red];
                A[red++] = tmp;
        }
            else if (A[i] == 1)
            {
                int tmp = A[white];
                A[white++] = A[i];
                A[i] = tmp;
            }
        }
        return;
    }
}