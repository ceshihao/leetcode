class Solution {
public:
    int findMin(vector<int> &num) {
        int begin = 0, end = num.size()-1;
        return findMin(num, begin, end);
    }
    
    int findMin(vector<int> & num, int begin, int end) {
        if (begin == end)
            return num[begin];
        int mid = (begin + end) / 2;
        if (num[mid] < num[end])
            return findMin(num, begin, mid);
        else
            return findMin(num, mid+1, end);
    }
};