public class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int length = triangle.size();
        int[][] result = new int[length][length];
        result[0][0] = triangle.get(0).get(0);
        
        for (int i=1; i<length; ++i)
        {
            List<Integer> level = triangle.get(i);
            for (int j=0; j<=i; ++j)
            {
                
                if (j==0)
                    result[i][j] = result[i-1][j] + level.get(j);
                else if (i==j)
                    result[i][j] = result[i-1][j-1] + level.get(j);
                else
                    result[i][j] = (result[i-1][j-1]>result[i-1][j]?result[i-1][j]:result[i-1][j-1])+level.get(j);
            }
        }
        int min_path = result[length-1][0];  
        for(int i=1;i<length;i++){  
            min_path = (min_path < result[length-1][i]?min_path:result[length-1][i]);  
        }  
        return min_path;
    }
}