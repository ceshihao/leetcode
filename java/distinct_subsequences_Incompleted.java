public class Solution {
    public int numDistinct(String S, String T) {
        int lengthS = S.length();
        int lengthT = T.length();
        
        if (lengthS==0 || lengthT==0)
            return 0;
        int[][] result = new int[lengthS+1][lengthT+1];
//        for (int i=0; i<lengthS+1; ++i)
//            result[i][0] = 0;
//        for (int i=1; i<lengthT+1; ++i)
//            result[0][i] = 0;
        for (int i=1; i<=lengthS; ++i)
        {
            for (int j=1; j<=i; ++j)
            {
                if (S.charAt(i-1) == T.charAt(j-1))
                    if (j == 1)
                        result[i][j] = 1;
                    else
                        result[i][j] = result[i-1][j-1] + result[i-1][j];
                else
                    result[i][j] = result[i-1][j];
            }
        }
        return result[lengthS][lengthT];
    }
}