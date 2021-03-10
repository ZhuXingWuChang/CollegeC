#include <stdio.h>
int main(void)
{
    float downloading_speed = 0.0; // 下载速率，单位Mbit/s，这里的1M=2^20
    float file_size = 0.0;         // 文件大小，单位MB，这里的1M=2^20
    float downloading_time = 0.0;  // 下载时间，单位s

    printf("Enter downloading speed(Mbit/s) and file size(MB):\n");
    scanf("%f%f", &downloading_speed, &file_size);
    downloading_time = (file_size * 8) / (downloading_speed); // 8bit = 1byte
    printf("At %.2f megabits per second, a file of %.2f megabytes", downloading_speed, file_size);
    printf("downloads in %.2f seconds.", downloading_time);

    return 0;
}