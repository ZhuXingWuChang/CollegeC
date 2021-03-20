/*
 * 洋蓟:artichoke   甜菜:beet   胡萝卜:carrot
 * 
 * 打印菜单
 * 
 * 提示用户输入
 * 用户输入，如果不是q：
 *      分支a：用户输入洋蓟的磅数
 *      分支b：用户输入甜菜的磅数
 *      分支c：用户输入胡萝卜的磅数
 *      分支q：退出订购
 *      其它情况：用户输入不对
 * 计算货物总价格
 * 如果总价格大于等于100美元：打折9.5折
 * 
 * 计算运费和包装费
 * 如果少于5磅：6.5美元
 * 否则如果大于5磅少于20磅：14美元
 * 否则如果超过20磅：14美元 + 超的磅数*0.5美元
 * 
 * 打印发票
 */
#include <stdio.h>
#include <string.h>
#define ARTICHOKE_PRICE 2.05f                    // 洋蓟售价
#define BEET_PRICE 1.15f                         // 甜菜售价
#define CARROT_PRICE 1.09f                       // 胡萝卜售价
#define DISCOUNT 0.05f                           // 打折
void print_menu(void);                           // 打印菜单
float calculate_price(float price, float pound); // 计算价格
int main(void)
{
    float vegetable_total = 0.0f; // 蔬菜总价格
    float discount_price = 0.0f;  // 折扣
    float artichoke_pound = 0.0f; // 洋蓟磅数
    float beet_pound = 0.0f;      // 甜菜磅数
    float carrot_pound = 0.0f;    // 胡萝卜磅数
    float artichoke_total = 0.0f; // 洋蓟总价格
    float beet_total = 0.0f;      // 甜菜总价格
    float carrot_total = 0.0f;    // 胡萝卜总价格
    float other_price = 0.0f;     // 运费和包装费
    float total = 0.0f;           // 订单总价格

    char vegetable = '\0'; // 用户选择购买何种蔬菜
    float pound = 0.0f;    // 用来存储用户输入的磅数

    print_menu();
    printf("What do you want to buy? Enter your choice (q to quit): ");
    // 开始购物
    while ((vegetable = getchar()) != 'q')
    {
        switch (vegetable)
        {
        case 'a':
            printf("How many pounds of artichokes do you need? ");
            scanf("%f", &pound);
            getchar();
            if (pound > 0)
            {
                artichoke_total += calculate_price(ARTICHOKE_PRICE, pound);
                artichoke_pound += pound;
            }
            else
                printf("Enter a positive number!\n");
            break;
        case 'b':
            printf("How many pounds of artichokes do you need? ");
            scanf("%f", &pound);
            getchar();
            if (pound > 0)
            {
                beet_total += calculate_price(BEET_PRICE, pound);
                beet_pound += pound;
            }
            else
                printf("Enter a positive number!\n");
            break;
        case 'c':
            printf("How many pounds of artichokes do you need? ");
            scanf("%f", &pound);
            getchar();
            if (pound > 0)
            {
                carrot_total += calculate_price(CARROT_PRICE, pound);
                carrot_pound += pound;
            }
            else
                printf("Enter a positive number!\n");
            break;

        default:
            printf("We don't have this kind of vegetable, please choice again.\n");
            break;
        }
        printf("What do you want to buy? Enter your choice (q to quit): ");
    } // 购物结束

    // 计算蔬菜总费用和折扣
    vegetable_total = artichoke_total + beet_total + carrot_total;
    if (vegetable_total > 100.0f)
        discount_price = vegetable_total * DISCOUNT;
    vegetable_total -= discount_price;

    // 计算运费
    pound = artichoke_pound + beet_pound + carrot_pound;
    if (pound <= 5.0)
        other_price = 6.5;
    else if (pound > 5.0 && pound < 14.0)
        other_price = 14.0;
    else
        other_price = 14.0 + (pound - 14.0) * 0.5;

    // 订单的总费用 = 购物总费用 - 折扣
    total = vegetable_total - discount_price;

    // 打印发票
    printf("****************************************\n");
    printf("artichoke_price     $%.2f/pound\n", ARTICHOKE_PRICE);
    printf("beet_price          $%.2f/pound\n", BEET_PRICE);
    printf("carrot_price        $%.2f/pound\n", CARROT_PRICE);
    printf("artichoke_pound      %.2f pound\n", artichoke_pound);
    printf("beet_pound           %.2f pound\n", beet_pound);
    printf("carrot_pound         %.2f pound\n", carrot_pound);
    printf("artichoke_total     $%.2f\n", artichoke_total);
    printf("beet_total          $%.2f\n", beet_total);
    printf("carrot_total        $%.2f\n", carrot_total);
    printf("vegetable_total     $%.2f\n", vegetable_total);
    if (discount_price > 0.0)
        printf("discount_price      $%.2f\n", discount_price);
    printf("total               $%.2f\n", total);
    printf("other_price         $%.2f\n", other_price);
    printf("sum                 $%.2f\n", total + other_price);
    printf("****************************************\n");

    return 0;
}

void print_menu(void)
{
    char message[255] = {"Our shop sells the following goods:"};
    for (int i = 0; i < strlen(message); i++)
        printf("*");
    printf("\n");
    printf("%s\n", message);
    printf("a) artichoke    $%.2f/pound\n", ARTICHOKE_PRICE);
    printf("b) beet         $%.2f/pound\n", BEET_PRICE);
    printf("c) carrot       $%.2f/pound\n", CARROT_PRICE);
    for (int i = 0; i < strlen(message); i++)
        printf("*");
    printf("\n");

    return;
}

float calculate_price(float price, float pound)
{
    return price * pound;
}