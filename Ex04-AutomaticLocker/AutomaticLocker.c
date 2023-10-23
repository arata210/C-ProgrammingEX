#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
void menu();            /*菜单*/
void locker();          /*寄存柜*/

/*菜单部分的可操作变量初始化，方便操作首位用0替代*/
char state[16][15]={"0","未启用","未启用","未启用","未启用","未启用","未启用","未启用","未启用","未启用","未启用","未启用","未启用","未启用","未启用","未启用"};
int number[1000]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

/*本程序的输入大部分均为int型，非法字符输入会导致程序奔溃，对非int型输入采用强制退出*/

int main()
{
    srand(time(NULL));          //埋下时间种子

    printf("\n");
    printf("\n");
    printf("              * * * * * * ****************** * * * * * * *\n");
    printf("              *                                          *\n");
    printf("              *           实验四：自动寄存柜             *\n");
    printf("              *                                          *\n");
    printf("              * * * * * * ****************** * * * * * * *\n");
    printf("\n");
    printf("\n");
    
    locker();             /*寄存柜*/

    return 0;
}

void menu()              /*菜单*/
{
    printf("             ┏━━━━━━━━━━━━━━━━━━┓━━━━━━┏━━━━━━━━━━━━━━━━━━┓             \n");
    printf("             ┃                  ┃******┃                  ┃             \n");
    printf("             ┃                  ┃******┃                  ┃             \n");
    printf("             ┃                  ┃******┃                  ┃             \n");
    printf("             ┃                  ┃******┃                  ┃             \n");
    printf("             ┃%2d号        %6s┃******┃%2d号        %6s┃             \n",number[1],state[1],number[2],state[2]);
    printf("             ┃━━━━━━━━━━━━━━━━━━┛━━━━━━┗━━━━━━━━━━━━━━━━━━┃             \n");
    printf("             ┃          ┃欢迎使用XX超市的寄存柜┃          ┃             \n");
    printf("             ┃%2d号%6s┃                      ┃%2d号%6s┃             \n",number[3],state[3],number[4],state[4]);
    printf("             ┃━━━━━━━━━━┃请输入以下编号进行寄存┃━━━━━━━━━━┃             \n");
    printf("             ┃          ┃                      ┃          ┃             \n");
    printf("             ┃%2d号%6s┃   1：投硬币寄存      ┃%2d号%6s┃             \n",number[5],state[5],number[6],state[6]);
    printf("             ┃━━━━━━━━━━┃   2：输密码取走      ┃━━━━━━━━━━┃             \n");
    printf("             ┃          ┃   0：退出            ┃          ┃             \n");
    printf("             ┃%2d号%6s┃                      ┃%2d号%6s┃             \n",number[7],state[7],number[8],state[8]);
    printf("             ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃             \n");
    printf("             ┃%2d号        %6s┃******┃%2d号        %6s┃             \n",number[9],state[9],number[10],state[10]);
    printf("             ┃━━━━━━━━━━━━━━━━━━┃******┃━━━━━━━━━━━━━━━━━━┃             \n");
    printf("             ┃%2d号        %6s┃******┃%2d号        %6s┃             \n",number[11],state[11],number[12],state[12]);
    printf("             ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃             \n");
    printf("             ┃           ┃           ┃                    ┃             \n");
    printf("             ┃           ┃           ┃                    ┃             \n");
    printf("             ┃           ┃           ┃                    ┃             \n");
    printf("             ┃           ┃           ┃                    ┃             \n");
    printf("             ┃%2d号 %6s┃%2d号 %6s┃%2d号          %6s┃             \n",number[13],state[13],number[14],state[14],number[15],state[15]);
    printf("             ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛             \n");
    printf("\n");
    printf("其他功能：3 - 重新设置柜子数量\n          4 - 找回密码");
    printf("\n\n欢迎加入VIP会员，可享受免费寄存、自由选择想要的柜子等服务。一年只要99元。");
    printf("\n");
    printf("\n");
}

void locker()               /*寄存柜*/
{
    int i,much;            /*定义变量much对柜子的数量、更新、计次等方面都有使用*/
    int choice,coin;       /*choice是选项，coin是投币值*/
    int t[1000]={0},a[1000]={0};      /*数组t是对柜子状态的判断（0-未启用 1-空 2-满），数组a是程序内部储存4位密码*/
    int d;

    printf("\n寄存柜总数：");         /*由使用者定义柜子总数*/
    if(scanf("%d",&much)!=1){
        printf("\n输入非法字符，自动退出程序. . .");
        system("pause");
        exit(0);
    }
    if(much<0){                           //柜子数必须大于等于0（实际必须大于0）
        printf("输入非法柜子数量. . .");
        system("pause");
        exit(0);
    }
    for(i=1;i<=much;i++){           /*修改寄存柜外部状态(菜单)*/
        strcpy(state[i],"空");
        if(i==15) break;
    }
    for(i=1;i<=much;i++){          /*修改寄存柜内部状态*/
        t[i]=1;
    }

    do{
    menu();
    if(much>=15) printf("您好，当前实际一共可用%d个柜子。",much);  /*寄存柜外部只有15个，所以大于等于15会提示用户*/
    printf("\n请选择：");
    if(scanf("%d",&choice)!=1){
        system("CLS");
        printf("\n输入非法字符，自动退出程序. . .");
        system("pause");
        exit(0);
    }
        switch (choice)
        {
        case 1:                                             /*寄存柜寄存*/
        {
            int F=0,box;
            char vip[1000];
            d=rand()%(9999-1000+1)+1000;     /*保证密码当前的唯一性，使用d生成随机4位密码*/
            for(i=0;i<=much;i++){
                if(t[i]==2) F++;
            }
            if(F==much){
                printf("\n非常抱歉，当前柜子已满。\n\n");
                system("pause");
                system("CLS");
                break;
            }
            
            printf("\n是否确认存放：");
            getchar();                                               //取回车符
            gets(vip);                                            /*VIP用户寄存，无需硬币*/
            if(strcmp(vip,"VIP2022")==0||strcmp(vip,"vip2022")==0){    //确认密码
                printf("\nVIP用户您好，请自由选择您需要存放的柜子：");
                if(scanf("%d",&box)!=1){
                    system("CLS");
                    printf("\n输入非法字符，自动退出程序. . .");
                    system("pause");
                    exit(0);
                }
                if(box<=0||box>much||t[box]==2){                     //判断柜子非法条件
                    printf("\n没有该编号的柜子或当前柜子已满。\n");
                    system("pause");
                    system("CLS");
                    break;
                }
                else{                                               //打印寄存情况
                    Sleep(1000);
                    printf("\n寄存柜编号：%2d  密码：%d\n",box,d);
                    a[box]=d;
                    t[box]=2;
                    if(box<=15) memset(state[box], '\0', sizeof(state[box]));
                    if(box<=15) strcpy(state[box],"满");
                    printf("\n您的密码是【%d】，请妥善保管好您的密码，若有丢失请联系工作人员，谢谢！",a[box]);
                    system("pause");
                    system("CLS");
                    break;
                }
            }
            printf("\n投币值：");
            if(scanf("%d",&coin)!=1){
                system("CLS");
                printf("\n输入非法字符，自动退出程序. . .");
                system("pause");
                exit(0);
            }
            if(coin!=1){                               //只能投1元硬币判断
                system("CLS");
                printf("\n投币失败，仅支持1元硬币。\n");
                system("pause");
                system("CLS");
            }else{
                for(i=1;i<=much;i++){                   /*东西寄存*/
                    if(t[i]==1){        //for数组循环，找到第一个还是空的柜子
                        Sleep(1000);    //当输入操作小于1秒会导致随机数失效，放入Sleep函数暂停1秒
                        printf("\n寄存柜编号：%2d  密码：%d\n",i,d);    //告知用户当前寄存情况
                        a[i]=d;        //记录密码
                        t[i]=2;        //内部状态设置为2-满
                        if(i<=15) memset(state[i], '\0', sizeof(state[i]));    //先申请新的内存
                        if(i<=15) strcpy(state[i],"满");                       //再更改外部状态
                        printf("\n您的密码是【%d】，请妥善保管好您的密码，若有丢失请联系工作人员，谢谢！",a[i]);  //再次提示用户
                        system("pause");
                        system("CLS");
                        break;        //跳出循环
                    }else{
                        continue;      //非空继续循环，防止被覆盖
                    }
                }
                F=0;
            }
            break;
        }
        case 2:                                             /*寄存柜取东西*/
        {
            int L=0,flag_p=0,password;   //L作为统计柜子空的数量，用于判断是否全为空
            for(i=1;i<=much;i++){
                if(t[i]==1) L++;
            }
            if(L==much){
                printf("\n非常抱歉，当前柜子全为空。\n\n");
                system("pause");
                system("CLS");
                break;
            }else{
                printf("\n输入密码：");
                if(scanf("%d",&password)!=1){
                    system("CLS");
                    printf("\n输入非法字符，自动退出程序. . .");
                    system("pause");
                    exit(0);
                }
                for(i=1;i<=much;i++){                   /*取东西*/
                    if(password==a[i]){                 //判断输入密码和密码数组中的元素是否相等
                        flag_p=0;                      //flag_p用于判断有没有找到密码，每次需要初始化为0
                        printf("\n%2d号寄存柜已打开。\n\n",i);
                        t[i]=1;                        //内部状态设置为1-空
                        a[i]=0;                        //重新将密码设为0（无）
                        if(i<=15) memset(state[i], '\0', sizeof(state[i]));  //先申请新的内存
                        if(i<=15) strcpy(state[i],"空");                     //再更改外部状态
                        system("pause");
                        system("CLS");
                        break;
                    }else{
                        flag_p++;                    //没有找到flag_p次数增加
                    }
                }
                if(flag_p==much){
                    printf("\n未找到该密码对应的寄存柜，请尝试重新输入. . .");
                    system("pause");
                    system("CLS");
                }
                    flag_p=0;                        //重新初始化flag_p为0
            }
            break;
        }
        case 5:                                             /*寄存柜管理员系统*/
        {
            char admin[10];                          //管理员密码
            int b[1000]={0},flaga=0,O=0;             //数组b用于登记非法柜子，flaga用于记录是否均为空，O是为了逗号的输出
            printf("\n欢迎进入管理员系统，请输入万能密码：");
            scanf("%s",admin);
            system("CLS");
            if(strcmp(admin,"000086")==0){
                printf("\n密码正确。\n");
                printf("\n柜子已经全部打开，");
                for(i=1;i<=much;i++){
                    if(t[i]==2){           //查找2-满的柜子
                        b[i]++;           //数组b记录
                        flaga=0;
                        t[i]=1;           //打开柜子
                    }else{
                        flaga++;
                    }
                }
                if(flaga==much){
                    printf("寄存柜均为空。\n\n");
                    system("pause");
                    system("CLS");
                }else{
                    printf("请重点检查");
                    for(i=1;i<=much;i++){
                        if(b[i]==1){
                            printf("柜子编号%-2d",i);
                            O=1;
                        }
                        if(O==1) printf("，");
                        O=0;
                    }
                    printf("是否有物留存。\n\n");
                    //menu();
                    system("pause");
                    system("CLS");
                }
            }else{
                printf("\n密码错误，请重新输入。");
                system("pause");
                system("CLS");
                break;
            }
            break;
        }
        case 3:                                             /*寄存柜空间扩大或缩小*/
        {
            int window;                            //重新输入柜子的数量
            printf("\n请输入开关到多少个柜子：");
            if(scanf("%d",&window)!=1){
                system("CLS");
                printf("\n输入非法字符，自动退出程序. . .");
                system("pause");
                exit(0);
            }
            if(window==much){                  //没有更改直接跳过设置
                printf("\n设置完成。");
                system("pause");
                system("CLS");
                break;
            }else{
                if(window>=much){
                    for(i=much+1;i<window+1;i++){    /*much->window设置*/
                        strcpy(state[i],"空");      //更新外部状态
                        if(i==15) break;
                    }
                    for(i=much+1;i<window+1;i++){
                        t[i]=1;                    //更新内部状态
                    }
                    much=window;                  //更新much+1的值，不然会覆盖一个柜子
                    printf("\n设置成功。");
                    system("pause");
                    system("CLS");
                    break;
                }else{
                    for(i=window+1;i<much+1;i++){    /*window->much设置*/
                        memset(state[i], '\0', sizeof(state[i]));  //先申请新的内存
                        strcpy(state[i],"未启用");                 //然后更改外部状态
                        if(i==15) break;
                    }
                    for(i=window+1;i<much+1;i++){
                        if(t[i]==2) printf("\n\n编号%d的柜子被当前操作已强制取消使用。",i);  //提示用户部分柜子被拆除
                        t[i]=0;                               //更新内部状态
                    }
                    much=window;                  //更新much-1的值，不然会覆盖一个柜子
                    printf("\n设置完成。");
                    system("pause");
                    system("CLS");
                    break;
                }
            }
            break;
        }
        case 4:                                             /*获取柜子对应密码，不进行自动打开柜子*/
        {
            int U,adv=1;           //U是输入柜子编号，adv是广告编号
            adv=rand()%(6-1+1)+1;  //广告一共6个，取1-6的随机数
            printf("\n查询密码，请输入柜子编号：");
            if(scanf("%d",&U)!=1){
                printf("\n输入错误，自动退出程序. . .");
                system("pause");
                exit(0);
            }
            if(U==0||U>much){         //柜子编号不存在
                printf("\n无该编号的柜子\n\n");
                system("pause");
                system("CLS");
                break;
            }else if(a[U]==0){      //柜子编号本身为空
                printf("\n您查询的柜子为空。\n\n");
                system("pause");
                system("CLS");
                break;
            }else{                 //忘记密码会有"小惩罚"（看广告）
                system("CLS");
                char adv_1[200]={"                   把心意藏在瓶子里，每天百事可乐！"};
                char adv_2[200]="                    想要春日仪式感？就在#肯德基疯狂星期四#\n\n                    【热辣香骨鸡】15块 ￥19.9，热辣咸香\n\n                    春日美味就在肯德基疯四，等你来，别错过～";
                char adv_3[200]="                    广告招募中，欢迎联系陈先生138XXXXXXXX。";
                char adv_4[200]="                    戴口罩、勤洗手，测体温、勤消毒，少聚集、勤通风。";
                char adv_5[200]="                    弘扬志愿精神，播撒爱心火种，共建和谐社会。";
                printf("\n该柜子存在，成功查询密码需要等待15秒以内的广告，感谢您的理解！\n\n");
                if(adv==1){
                    system("color 09");
                    printf("\n\n\n\n\n");//百事可乐
                    for(i=0;adv_1[i]!='\0';i++){
                        printf("%c",adv_1[i]);
                        Sleep(100);
                    }
                    printf("\n\n");
                    system("img\\1.jpg");                                     //打开图片
                    Sleep(8000);
                }
                if(adv==2){
                    system("color CF");
                    printf("\n\n\n\n\n");                                  //疯狂星期四
                    for(i=0;adv_2[i]!='\0';i++){
                        printf("%c",adv_2[i]);
                        Sleep(100);
                    }
                    printf("\n\n");
                    system("img\\2.jpg");                                    //打开图片
                    Sleep(8000);
                }
                if(adv==3){
                    system("color 1F");                                 //招募广告
                    printf("\n\n\n\n\n");
                    for(i=0;adv_3[i]!='\0';i++){
                        printf("%c",adv_3[i]);
                        Sleep(100);
                    }
                    printf("\n\n");
                    system("img\\3.jpg");                                    //打开图片
                    Sleep(8000);
                }
                if(adv==4){
                    system("color 87");                                 //疫情广告
                    printf("\n\n\n\n\n");
                    for(i=0;adv_4[i]!='\0';i++){
                        printf("%c",adv_4[i]);
                        Sleep(100);
                    }
                    printf("\n\n");
                    Sleep(8000);
                }
                if(adv==5){
                    system("color 1F");                                 //招募广告
                    printf("\n\n\n\n\n");
                    for(i=0;adv_3[i]!='\0';i++){
                        printf("%c",adv_3[i]);
                        Sleep(100);
                    }
                    printf("\n\n");
                    system("img\\3.jpg");                                    //打开图片
                    Sleep(8000);
                }
                if(adv==6){
                    system("color 97"); 
                    printf("\n\n\n\n\n");                                //志愿者广告
                    for(i=0;adv_4[i]!='\0';i++){
                        printf("%c",adv_4[i]);
                        Sleep(100);
                    }
                    printf("\n\n");
                    Sleep(8000);
                }
                system("color 07");                                    //恢复正常黑白颜色界面
                system("CLS");
                printf("\n您好，密码查询成功，您的密码为：%4d。请保管好您的密码不要再丢失了。\n\n",a[U]);
                system("pause");
                system("CLS");
                break;
            }
            system("pause");
            system("CLS");
        }
        case 0:                                             /*退出程序*/
            system("CLS");
            printf("\n感谢您的使用，欢迎下次光临！");
            system("pause");
            break;
    
        default:                                             /*错误输入*/
            system("CLS");
            printf("\n输入错误，请重新输入！");
            system("pause");
            break;
        }
    }while(choice!=0);                   /*do-while+switch函数实现整个框架*/
}