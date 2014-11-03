class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector< vector<int> > result;
        for (vector<vector<int>>::size_type row=0; row!=numRows; ++row)
        {
            vector<int> tmp;
            for (vector<int>::size_type index=0; index!=row+1; ++index)
            {
                if(index==0 || index==row)
                    tmp.push_back(1);
                else
                    tmp.push_back(result[row-1][index-1]+result[row-1][index]);
            }
            result.push_back(tmp);
        }
        return result;
    }
};