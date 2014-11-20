public class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        int[][] ways = new int[m][n];
        
        if (obstacleGrid[0][0] != 0)
            return 0;
        else
            ways[0][0] = 1;
        for (int i=1; i<m; ++i)
            if (obstacleGrid[i][0] == 0)
                ways[i][0] = ways[i-1][0];
            else
                ways[i][0] = 0;
        for (int i=1; i<n; ++i)
            if (obstacleGrid[0][i] == 0)
                ways[0][i] = ways[0][i-1];
            else
                ways[0][i] = 0;

        for (int i=1; i<m; ++i)
            for (int j=1; j<n; ++j)
                if (obstacleGrid[i][j] == 0)
                    ways[i][j] = ways[i-1][j] + ways[i][j-1];
                else
                    ways[i][j] = 0;
        return ways[m-1][n-1];
    }
}