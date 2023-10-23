#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void menu();                            //菜单函数
int vendor_system_input(int *sumS);     //输入函数
int vendor_system_output();            //输出函数

//定义全局变量商品名和价格

char name[11][100]={"0","农夫山泉"," 百岁山"," 怡  宝","可口可乐","光明牛奶","青岛啤酒"," 鲜橙多"," 雪  碧"," 乌龙茶"," 绿  茶"};
int money[11]={0,1,1,1,2,2,3,3,3,4,4};

//int类型输入其他类型会死循环，均在输入的同时判断类型，同时立刻退出程序。

int main()
{
    /*管理员系统*/
    printf("欢迎光临，请按回车继续进入购买界面。\n");
    char pass[1000],passw[12]="2022A_a2202";        //管理员密码
    gets(pass);
    if(strcmp(pass,passw)==0){
        int id,modify;
        printf("\n欢迎进入管理员系统\n");
        printf("\n管理员你好，请仔细按照接下来的要求对【商品名称】和【商品价格】进行修改。\n本次修改暂时仅对本次使用有效！下次使用需要重新修改。（有计划更新成完全修改）\n请勿在价格输入非法字符，谢谢！\n");
        printf("\n这是当前简略的货架商品列表（至多10个商品，价格请控制在2位数并无角、分。）：\n\n");
        printf(" %-2d号商品：%-8s 单价：%2d.0元 ┃ %-2d号商品：%-8s 单价：%2d.0元 ┃\n %-2d号商品：%-8s 单价：%2d.0元 ┃ %-2d号商品：%-8s 单价：%2d.0元 ┃\n %-2d号商品：%-8s 单价：%2d.0元 ┃",1,name[1],money[1],2,name[2],money[2],3,name[3],money[3],4,name[4],money[4],5,name[5],money[5]);
        printf(" %-2d号商品：%-8s 单价：%2d.0元 ┃\n %-2d号商品：%-8s 单价：%2d.0元 ┃ %-2d号商品：%-8s 单价：%2d.0元 ┃\n %-2d号商品：%-8s 单价：%2d.0元 ┃%2d 号商品：%-8s 单价：%2d.0元 ┃\n",6,name[6],money[6],7,name[7],money[7],8,name[8],money[8],9,name[9],money[9],10,name[10],money[10]);
        do{
        printf("\n请输入你需要修改的编号（结束修改输入-1）：");
        if(scanf("%d",&id)!=1){
            printf("\n输入非法字符，自动退出程序. . .");
            system("pause");
            exit(0);
        }
        getchar();
        if(id==-1||(id>10||id<1)){
            printf("\n无该编号商品，请重新输入，结束修改输入-1。\n");
        }else{
            printf("\n请输入你需要修改的商品名（建议在8个字符/4个汉字以内）：");
            free(name[id]);         //保险起见，释放指针数组的空间
            scanf("%s",name[id]);   //输入商品名
            printf("\n请输入修改商品的新价格（请控制在2位数并无角、分，无奇怪字符）：");
            if(scanf("%d",&money[id])!=1){  //输入对应价格
            printf("\n输入非法字符，自动退出程序. . .");
            system("pause");
            exit(0);
            }
        }
        }while(id!=-1);
        printf("\n修改完成，即将进入购买界面. . .\n\n");
        system("pause");
    }
    
    system("CLS");   //清屏
    printf("\n");

    printf("             * * * * * * ****************** * * * * * * *\n");
    printf("             *                                          *\n");
    printf("             *           实验三：自动售货机             *\n");
    printf("             *                                          *\n");
    printf("             * * * * * * ****************** * * * * * * *\n");
    printf("\n");
    printf("\n");
    
    menu();     //放入菜单
    char result=1;
    do{
        vendor_system_output();
        printf("\n继续购买请输入1，退出请输入-1。\n\n");
        scanf("%d",&result);
        system("CLS");
        menu();
    }while(result!=-1);    //do-while循环可以便于多次购买
    
    printf("\n欢迎下次光临！\n\n");
    system("pause");

    return 0;
}

void menu()   //售货机框架
{
    printf("   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("   ┃   ┏━━━┓    ┏━━━┓    ┏━━━┓    ┏━━━┓    ┏━━━┓  ┃              ┃\n");
    printf("   ┃   ┃   ┃    ┃   ┃    ┃   ┃    ┃   ┃    ┃   ┃  ┃              ┃\n");
    printf("   ┃   ┃ 1 ┃    ┃ 2 ┃    ┃ 3 ┃    ┃ 4 ┃    ┃ 5 ┃  ┃ 输入商品编号 ┃\n");
    printf("   ┃   ┃   ┃    ┃   ┃    ┃   ┃    ┃   ┃    ┃   ┃  ┃ ┏━━━━━━━━━━━┓┃\n");
    printf("   ┃   ┗━━━┛    ┗━━━┛    ┗━━━┛    ┗━━━┛    ┗━━━┛  ┃ ┃ 1   2   3 ┃┃\n");
    printf("   ┃ %-8s %-8s %-8s %-8s %-8s ┃ ┃ 4   5   6 ┃┃\n",name[1],name[2],name[3],name[4],name[5]);
    printf("   ┃ ┏━━━━━━┓ ┏━━━━━━┓ ┏━━━━━━┓ ┏━━━━━━┓ ┏━━━━━━┓ ┃ ┃ 7   8   9 ┃┃\n");
    printf("   ┃ ┃￥%2d.0┃ ┃￥%2d.0┃ ┃￥%2d.0┃ ┃￥%2d.0┃ ┃￥%2d.0┃ ┃ ┃清空 0 删除┃┃\n",money[1],money[2],money[3],money[4],money[5]);
    printf("   ┃ ┗━━━━━━┛ ┗━━━━━━┛ ┗━━━━━━┛ ┗━━━━━━┛ ┗━━━━━━┛ ┃ ┗━━━━━━━━━━━┛┃\n");
    printf("   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛              ┃\n");
    printf("   ┃戴口罩、勤洗手，测体温、勤消毒，少聚集、勤通风┃   纸币   硬币┃\n");
    printf("   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓┏━━━━━━━━┓┏━━┓┃\n");
    printf("   ┃   ┏━━━┓    ┏━━━┓    ┏━━━┓    ┏━━━┓    ┏━━━┓  ┃┗━━━━━━━━┛┗━━┛┃\n");
    printf("   ┃   ┃   ┃    ┃   ┃    ┃   ┃    ┃   ┃    ┃   ┃  ┃  ┏━━━━━━━━┓  ┃\n");
    printf("   ┃   ┃ 6 ┃    ┃ 7 ┃    ┃ 8 ┃    ┃ 9 ┃    ┃1 0┃  ┃  ┃确定购买┃  ┃\n");
    printf("   ┃   ┃   ┃    ┃   ┃    ┃   ┃    ┃   ┃    ┃   ┃  ┃  ┗━━━━━━━━┛  ┃\n");
    printf("   ┃   ┗━━━┛    ┗━━━┛    ┗━━━┛    ┗━━━┛    ┗━━━┛  ┃              ┃\n");
    printf("   ┃ %-8s %-8s %-8s %-8s %-8s ┃      找零    ┃\n",name[6],name[7],name[8],name[9],name[10]);
    printf("   ┃ ┏━━━━━━┓ ┏━━━━━━┓ ┏━━━━━━┓ ┏━━━━━━┓ ┏━━━━━━┓ ┃  ┏━━━━━━━━━┓ ┃\n");
    printf("   ┃ ┃￥%2d.0┃ ┃￥%2d.0┃ ┃￥%2d.0┃ ┃￥%2d.0┃ ┃￥%2d.0┃ ┃  ┃         ┃ ┃\n",money[6],money[7],money[8],money[9],money[10]);
    printf("   ┃ ┗━━━━━━┛ ┗━━━━━━┛ ┗━━━━━━┛ ┗━━━━━━┛ ┗━━━━━━┛ ┃  ┗━━━━━━━━━┛ ┃\n");
    printf("   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("   ┃ 货架二：广告招募中，有需要请联系：138XXXXXXXX               ┃\n");
    printf("   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("   ┃                                            ┃  _   _   _     ┃\n");
    printf("   ┃                                            ┃ / \\ / \\ | \\|  |┃\n");
    printf("   ┃                                            ┃ \\   \\   | /|  |┃\n");
    printf("   ┃       ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┓        ┃  \\   \\  |▔ |  |┃\n");
    printf("   ┃       ┃                           ┃        ┃ \\ / \\ / |  \\  /┃\n");
    printf("   ┃       ┃       取    货    口      ┃        ┃  ▔   ▔      ▔  ┃\n");
    printf("   ┃       ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛        ┃上海第二工业大学┃\n");
    printf("   ┃                                            ┃   自动售货机   ┃\n");
    printf("   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("\n");
    printf("\n");
    printf("使用说明：\n");
    printf("购买使用前请先投币，本售货机仅支持1元、2元、5元、10元等纸、硬币。清空请输入0，结束投币请输入-1；\n");
    printf("再选择您需要的商品，输入商品上方的编号，结束选择请输入-1。若余额不足或输入错误也会自动结束购买。\n");
    printf("\n");
    printf("注意：\n");
    printf("请勿输入非法字符等，否则会立刻终止程序，感谢您的使用！\n");
    printf("\n");
    printf("\n");
}

int vendor_system_input(int *sumS)
{
    int coin,i=0,b[20]={0},flag=0;
    int sum=1;                                               //循环会加上-1的值，总金额从1开始
    printf("开始投币：\n");
    do{
        if(scanf("%d",&coin)!=1)
        {
            printf("\n输入非法字符，自动退出程序. . .");
            system("pause");
            exit(0);
        }else if(coin==0){                                   //输入'0'进行退币
            printf("即将退还所有投币...");
            sum=sum-1;
            printf("\n找零：%2d.0 元",sum);
                        
/*详细找零（要求按人民币的实际流通币值，取张数最少）*/
                        printf("（其中：");
int ten=0,five=0,two=0,one=0;
while(sum!=0){
    if(sum-10>=0){
        ten++;
        sum=sum-10;
    }else if(sum-5>=0){
        five++;
        sum=sum-5;
    }else if(sum-2>=0){
        two++;
        sum=sum-2;
    }else if(sum-1>=0){
        one++;
        sum=sum-1;
    }
}
    if(ten>0) printf(" 10元——%d张",ten);
    if(five>0) printf(" 5元——%d张",five);
    if(two>0) printf(" 2元——%d张",two);
    if(one>0) printf(" 1元——%d张",one);
    if(ten==0&&five==0&&two==0&&one==0) printf("无");
                        printf("）\n\n");
                        system("pause");
                        exit(0);
        }else if(coin!=1&&coin!=2&&coin!=5&&coin!=10&&coin!=-1)   //只允许输入流通货币单价
        {
            i++;
            printf("\n您的输入货币有误，还有%d次机会重新输入\n\n",2-i);    //输错2次返回主菜单
            if(i==2){
                printf("\n输错次数过多，停止购买. . .\n\n");
                system("pause");
                exit(0);
            }
            continue;    //保证i++继续执行
        }
        else
        {
            sum+=coin;
            i=0;        //计算总金额
        }
    }while(coin!=-1);        //输入'-1'结束投币
    *sumS=sum;              //返回sum的值
}

int vendor_system_output()
{
    int sum;
    vendor_system_input(&sum);    //引用sum的值

    printf("\n投币成功！当前投币为：%2d.0元\n",sum);   //提示用户当前总金额

    int charge,a[11]={0};          //数组a[11]用于对应商品名输出购买商品
    int i,number,flag=0;
    charge=sum;                 //初始化找零的总金额=投币总金额
    printf("\n开始购买：\n");
    do{
        if(scanf("%d",&number)!=1)
        {
            printf("\n输入非法字符，自动退出程序. . .");
            system("pause");
            exit(0);
        }
        else if(number!=-1&&(number>10||number<1))      //输错编号退出购买
        {
            number=-1;
            printf("\n货架上无该编号的商品！\n");
            break;
        }
        else                                         
        {
            for(i=1;i<=10;i++){
                if(number==i){
                    if(charge-money[i]<0){          //先判断余额是否足够
                        printf("\n余额不足，购买失败。\n");
                        printf("\n找零：%2d.0 元",charge);
                        
/*详细找零（要求按人民币的实际流通币值，取张数最少）*/
                        printf("（其中：");
int ten=0,five=0,two=0,one=0;
while(charge!=0){
    if(charge-10>=0){
        ten++;
        charge=charge-10;
    }else if(charge-5>=0){
        five++;
        charge=charge-5;
    }else if(charge-2>=0){
        two++;
            charge=charge-2;
    }else if(charge-1>=0){
        one++;
        charge=charge-1;
    }
}
    if(ten>0) printf(" 10元——%d张",ten);
    if(five>0) printf(" 5元——%d张",five);
    if(two>0) printf(" 2元——%d张",two);
    if(one>0) printf(" 1元——%d张",one);
    if(ten==0&&five==0&&two==0&&one==0) printf("无");    //没有找零输出'无'
                        printf("）");

/*购买列表*/
                        printf("\n\n本次购买商品列表：\n");
                        for(i=1;i<=10;i++){
                            if(a[i]>0) printf("\n%2d号商品：%-8s | 数量：%2d瓶(个) | 单价：%2d.0 元\n",i,name[i],a[i],money[i]);
                            else flag++;    //flag记录a[i]是否为零
                        }
                        if(flag==10) printf("无");   //flag=10的时候就是没有购买输出'无'
                        printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
                        system("pause");
                        return 0;
                    }else{
                        charge=charge-money[i];
                        a[i]++;
                    }
                }
            }
        }
    }while(number!=-1);
    flag=0;
    printf("\n找零：%2d.0 元",charge);
    printf(" （其中：");

/*详细找零（要求按人民币的实际流通币值，取张数最少）*/
int ten=0,five=0,two=0,one=0;
while(charge!=0){
    if(charge-10>=0){
        ten++;
        charge=charge-10;
    }else if(charge-5>=0){
        five++;
        charge=charge-5;
    }else if(charge-2>=0){
        two++;
            charge=charge-2;
    }else if(charge-1>=0){
        one++;
        charge=charge-1;
    }
}
    if(ten>0) printf(" 10元——%d张",ten);
    if(five>0) printf(" 5元——%d张",five);
    if(two>0) printf(" 2元——%d张",two);
    if(one>0) printf(" 1元——%d张",one);
    if(ten==0&&five==0&&two==0&&one==0) printf("无");
    printf("）");


    printf("\n\n本次购买商品列表：\n");       /*列出商品列表*/
    for(i=1;i<=10;i++){
        if(a[i]>0) printf("\n%2d号商品：%-8s | 数量：%2d瓶(个) | 单价：%2d.0 元\n",i,name[i],a[i],money[i]);
        else flag++;
    }
    if(flag==10) printf("无");
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
}