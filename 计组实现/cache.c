/*
主存:size==256的数组,每一个单元里面存放一个数据,但是空出一部分不写数据
cache:size==32的数组
第三个数组:存放主存到cache的主相联下标映射

程序要求计算出命中率
*/
#include <stdio.h>
#include <stdlib.h>
#define MAINSIZE 256 // 主存的存储单元数
#define CACHESIZE 32 // cache的存储单元数
int main(void)
{
    int mainMemory[MAINSIZE] = {0};   // 主存有256个存储单元
    int cacheMemory[CACHESIZE] = {0}; // cache有32个存储单元
    int map[CACHESIZE] = {0};         // map存放主存存到cache中对应的地址
    double hit = 0.0;                 // hit代表CPU到cache的命中率
    int count = 0;                    // count用来存放命中的次数

    // 使用一个for循环,在主存中大概一半的存储单元里写入数据
    for (int i = 0; i < MAINSIZE / 2; i++)
    {
        int index = rand() % MAINSIZE; // 对于主存,产生一个合法的随机下标
        mainMemory[index] = 1;         // 在这个随机下标处写入数据
    }

    // 此时CPu中的数据为
    printf("The data in main memory is: ");
    for (int i = 0; i < MAINSIZE; i++)
    {
        if (i % CACHESIZE == 0)
            printf("\n");
        printf("%2d", mainMemory[i]);
    }
    printf("\n");

    // 随机地把主存的数据写入到cache中
    for (int i = 0; i < CACHESIZE; i++)
    {
        int index = rand() % MAINSIZE;      // 对于主存,产生一个合法的随机下标
        cacheMemory[i] = mainMemory[index]; // 随机地将数据写入cache
        map[i] = index;                     // 对应地址存入到map中
    }

    // cache中的数据为
    printf("The data in cache is: \n");
    for (int i = 0; i < CACHESIZE; i++)
        printf("%2d", cacheMemory[i]);
    printf("\n");

    // 对应的地址为
    printf("The corresponding address is: \n");
    for (int i = 0; i < CACHESIZE; i++)
        printf("%d ", map[i]);
    printf("\n");

    // CPU产生32个连续地址
    int startAddress = rand() % (MAINSIZE - CACHESIZE); // startAddress是一个不会越界的随机起始地址
    printf("The start address is: *%d*\n", startAddress);
    for (int i = 0; i < CACHESIZE; i++)
    {
        int address = startAddress + i;
        // 检查CPU发出的连续地址,命中了cache多少次
        for (int j = 0; j < CACHESIZE; j++)
            if (address == map[j])
                count++;
    }

    // 计算出命中率
    hit = (double)count / (double)CACHESIZE;
    printf("The CPU's cache hit ratio is: %.2lf", hit);

    return 0;
}