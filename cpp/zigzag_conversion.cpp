class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) return s;
        int length = s.size();
        string result;
        for (int i=0; i<nRows; ++i)
        {
            string tmp;
            int j=i;
            while (j<length)
            {
                if(j%(nRows-1) == 0)
                {
                    tmp += s[j];
                    j += 2*(nRows-1);
                }
                else
                {
                    tmp += s[j];
                    if (j+2*(nRows-1)-2*i<length)
                        tmp += s[j+2*(nRows-1)-2*i];
                    j += 2*(nRows-1);
                }
            }
            result+= tmp;
        }
        return result;
    }
};