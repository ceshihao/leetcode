public class Solution {
    public int lengthOfLastWord(String s) {
        char prev = ' ';
        int count = 0;
        for (int i=0; i<s.length(); ++i)
        {
            char c = s.charAt(i);
            if (prev == ' ' && c!= ' ')
            {
                count = 1;
                prev = c;
            }
            else if (c != ' ')
                count++;
            else
                prev = c;
        }
        return count;
    }
}