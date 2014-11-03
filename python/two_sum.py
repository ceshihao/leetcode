class Solution:
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
        map = {}
        for i in range(len(num)):
            if num[i] in map:
                map[num[i]] += [i]
            else:
                map[num[i]] = [i]
        for index1 in range(len(num)):
            gap = target - num[index1]
            if gap in map:
                if gap == num[index1]:
                    if len(map[gap]) == 2:
                        result = (map[gap][0]+1, map[gap][1]+1)
                        break
                else:
                    result = (map[num[index1]][0]+1, map[gap][0]+1)
                    break
        return result