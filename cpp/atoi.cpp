class Solution {
public:
    int atoi(const char *str) {
        long long result = 0;
        int flag = 1;
  
        while (*str == ' ')
            str++;
        
        if (*str == '+')
        {
            flag = 1;
            str++;
        }
        else if (*str == '-')
        {
            flag = -1;
            str++;
        }
        else if (*str >= '0' && *str <= '9')
        {
            flag = 1;
        }
        else
            return result;
        
        while (str != NULL)
        {
            if (*str < '0' || *str > '9')
                break;
            else
            {
                result = result * 10 + (*str - '0');
                str++;
            }
        }
        
        if (result * flag > INT_MAX)
            return INT_MAX;
        else if (result * flag < INT_MIN)
            return INT_MIN;
        else
            return (int) result * flag;
    }
};