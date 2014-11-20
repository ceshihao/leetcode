public class Solution {
    public int numDecodings(String s) {
        int length = s.length();
        if (length == 0)
            return 0;
        int[] num = new int[length];
        if (s.charAt(0) == '0')
            return 0;
        else
            num[0] = 1;
        for (int i=1; i<length; ++i)
        {
            int two = Integer.parseInt(s.substring(i-1, i+1));
            int one = Integer.parseInt(s.substring(i, i+1));
            if (two == 0 || (one == 0 && two > 26))
                return 0;
            else if (two > 26 || two < 10)
                num[i] = num[i-1];
            else if (one == 0)
                num[i] = (i==1?1:num[i-2]);
            else
                num[i] = num[i-1] + (i==1?1:num[i-2]);
        }
        return num[length-1];
    }
}