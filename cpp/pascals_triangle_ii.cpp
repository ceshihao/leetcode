class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        for (int row=0; row!=rowIndex+1; ++row)
        {
            result.push_back(1);
            for (vector<int>::reverse_iterator iter=result.rbegin(); iter!=result.rend(); ++iter)
            {
                if (iter!=result.rbegin() && iter!=result.rend()-1)
                    *iter = *iter + *(iter+1);
            }
        }
        return result;
    }
};