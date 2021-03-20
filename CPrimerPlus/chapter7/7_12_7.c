/*
 * 基本工资=10美元/小时
 * 加班（超过40小时）=15美元/小时
 * 税率：前300美元为15%
 *      续150美元为20%
 *      超过450美元的部分为25%
 * 
 * ------------------------------
 * 定义工资分界线1
 * 定义工资分界线2
 * 读取用户输入，当用户输入合法时：
 *      如果没有加班：计算税前工资
 *      否则：计算加班的税前工资
 *      
 *      如果工资小于分界线1：按照15%税率计算税后工资
 *      如果工资在分界线1到分界线2之间：税后工资=分界线1+（税后工资-分界线1）*20%税率
 *      否则：税后工资=分界线2+（税后工资-分界线2）*25%税率
 * 
 * 输出结果
 */
#include <stdio.h>
#include <math.h>
#define SALARY1 300.0
#define SALARY2 450.0
#define TIME_LIMIT 40.0
#define BASE_SALARY_PER_HOUR 10.0
#define OVERTIME_SALARY_PER_HOUR 15.0
#define RATE1 0.10
#define RATE2 0.15
#define RATE3 0.25
int main(void)
{
    double time = 0.0;
    double salary = 0.0;

    printf("Enter your wordking time (q to quit): ");

    while (scanf("%lf", &time) == 1)
    {
        // 计算税前工资
        if (time < TIME_LIMIT)
            salary = time * BASE_SALARY_PER_HOUR;
        else
            salary = TIME_LIMIT * BASE_SALARY_PER_HOUR + (time - TIME_LIMIT) * OVERTIME_SALARY_PER_HOUR;
        // printf("salary = %lf\n", salary);    // 调试代码

        // 根据税前工资来计算税后工资
        if (salary < SALARY1 || abs(salary - SALARY1) < 0.001)
            salary *= (1 - RATE1);
        else if (salary > SALARY1 && (salary < SALARY2 || abs(salary - SALARY2) < 0.00001))
            salary = SALARY1 * (1 - RATE1) + (salary - SALARY1) * (1 - RATE2);
        else
            salary = SALARY1 * (1 - RATE1) + (SALARY2 - SALARY1) * (1 - RATE2) + (salary - SALARY2) * (1 - RATE3);

        printf("Your salary is %.2lf dollars.\n", salary);
        printf("Enter your wordking time (q to quit): ");
    }

    return 0;
}