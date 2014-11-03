class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1;
        for (vector<int>::reverse_iterator iter=digits.rbegin(); iter!=digits.rend(); ++iter)
        {
            *iter += carry;
            carry = *iter / 10;
            *iter %= 10;
        }
        if (carry > 0)
            digits.insert(digits.begin(),carry);
        return digits;
    }
};