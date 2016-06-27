public class Solution {
    public int[] searchRange(int[] nums, int target) {
        int i = 0;
        int start = -1, end = -1;
    
        while(i < nums.length && (nums[i] != target))
            i++;
        if(i < nums.length){
            start = i;
            while(i < nums.length && (nums[i] == target))
                i++;
            end = i - 1;
        }
        int [] result = new int[2];
        result[0] = start;
        result[1] = end;
        return result;
    }
}
