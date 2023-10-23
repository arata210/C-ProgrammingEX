/*实验五：停车场管理*/

/*本程序为了尽可能保证输入正确、程序安全，在绝大部分int类型输入处有设置保护措施*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000                 //定义MAX数值

struct Parking                   //停车场结构体
{
    char number[1000];           //车牌号
    int ptime;                   //停车时长
}p1[MAX];                        //结构数组p1

int count=0,cars,time,i;     //全局变量 | count - 当前总车数的计数器 | cars - 停车场车位数 | time - 输入时间 | i - 常用变量 
char num[MAX];               //        | num[MAX] - 输入车牌号

void arrive(int cars)        //函数 - 入场
{
    int flag=1;              //测试cars内是否有空位
    scanf("%s",num);         //输入车牌
    if(scanf("%d",&time)!=1) //输入时间
    {
        system("CLS");
        printf("\n输入非法字符，自动退出程序. . .");
        system("pause");
        exit(0);
    }
    for(i=1;i<=cars;i++)                 //for循环查找空位
    {
        if(strlen(p1[i].number)==0)      //查找方式是车牌号的char型的长度是否为'空(NULL)'
        {
            strcpy(p1[i].number,num);    //保存输入的车牌号进入结构体
            p1[i].ptime=time;            //保存输入的入场时间进入结构体
            printf("\n入场成功，您的车位号是%d号。",flag);  //提示使用者成功停入
            count++;                     //车辆总数增加
            break;
        }
        else
        {
        	flag++;
            continue;
        }
    }
    if(flag>cars)                           //停车场无空位的情况下
    {
    	for(i=cars+1;;i++)                  //已知无空位，for循环从cars+1开始，因为一定会跳出循环，所以不设跳出参数
        {
            if(strlen(p1[i].number)==0)     //查找方式是车牌号的char型的长度是否为'空(NULL)'
            {
                strcpy(p1[i].number,num);   //保存输入的车牌号进入结构体
                p1[i].ptime=time;           //保存输入的入场时间进入结构体
                printf("\n当前车位已满，请停留在便道上等待。\n",p1[i].number); //提示使用者成功停入
                count++;                   //车辆总数增加
                break;                     //跳出循环
            }
            else
            {
                continue;
            }
        }
    }
    printf("\n");
}

void change(int time,int cars,int i)                //函数 - 移动车位
{
    for(int j=i;j<cars;j++){                        //调整停车场车位
        strcpy(p1[j].number,p1[j+1].number);
        p1[j].ptime=p1[j+1].ptime;
    }
    strcpy(p1[cars].number,"\0");                   //末位为空
    p1[cars].ptime=time;                            //等候区第一辆车的进场时间
    for(int q=cars+1;q<=count;q++)                  //停车场末位+等候区车位、时间顺序重置
    {
        if(strlen(p1[q].number)!=0)
        {
            strcpy(p1[cars].number,p1[q].number);
            p1[q].ptime=time;
            printf("车牌号【%s】成功停入%d号车位。\n\n",p1[cars].number,cars);
            strcpy(p1[q].number,"\0");
            for(int t=cars+1;t<=count;t++)
            {
                if(strlen(p1[t].number)==0)
                {
                    strcpy(p1[t].number,p1[t+1].number);
                    strcpy(p1[t+1].number,"\0");
                }
            }
            break;
        }
    }
}

void depart(int cars)                                 //函数 - 驶离
{
    int flag=0,flag2=0;
    scanf("%s",num);
    if(scanf("%d",&time)!=1)
    {
        system("CLS");
        printf("\n输入非法字符，自动退出程序. . .");
        system("pause");
        exit(0);
    }
    for(i=1;i<=count;i++){
        if(strcmp(p1[i].number,num)==0&&i>cars)                  //等候区驶离两种情况
        {
            printf("车号【%s】当前在便道上等待，是否准备离开？\n1 - 离开     2 - 等待(默认)\n请输入：",p1[i].number);
            int request;
            if(scanf("%d",&request)!=1)
            {
                system("CLS");
                printf("\n输入非法字符，自动退出程序. . .");
                system("pause");
                exit(0);
            }
            if(request==1)
            {
                strcpy(p1[i].number,"\0");
                p1[i].ptime=0;
                for(i==cars;i<=count;i++){
                    if(strlen(p1[i].number)==0){
                        strcpy(p1[i].number,p1[i+1].number);
                        strcpy(p1[i+1].number,"\0");
                        count--;
                    }
                }
                flag2=1;
                break;
            }
            else
            {
                printf("继续等待中. . .\n");
                flag2=1;
                break;
            }
        }
        else if(strcmp(p1[i].number,num)==0&&i<=cars)           //停车场驶离
        {
            flag2=1;
            int exit;
            exit=time-p1[i].ptime;
            if(exit<0)
            {
                printf("\n驶离时间非法，请重新输入. . .\n\n");
                break;
            }
            else
            {
                printf("\n车牌号【%s】停留时间为%d小时，\n需缴付停车费%d元整。欢迎下次光临。\n\n",p1[i].number,exit,exit*10);
                flag++;
                strcpy(p1[i].number,"\0");
                p1[i].ptime=0;
                change(time,cars,i);
                break;
            }
        }
        else
        {
            continue;
        }
    }
    count=count-flag;                      //修改总数
    if(flag2==0) printf("\n无该车号的车，请重新输入. . .\n");
}

void park(int cars)                       //函数 - 简易示意图
{
    int k;
    printf("\n本停车场共有%d个车位。",cars);
    if(count>cars) printf("当前有%d辆车在等候中. . .",count-cars);
    printf("\n\n停车场：\n");
    printf("        ");
    for(k=1;k<=cars;k++)
    {
        if(strlen(p1[k].number)==0) printf("%-10s","空");
        else printf("%10s",p1[k].number);
        printf("  ");
    }
    printf("\n");
    if(count>cars)
    {
        printf("\n\n便道上：\n");
        for(k=cars+1;k<=count;k++)
        {
            printf("        %10s\n\n",p1[k].number);
        }
    }
    printf("-------------------------------------------------------------------------\n");
    printf("\n");
}

void end()                           //函数 - 退出程序（'E 0 0'）
{
    scanf("%s",num);
    if(scanf("%d",&time)!=1)
    {
        system("CLS");
        printf("\n输入非法字符，自动退出程序. . .");
        system("pause");
        exit(0);
    }
    if(num[0]=='0'&&strlen(num)==1&&time==0)
    {
        printf("\n已成功退出程序. . .");
        system("pause");
        exit(0);
    }
    else
    {
        printf("\n输入错误，请重新输入. . .\n");
    }
}

int main()
{
    printf("\n");
    printf("\n");
    printf("              * * * * * * ****************** * * * * * * *\n");
    printf("              *                                          *\n");
    printf("              *           实验五：停车场管理             *\n");
    printf("              *                                          *\n");
    printf("              * * * * * * ****************** * * * * * * *\n");
    printf("\n");
    printf("\n");

    printf("请输入车位总数：");
    if(scanf("%d",&cars)!=1){
        system("CLS");
        printf("\n输入非法字符，自动退出程序. . .");
        system("pause");
        exit(0);
    }
    printf("\n");

    char choice;
    printf("车辆入场 - A 车牌号码 进入时间\n车辆驶离 - D 车牌号码 离开时间\n退出程序 - E %4d %8d\n\n注意：本停车场收费为每小时10元。\n\n",0,0);
    while(1)
    {
        getchar();
        scanf("%c",&choice);
        if(choice=='A')
        {
            arrive(cars);
            park(cars);
        }
        else if(choice=='D')
        {
            depart(cars);
            park(cars);
        }
        else if(choice=='E')
        {
            end();
        }
        else if(choice=='C')                //修改总数
        {
            int c;
            printf("\n修改停车场车位总数。注：若扩大车位，原便道上的入场时间从'0'记起。\n请输入：");
            scanf("%d",&c);
            cars=c;
            printf("\n修改成功。\n\n");
            park(cars);
            
        }
        else
        {
            printf("\n输入错误，请重新输入. . .\n");
            continue;
        }
    }

    return 0;
}