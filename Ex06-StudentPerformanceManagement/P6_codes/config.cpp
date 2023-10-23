#include "student.h"         //引用头文件
#include "recorder.c"        //引用其他C、C++文件
#include "sorts.c"
#include "time.cpp"

int count=0;                 //全局变量

int main()
{
    FILE *fp;                                      //文件指针 - fp

    FILE *backup;                                  //文件指针 - backup(备份)
    char ch;                                       //从原文件将数据一个个备份到新的文件变量ch

/*另存一份备份文件*/
    fp=fopen("scores.txt","r");                    //打开文件，文件必存在，否则会跳过
    backup=fopen("scores_backup.txt","w+");        //创建并打开新文件，可以进行读写
    fscanf(fp,"%d",&count);                        //读取count当前的数
    if(count==0)                                   //如果count为0，则关闭文件；反之备份文件并关闭两个文件
    {
        fclose(fp);
    }
    else
    {
        while ((ch = fgetc(fp)) != EOF)
        fputc(ch, backup);
        fclose(fp);
        fclose(backup);
    }
    
/*数据导入程序*/
    fp=fopen("scores.txt","a+");                    //打开读写文件
    fscanf(fp,"%d",&count);                         //读取数据到程序中
    for(int t=1;t<=count;t++)
    {
        fscanf(fp,"%d%s%s%f%f",&s1[t].m,s1[t].num,&s1[t].name,&s1[t].sum,&s1[t].avg);
        for(int s=0;s<s1[t].m;s++)
        {
             fscanf(fp,"%d",&s1[t].score[s]);
        }
    }
    printf("\n####数据导入成功！####\n");             //提示用户完成正常读取，并输出当前时间和关闭文件
    time();
    fclose(fp);

/*菜单框架*/
    printf("\n");
    printf("\n");
    printf("              * * * * * * ****************** * * * * * * *\n");
    printf("              *                                          *\n");
    printf("              *          实验六：学生成绩管理            *\n");
    printf("              *                                          *\n");
    printf("              * * * * * * ****************** * * * * * * *\n");
    printf("\n");
    printf("\n");

    printf("        1.追加记录\t2.列出记录\n\n        3.删除记录\t4.修改记录\t5.查找记录\n\n\n");
    printf("        6.按总分降序排序\t7.按总分升序排序\n\n        8.按学号降序排序\t9.按学号升序排序\n\n\n");
    printf("        0.退出程序\n\n\n");
    printf("    注1：本程序会自动从文件中读取数据、写入数据、保存数据。\n");
    printf("    注2：最多限20门分科，分科成绩允许有小数，但会自动取舍。\n");

/*数据处理*/
    int choice;                                          //do-while+switch分类处理各环节
    do
    {
        printf("\n请输入：");
        if(scanf("%d",&choice)!=1)
        {
            printf("\n输入错误！自动保存数据并退出。\n");
            break;
        }
        switch (choice)
        {
        case 1:                  //追加记录
        {
            Append();
            break;
        }
        case 2:                  //列出记录
        {
            List();
            break;
        }
        case 3:                  //删除记录
        {
            Delete();
            break;
        }
        case 4:                  //修改记录
        {
            Modify();
            break;
        }
        case 5:                  //查找记录
        {
            Search();
            break;
        }
        case 6:                  //按总分降序排序
        {
            descending_sum();
            break;
        }
        case 7:                  //按总分升序排序
        {
            ascending_sum();
            break;
        }
        case 8:                  //按学号降序排序
        {
            descending_num();
            break;
        }
        case 9:                  //按学号升序排序
        {
            ascending_num();
            break;
        }
        case 0:                  //退出程序
        {
            printf("是否删除备份？删除请输入‘1’。\n请输入：");        //删除备份
            char q;
            getchar();                                //吸收一个回车字符
            scanf("%c",&q);
            if(q=='1')
            {
                fclose(backup);
                if (remove("scores_backup.txt") == 0)        //删除备份，并提示用户
                {
                    printf("####已删除备份！####\n\n");
                }
            }
            printf("####成功退出程序！####\n");            //完成退出
            break;
        }
        default:
        {
            printf("####输入错误，请重新输入。####\n");
            break;
        }
        }
    }
    while(choice!=0);

/*保存数据到文件*/
    fp=fopen("scores.txt","w+");
    fprintf(fp,"%d\n",count);
    for(int t=1;t<=count;t++)
    {
        fprintf(fp,"%d %s %s %.2f %.2f ",s1[t].m,s1[t].num,&s1[t].name,s1[t].sum,s1[t].avg);
        for(int s=0;s<s1[t].m;s++)
        {
            fprintf(fp,"%d ",s1[t].score[s]);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
    printf("\n####数据导出成功！####\n");
    time();
    
/*检查文件是否有意义*/
    int test;
    fp=fopen("scores.txt","r");        //打开存在文件，读文件
    fscanf(fp,"%d",&test);
    if(test==0)                        //文件没有记录成绩，自动删除文件
    {
        fclose(fp);                    //要先关闭已打开的文件
        remove("scores.txt");
    }
    else
    {
        fclose(fp);
    }

    system("pause");
    return 0;
}