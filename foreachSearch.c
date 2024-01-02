#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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

int findAppointVAlPos(int *array, int length, int val, int *pPos)
{
    int ret = 0;

    if (array == NULL)
    {
        return -1;
    }

    int flag = 0;
    for (int idx = 0; idx < length; idx++)
    {
        if (array[idx] == val)
        {
            *pPos = idx;
            flag = 1;
            return ret;
        }
    }

    if(flag == 0)
    {
        *pPos = -1;

    }
    return ret;
    
}

int main(int argc, char const *argv[])
{
    /* 随机数种子 */
    // srand(time(NULL));

    int buffer[BUFFER_SIZE] = {0};
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        buffer[idx] = rand() % 100 + 1;
    }

    int length = sizeof(buffer) / sizeof(buffer[0]);
    printArray(buffer, length);
    printf("\n");

    int findNum = 36;
    int pos = 0;
    findAppointVAlPos(buffer, length, findNum, &pos);
    printf("pos = %d\n", pos);

    return 0;
}
