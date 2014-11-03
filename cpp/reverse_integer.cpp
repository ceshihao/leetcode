class Solution {
public:
    int reverse(int x) {
        long result = 0;
        int flag = 1;
        if (x < 0)
        {
            flag = -1;
            x *= -1;
        }
        
        while (x > 0)
        {
            result = result * 10 + x % 10;
            x /= 10;
        }
        
        if (result * flag > INT_MAX)
            return INT_MAX;
        else if (result * flag < INT_MIN)
            return INT_MIN;
        else
            return (int) (result * flag);
    }
};