#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
int MyRandom (int n,int m); 
int MyRandom_o2h();
int distribution();
int t_choose_s();
int x_choose_y();
int main ()
{
	int sentaku,a=0; //用于菜单
	srand(time(NULL));    //随机函数初始化 提示：只需要埋一次种子即可
	do{
	printf("\n******************实验一：随机数及其应用******************\n\n");
	printf("*   1：求随机数分布情况                                  *\n");
	printf("*   2：“35选7”福利彩券摇奖器                             *\n");
	printf("*   3：“ x选y”通用福利彩券摇奖器                         *\n");
	printf("*   0：退出                                              *\n\n");
	printf("**********************************************************\n\n");
		printf("请输入你的选择：");
		if(scanf("%d",&sentaku)!=1){
			printf("\n输入中含有非法字符，已强制结束程序。\n\n");
			system("pause");
			exit(0);
		}
	switch(sentaku)
	{
		case  1: 
		a=0;
			    distribution();
			    system("pause");
			    system("CLS");           //清屏
			    printf("\n继续操作，");
				break;
		case  2: 
		a=0;
				t_choose_s();
			    system("pause");
			    system("CLS");
			    printf("\n继续操作，");
				break;
		case  3: 
		a=0;
				x_choose_y();
			    system("pause");
			    system("CLS");
			    printf("\n继续操作，");
				break;
		case  0: 
			    system("CLS");
			    printf("\n已结束程序。");
				break;
		default:
			        a++;
                    if(a==3){
							system("CLS");
							printf("\n输入错误次数过多，自动提前结束程序。");
							system("pause");
							exit(0);
					}
			        system("CLS");
			        printf("\n输入错误，请根据菜单输入。");
					break;
		}	
	}while(sentaku!=0);
	system("pause");
	return 0;
}

int MyRandom (int n,int m) //①“真随机数”函数
{
	int a;
	a=rand()%(9999-1000+1)+1000;
	return a;
}

int distribution()    //②随机数分布情况
{
	int a[101]={0};
	int i,d,sum_A=0,sum_B=0;
	printf("\n随机数分布情况\n");
	for(i=1;i<=10000;i++){
		d=rand()%100+1;
		a[d]++; 
	}
	for(d=1;d<=100;d+=10){
		printf("\n%3d: %3d次",d,a[d]);
		printf("    %3d: %3d次",d+1,a[d+1]);
		printf("    %3d: %3d次",d+2,a[d+2]);
		printf("    %3d: %3d次",d+3,a[d+3]);
		printf("    %3d: %3d次",d+4,a[d+4]);
		printf("    %3d: %3d次",d+5,a[d+5]);
		printf("    %3d: %3d次",d+6,a[d+6]);
		printf("    %3d: %3d次",d+7,a[d+7]);
		printf("    %3d: %3d次",d+8,a[d+8]);
		printf("    %3d: %3d次\n",d+9,a[d+9]);
	}
	for(d=1;d<=50;d++){
		sum_A+=a[d];
	}
	for(d=51;d<=100;d++){
		sum_B+=a[d];
	}
	printf("\n其中：\n 1- 50: %4d次，\n\n51-100: %4d次。\n\n",sum_A,sum_B);
	return 0;
}

int t_choose_s()             //③“35选7”福利彩券摇奖器
{
	int i,d;
	int a[36]={0};
	printf("\n“35选7”福利彩券摇奖器\n\n本次开奖结果：\n");
	for(i=1;i<=7;i++){
		d=rand()%35+1;
		if(a[d]!=0){
			i--;
		}
		a[d]++;
	}
	for(i=1;i<=35;i++){
		if(a[i]!=0){
			printf("\n%5d\n",i);
		}
	}
	printf("\n");
	return 0;
}

int x_choose_y()             //④“x选y”通用福利彩券摇奖器
{
	int i,d,x,y;
	printf("\n“x选y”通用福利彩券摇奖器\n\n请输入x的值：");
	if(scanf("%d",&x)!=1){
			system("CLS");
			printf("\n输入中含有非法字符，已强制结束程序。\n\n");
			system("pause");
			exit(0);
	}
	printf("\n请输入y的值：");
	if(scanf("%d",&y)!=1){
			system("CLS");
			printf("\n输入中含有非法字符，已强制结束程序。\n\n");
			system("pause");
			exit(0);
	}
	if(y>x||x<1||y<1){
		printf("\n输入错误，可能y大于x或x和y小于1，请重新输入！\n");
		printf("\n请输入x的值：");
		if(scanf("%d",&x)!=1){
			system("CLS");
			printf("\n输入中含有非法字符，已强制结束程序。\n\n");
			system("pause");
			exit(0);
		}
		printf("\n请输入y的值：");
		if(scanf("%d",&y)!=1){
			system("CLS");
			printf("\n输入中含有非法字符，已强制结束程序。\n\n");
			system("pause");
			exit(0);
		}
		if(y>x||x<1||y<1){
			printf("\n已第二次输入错误，即将返回菜单。\n\n");
			return 0;
		}
	}
	printf("\n本次开奖结果（默认顺序输出）：\n");
	int a[x+1]={0};
	for(i=1;i<=y;i++){
        Sleep(2000);
		d=rand()%x+1;
		if(d>=10) i--;
		else printf("\n%5d\n",d);
	}
	printf("\n");
	return 0;
}