class Solution:
    # @return a list of integers
    def getRow(self, rowIndex):
        result=[1]
        for row in range(rowIndex+1):
            for index in range(row):
                if index == 0:
                    result.append(1)
                else:
                    result[row-index] += result[row-index-1]
        return result