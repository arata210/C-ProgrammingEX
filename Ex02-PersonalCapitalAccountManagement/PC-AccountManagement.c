#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long size;                         /*当前最近一次的流水号*/
struct LogData{                    /*记录的结构*/
       long logid;                 /*记录ID*/
       char logdate[11];            /*记录发生日期*/
       char lognote[15];            /*记录事件说明*/
       double charge;              /*发生费用：负表示支出，正表示收入*/
       double balance;             /*余额*/
};


long getLogcount(FILE *cfptr)      /*获取文件记录总数*/
{
       long begin,end,logcount;
       fseek(cfptr,0L,SEEK_SET);
       begin=ftell(cfptr);
       fseek(cfptr,size,SEEK_END);
       end=ftell(cfptr);
       logcount=(end-begin)/size-1;
       return logcount;
}


void ListAllLog_1(FILE *cfptr)              /*列出所有收支流水帐*/
{
       struct LogData log;
       fseek(cfptr,0L,SEEK_SET);          /*定位指针到文件开始位置*/
       fread(&log,size,1,cfptr);
       printf("\n单号    日期          说明               收支       余额\n");
       while(!feof(cfptr)){
              printf("%-1ld    %s       %13s%11.2lf%11.2lf\n",
                     log.logid,log.logdate,log.lognote,log.charge,log.balance);
              fread(&log,size,1,cfptr);
       };
}

void QueryLastLog_1(FILE *cfptr)              /*查询显示最后一条记录*/
{
       struct LogData log;
       long logcount;
       logcount=getLogcount(cfptr);
       if(logcount>0)             /*表示有记录存在*/
       {
              fseek(cfptr,size*(logcount-1),SEEK_SET);    /*定位最后记录*/
              fread(&log,size,1,cfptr);                   /*读取最后记录*/
              printf("\n最后一条流水是：\n");
              printf("\n单号：%-6ld\n日期：%-11s\n说明：%-15s\n",
                     log.logid,log.logdate,log.lognote);
              printf("收支：%-10.2lf\n余额：%-10.2lf\n",
                     log.charge,log.balance);        /*显示最后记录内容*/
       }
       else  printf("没有流水记录!\n");
}

void AddNewLog_1(FILE *cfptr)                   /*添加新记录*/
{
       struct LogData log,lastlog;
       long logcount;
       printf("请输入流水日期(格式:2022-03-14)：");
       scanf("%s",log.logdate);
       printf("请输入相关说明：");
       scanf("%s",log.lognote);
       printf("请输入收支情况(收+支-)：");
       scanf("%lf",&log.charge);
       logcount=getLogcount(cfptr);         /*获取记录数*/
 
       if(logcount>0){
              fseek(cfptr,size*(logcount-1),SEEK_SET);
              fread(&lastlog,size,1,cfptr);        /*读入最后记录*/
              log.logid=lastlog.logid+1;         /*记录号按顺序是上次的+1*/
              log.balance=log.charge+lastlog.balance;
       }
       else{                      /*如果文件是初始状态，记录数为0*/
              log.logid=1;
              log.balance=log.charge;
       }
       rewind(cfptr);
       printf("本次单号是：%ld\n",log.logid);
       fwrite(&log,sizeof(struct LogData),1,cfptr);        /*写入记录*/
       fclose(cfptr);
}

void UpdateLog_1(FILE *cfptr){
       struct LogData log[100],logx,update;
       long logcount,id,i,flag=-1;

       printf("\n请输入您需要修改的流水单号：");
       scanf("%d",&id);
       logcount=getLogcount(cfptr);				/*获取记录数*/ 
	rewind(cfptr);
	fread(&logx+1,size,logcount,cfptr);
       for(i=0;i<=logcount;i++){
              if(id==log[i].logid){
                     printf("\n成功找到流水记录！\n");
                     printf("\n单号    日期          说明               收支       余额\n");
                     printf("%-1ld    %s       %13s%11.2lf%11.2lf\n",
                     log[i].logid,log[i].logdate,log[i].lognote,log[i].charge,log[i].balance);
                     flag=i;
                     break;
              }
       }
       rewind(cfptr);
       if(flag!=-1){
              printf("\n请输入流水日期(格式:2022-03-14):");
              scanf("%s",update.logdate);
              printf("请输入相关说明:");
              scanf("%s",update.lognote);
              printf("请输入收支情况(收+支-):");
              scanf("%lf",&update.charge);
              strcpy(log[flag].logdate,update.logdate);
              strcpy(log[flag].lognote,update.lognote);
              if(log[flag].charge!=update.charge){
                     update.balance=log[flag].balance-log[flag].charge+update.charge;
                     log[flag].charge=update.charge;
                     log[flag].balance=update.balance;
                     for(i=flag+1;i<=logcount;i++){
                            log[i].balance=log[i-1].balance+log[i].charge;
                     }
              }
              rewind(cfptr);
		fwrite(&logx+1,size,logcount,cfptr);
              printf("\n修改成功,当前流水如下:\n");
              printf("\n单号:%-6ld\n日期:%-11s\n说明:%-15s\n",
                     log[flag].logid,log[flag].logdate,log[flag].lognote);
              printf("收支:%-10.2lf\n余额:%-10.2lf\n",
                     log[flag].charge,log[flag].balance);  
              system("pause"); 
              system("CLS");
       }else{
              rewind(cfptr);
              system("CLS");
              printf("\n没有找到流水记录，请正确输入单号！现在返回操作菜单。。。");
       }
}

int main(void)
{
       FILE *fp;
       if((fp=fopen("cashbox.dat","ab+"))==NULL){
              printf("无法打开账单记录！\n");
              exit(0);
       }
       size=sizeof(struct LogData);
       char language[20];
       int mychoice,la=1;
       do{
              {
                     printf("\n********** 实验二：个人资金账户管理 *********\n");
                     printf("*     1：增加流水                           *\n*     2：所有流水                           *\n");
                     printf("*     3：最后流水                           *\n*     4：修改流水                           *\n");
                     printf("*     0：结束程序                           *\n");
                     printf("*********************************************\n\n");
                     printf("请输入你的选择：");
                     if(scanf("%d",&mychoice)!=1){
			       printf("\n输入中含有非法字符，已强制结束程序。\n\n");
                            system("pause");
			       exit(0);
		       }
              }
              switch(mychoice){
                     case 1:
                     {
                            fp=fopen("cashbox.dat", "ab+");
                            system("CLS");
                            AddNewLog_1(fp);
                            break;
                     }
                     case 2:                      /*列出所有的收入支出情况*/
                     {
                            fp=fopen("cashbox.dat", "ab+");
                            system("CLS");
                            ListAllLog_1(fp);
                            break;
                     }
                     case 3:                          /*查询最后记录及余额*/
                     {
                            fp=fopen("cashbox.dat", "ab+");
                            system("CLS");
                            QueryLastLog_1(fp);
                            break;
                     }
                     case 4:                          /*修改任意记录及余额*/
                     {
                            fp=fopen("cashbox.dat", "rb+"); //此处要用rb+，否则修改后的所有数据会继续写入
                            system("CLS");
                            ListAllLog_1(fp);
                            UpdateLog_1(fp);
                            fclose(fp); //关闭文件，否则无法更新文件
                            break;
                     }
                     default:
                     {
                            system("CLS");
                            printf("输入错误！请重新输入。。。");
                            break;
                     }
              }
       }while(mychoice!=0);

       if(fclose(fp)){
              printf("无法关闭账单记录！\n");
              exit(0);
       }

       return 0;
}