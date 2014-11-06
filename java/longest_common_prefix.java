public class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length==0) return "";
        String temp = strs[0];
        int length = temp.length();
        for (int i=1; i<strs.length; ++i)
        {
            length = Math.min(length, strs[i].length());
            for (int j=0; j<length; ++j)
            {
                if (temp.charAt(j) != strs[i].charAt(j))
                {
                    length = j;
                    break;
                }
            }
        }
        return temp.substring(0, length);
    }
}