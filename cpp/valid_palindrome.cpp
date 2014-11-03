class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int left = 0, right = s.size();
        while (left < right) {
            if (!isalnum(s[left])) ++left;
            else if (!isalnum(s[right])) --right;
            else if (s[left] != s[right]) return false;
            else{ left++, right--; }
        }
        return true;
    }
};