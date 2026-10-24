#include <stdio.h>
int searchInsert(int* nums, int numsSize, int target) {
    int head = 0, tail = numsSize - 1;
    int mid = 0;
    if (target <= nums[0])
        return 0;
    if(target>nums[tail])
    return numsSize;
    while (head < tail) {
        mid = (head + tail) / 2;
        if (nums[mid] == target) {
            return mid;
        } else {
            if (nums[mid] < target) {
                head = mid + 1;
                if (target < nums[head])
                    return mid + 1;
            } else {
                tail = mid - 1;
                if (target > nums[tail])
                    return tail + 1;
            }
        }
    }
    return head;
}

int main(void)
{
    int nums[] = {1, 3, 5, 6};
    int target = 5;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int index = searchInsert(nums, numsSize, target);
    printf("Index to insert %d: %d\n", target, index);
    return 0;
}