public class Solution {
    public int removeDuplicates(int[] A) {
        int length = 0, prev = Integer.MIN_VALUE;
        for (int item:A)
        {
            if (item != prev)
            {
                A[length++] = item;
                prev = item;
            }
        }
        return length;
    }
}