class Solution {
public:
    double pow(double x, int n) {
        double result;
        if (n==0 || x == 1.0)
            result = 1.0;
        else if (x == -1.0)
        {
            if (n % 2 == 0)
                result = 1.0;
            else
                result = -1.0;
        }
        else if (n < 0)
            result = 1.0 / pow(x, -1*n);
        else
        {
            double tmp = pow(x, n/2);
            if (n%2 == 0)
                result = tmp *tmp;
            else
                result = x * tmp * tmp;
        }
        
        
        return result;
    }
};