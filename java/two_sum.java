public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        Map<Integer, Integer> mapping = new HashMap<Integer, Integer>();
        int[] result = new int[2];
        for (int i=0; i<numbers.length; ++i)
            mapping.put(numbers[i], i);
        for (int i=0; i<numbers.length; ++i)
        {
            int gap = target - numbers[i];
            if(mapping.get(gap) != null && mapping.get(gap)>i)
            {
                result[0] = i+1;
                result[1] = mapping.get(gap)+1;
                break;
            }
        }
        return result;
    }
}