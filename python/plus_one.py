class Solution:
    # @param digits, a list of integer digits
    # @return a list of integer digits
    def plusOne(self, digits):
        carry = 1
        length = len(digits)
        for i in range(0,length):
            tmp = carry + digits[length-i-1]
            carry = tmp/10
            digits[length-i-1] = tmp % 10
        if carry > 0:
            digits.insert(0, carry)
        return digits