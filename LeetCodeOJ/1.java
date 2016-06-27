public class Solution {
    public int[] twoSum(int[] nums, int target) {
        int i, j;
        int index1 = 0, index2 = 0;
        int temp = 0, flag = 0;
        for(i = 0; i < nums.length; i++){
        temp = nums[i];
        for(j = i+1; j < nums.length; j++){
            if((temp + nums[j]) == target){
                index1 = i + 1;
                index2 = j + 1;
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            break;
    }
    int[] result = new int[2];
    result[0] = index1;
    result[1] = index2;
    return result;
    }
}
