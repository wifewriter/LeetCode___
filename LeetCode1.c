//
// Created by Administrator on 2020/3/2.
//
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int* arr;
    arr = (int *)malloc(sizeof(int)*2);
    int i,j,x=0;
    int flag = 0;
    for(i=0;i<numsSize;i++){
        for(j=0;(i!=j)&&(j<numsSize);j++){
            if(nums[i]+nums[j] == target){
                flag = 1;
                if(i>j){
                    x=i;
                    i=j;
                    j=x;
                }
                arr[0] = i;
                arr[1] = j;
                break;
            }
        }
        if(flag)break;
    }
    return arr;
}
