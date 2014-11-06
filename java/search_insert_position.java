public class Solution {
    public int searchInsert(int[] A, int target) {
        int pos = 0;
        for (int item:A)
        {
            if (item < target)
                ++pos;
            else
                break;
        }
        return pos;
    }
}