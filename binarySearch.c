#include <stdio.h>

#define BUFFER_SIZE 10

/* 打印函数 */
void printArray(int *array, int arraySize)
{
    if (array == NULL)
    {
        return;
    }
    for (int idx = 0; idx < arraySize; idx++)
    {
        printf(" %d ", array[idx]);
    }
}

/* 返回值：1表示存在，0表示不存在 */
int binarySearchAppointValPos(int *array, int length, int val)
{
    int ret = 0;
    if (array == NULL)
    {
        return 0;
    }

    int start = 0;
    int end = length - 1;
    int midPos = 0;

    while (start <= end)
    {
#if 0
        midPos = (end + start) / 2;
#else
        midPos = (start + end) >> 1;
#endif
#if 1
/* todo... */
        if (val < array[midPos])
        {
            end = midPos;
            length = midPos - start + 1;
            binarySearchAppointValPos(array, length, val);
            return 0;
        }
        else if (val > array[midPos])
        {
            start = midPos;
            length = end - midPos + 1;
            binarySearchAppointValPos(array, length, val);
            return 0;
        }
        else
        {
            return 1;
        }

#else
        /* 找到了 */
        if (array[midPos] == val)
        {
            return midPos;
        }
        else if (array[midPos] < val)
        {
            start = midPos + 1;
        }
        else if (array[midPos] > val)
        {
            end = midPos - 1;
        }
#endif
    }
    /* 没找到 */
    return -1;
}

int main(int argc, char const *argv[])
{
    int buffer[BUFFER_SIZE] = {0};
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        buffer[idx] = idx + 2;
    }

    int length = sizeof(buffer) / sizeof(buffer[0]);
    printArray(buffer, length);
    printf("\n");

    int val = 5;
    int isExist = binarySearchAppointValPos(buffer, length, val);
    printf("isExist: %d\n", isExist);
    return 0;
}
