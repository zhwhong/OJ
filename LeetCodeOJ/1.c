/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i, j, index1, index2;
    int temp = 0, flag = 0;
    for(i = 0; i < numsSize; i++){
        temp = nums[i];
        for(j = i+1; j < numsSize; j++){
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
    int *result = (int *)malloc(2 * sizeof(int));
    result[0] = index1;
    result[1] = index2;
    return result;
}
