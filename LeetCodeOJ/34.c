/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int i = 0;
    int start = -1, end = -1;
    
        while(i < numsSize && (nums[i] != target))
            i++;
        if(i < numsSize){
            start = i;
            while(i < numsSize && (nums[i] == target))
                i++;
            end = i - 1;
        }
    *returnSize = 2;
    int *result = (int *)malloc((*returnSize) * sizeof(int));
    result[0] = start;
    result[1] = end;
    return result;
}
