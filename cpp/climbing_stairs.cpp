class Solution {
public:
    int climbStairs(int n) {
        int map[n];
        for (int i=0; i<n; ++i)
        {
            if (i==0)
                map[i] = 1;
            else if (i==1)
                map[i] = 2;
            else
                map[i] = map[i-1] + map[i-2];
        }
        return map[n-1];
    }
};