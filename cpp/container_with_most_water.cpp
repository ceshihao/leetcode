class Solution {
public:
    int maxArea(vector<int> &height) {
        int begin=0, end=height.size()-1;
        int result = -1;
        while (begin != end)
        {
            int h = min(height[begin], height[end]);
            int square = (end - begin) * h;
            if ( square > result)
                result = square;
            if (height[begin]<height[end]) ++begin;
            else --end;
        }
        return result;
    }
};