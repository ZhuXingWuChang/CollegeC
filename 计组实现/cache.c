/*
DRAM 主存: size==1K的数组,每一个存储单元代表一个块,每一个块里面又存放64个字
SRAM cache: size==32的数组,每一行用来存放主存中的一个块,分为8组,每一组4行
CAM 相联存储器: size==32,每个单元存储主存到cache的地址映射

程序要求计算出命中率

分析:
因为主存里,每一块存放64个字,所以 字号=6位
因为有8个组,所以 组号=3位
又因为主存中有1K个块,每个块对应一个地址,所以CPU发出的地址位数为10位
又因为10位中有3位拿出来用来标记了分组
所以 tag=7位, 那么

综上:
CPU每次发出16位的访问地址,格式为 "7位tag + 3位组号 + 6位字号"
CPU每次寻址,先通过3位组号,来找到cache中对应的分组,然后将7位tag与该分组中每一行的tag同时比较
若命中,则按照6位字号访问该行对应的字
若未命中,则按照高10位的地址,去主存中访问该块,并按照6位字号访问该块对应的字
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAINSIZE 1024     // 主存包含1K个块
#define CACHESIZE 32      // cache包含32行
#define CAMSIZE CACHESIZE // CAM存储的地址映射数
#define WORDNUM 64        // 每一个块(行)中含有64个字

int main(void)
{
    int mainMemory[MAINSIZE][WORDNUM] = {0};   // 主存有1024个块,每个块有64个字
    int cacheMemory[CACHESIZE][WORDNUM] = {0}; // cache有32行,每一行有64个字
    int cam[CACHESIZE] = {0};                  // CAM存放主存存到cache中对应的地址
    int visitCount[CACHESIZE] = {0};           // 每一行的访问计数器
    double hit = 0.0;                          // hit代表CPU到cache的命中率
    int count = 0;                             // count用来存放命中的次数

    srand((unsigned int)time(0)); // 初始化随机种子

    // 使用一个for循环,在主存中大概一半的块里写入数据
    for (int i = 0; i < MAINSIZE / 2; i++)
    {
        int index = abs(rand()) % MAINSIZE; // 对于主存,随机产生一个块号

        // 遍历块中的每一个字,为其写入随机数据
        for (int j = 0; j < WORDNUM; j++)
            mainMemory[index][j] = abs(rand()) % 256; // 写入的数据值在0到255之间,随机值
    }

    /*
因为主存中的数据过多,一共有1024*64个字,控制台显示不下,所以这段代码最好不要运行
*/
    // // 此时主存中的数据为
    // printf("The data in main memory is: ");
    // // 对主存中所有块遍历
    // for (int i = 0; i < MAINSIZE; i++)
    // {
    //     // 对块中每一个字遍历
    //     for (int j = 0; j < WORDNUM; j++)
    //         printf("%3d ", mainMemory[i][j]);
    //     printf("\n");
    // }
    // printf("\n");

    // 随机地把主存的数据写入到cache中
    // 遍历cache
    for (int i = 0; i < CACHESIZE; i++)
    {
        int index = rand() % MAINSIZE; // 随机产生一个主存的地址(块号)

        // 遍历该块中的每一个字,把这个块中所有的字写入到cache的行中
        for (int j = 0; j < WORDNUM; j++)
            cacheMemory[i][j] = mainMemory[index][j];

        // 与此同时,将这些块的块号保存到CAM中
        cam[i] = index;
    }

    // cache中的数据为
    printf("The data in cache is: \n");
    // 遍历cache的行
    for (int i = 0; i < CACHESIZE; i++)
    {
        // 遍历行中的每一个字
        for (int j = 0; j < WORDNUM; j++)
            printf("%3d ", cacheMemory[i][j]);
        printf("\n");
    }
    printf("\n");

    // 对应的地址为
    printf("The corresponding address is: \n");
    for (int i = 0; i < CACHESIZE; i++)
        printf("%3d ", cam[i]);
    printf("\n");

    // CPU产生100个连续的地址,为了方便,把19位地址以 高12位的块号 和 低7位的字号 分开处理
    const int ADRESSNUM = 100;                           // 代表连续访问100个地址
    int startBlockNum = rand() % (MAINSIZE - ADRESSNUM); // startBlockNum是随机产生的块号,这样处理可以保证 块号+100 后仍不越界
    printf("The start block number is: *%d*\n", startBlockNum);
    for (int i = 0; i < ADRESSNUM; i++)
    {
        int blockNum = startBlockNum + i;

        for (int j = 0; j < CACHESIZE; j++)
        {
            // LRU替换策略的计数原理
            if (blockNum == cam[j])
            {
                count++; // 这个count是为了最终计算命中率的
                visitCount[j]++;
            }
            else
                visitCount[j] = 0;
        }

        // 每一行计数完以后,找到第一个值最大的计数器,下次将其替换掉
        int max = 0;
        for (int j = 0; j < CACHESIZE; j++)
        {
            if (visitCount[j] > max)
                max = j; // 保存最大值的下标
        }

        // 替换操作
        for (int j = 0; j < WORDNUM; j++)
        {
            cacheMemory[max][j] = mainMemory[blockNum + 1][j];
        }
    }

    // 计算出命中率
    hit = (double)count / (double)CACHESIZE;
    printf("The CPU's cache hit ratio is: %.2lf", hit);

    return 0;
}