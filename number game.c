#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>
void start();                                               //开始界面
void rule();                                                //规则界面
void load();                                                //加载界面
void game();                                                //游戏主程序
void end();                                                 //结束界面
int main()                                                  //"/t/t/t/t/t"为格式
{
    start();                                                //进入开始界面
}
void start()
{
    char a;
    printf("\t\t\t\t\t——————————————\n");
    printf("\t\t\t\t\t|      数字炸弹游戏        |\n");
    printf("\t\t\t\t\t|      输入1查看规则       |\n");
    printf("\t\t\t\t\t|      按回车键开始游戏    |\n");
    printf("\t\t\t\t\t——————————————\n");
    printf("\t\t\t\t\t");
    a = getchar();
    if (a == '1')
        rule();                                             //进入规则界面
    else if (a == '\n')
        load();                                                 //进入加载界面
}
void rule()
{
    int c=0;
    printf("————————————————————————————————————————————————————————————\n");
    printf("\t\t\t\t\t系统会随机生成一个1-100数，\n");
    printf("\t\t\t\t\t用户需要先输入预测的次数然后输入1-100的数，\n");
    printf("\t\t\t\t\t如果输入的数大于随机的数会提示“您输入的数太大了，\n");
    printf("\t\t\t\t\t如果输入的数小于随机的数会提示“您输入的数太小了，\n");
    printf("\t\t\t\t\t当输入的次数小于预测的次数游戏胜利否则游戏失败。\n");
    printf("————————————————————————————————————————————————————————————\n");
    printf("\t\t\t\t\t按回车键开始游戏");
    getchar();
    if (getchar() == '\n')
        load();
}
void load()
{
    int n=0;
    printf("\t\t\t\t\t游戏加载中");
    for (int i = 0; i < 6; i++)
    {
        printf("·");
        Sleep(500 * sqrt(i * i));
    }
    printf("\n");
    game();                                                  //进入游戏主程序
}
void game()
{
    int n, count, random, fre = 0, flag;
    srand((unsigned)time(NULL));
    random = rand() % 100 + 1;
    printf("%d", random);
    printf("\t\t\t\t\t请输入你预计猜测的次数\n");
    printf("\t\t\t\t\t");
    scanf_s("%d", &count);
    printf("\t\t\t\t\t请输入一个1-100范围内的数\n");
    printf("\t\t\t\t\t");
    while (~scanf_s("%d", &n))
    {
        fre++;
        if (n == random)
            break;
        if (n < random)
            printf("\t\t\t\t\t您输入的数太小了\n");
        if (n > random)
            printf("\t\t\t\t\t您输入的数太大了\n");
        printf("\t\t\t\t\t");
    }
    if (fre <= count)
        printf("\t\t\t\t\t恭喜你，挑战成功！\n");
    else
        printf("\t\t\t\t\t抱歉，挑战失败！\n");
    printf("\t\t\t\t\t是否重新开始游戏？\n");
    printf("\t\t\t\t\t重新开始请按1\n\t\t\t\t\t退出游戏请按2\n");
    printf("\t\t\t\t\t");
    scanf_s("%d", &flag);
    if (flag == 1)
    {
        for (int i = 0; i < 30; i++)
            printf("\n");
        load();
    }
    else
        end();
}
void end()
{
    printf("结束了");
}