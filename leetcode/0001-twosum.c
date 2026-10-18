/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #include <stdio.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
int *array=(int*)malloc(sizeof(int)*2);
    *returnSize=2;
    for(int i=0;i<numsSize;i++)  
    {
        for(int j=i+1;j<numsSize;j++)
        {
            if(nums[i]+nums[j]==target){
            array[0]=i;
            array[1]=j;
            return array;}
        }
    }
    return NULL;
}
int main(void)
{
    int numsize,returnSize,target;
    printf("input the number of elements：");
    scanf("%d",&numsize);
    int nums[numsize];
    printf("input the array elements：");
    for(int i=0;i<numsize;i++)
    {
        scanf("%d",&nums[i]);
    }
    printf("input the target value：");
    scanf("%d",&target);
    int *array=twoSum(nums,numsize,target,&returnSize);
    printf("%d %d\n",array[0],array[1]);
    free(array);
    return 0;
}