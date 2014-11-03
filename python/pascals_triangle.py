class Solution:
    # @return a list of lists of integers
    def generate(self, numRows):
        result = []
        for row in range(numRows):
            tmp = []
            for index in range(0, row+1):
                if index == 0 or index == row:
                    tmp.append(1)
                else:
                    tmp.append(result[row-1][index-1] + result[row-1][index])
            result.append(tmp)
        return result