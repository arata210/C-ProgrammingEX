extern int count;        //声明外部变量

void Append()            //追加记录
{
    int i;
    count++;
    printf("\n##请输入学号：");
    scanf("%s",s1[count].num);
    printf("\n##请输入姓名：");
    scanf("%s",&s1[count].name);
    printf("\n##请输入科数：");
    scanf("%d",&s1[count].m);
    if(s1[count].m>20)             //限制科目数
    {
        printf("####追加失败，超出范围，请重新输入。####\n");
        count--;
    }
    else
    {
        printf("\n##请输入各科成绩(空格隔开)：");
        for(i=0;i<s1[count].m;i++){                //导入分科成绩
            float ss;
            scanf("%f",&ss);
            if(ss-(int)ss<0.5) s1[count].score[i]=int(ss);  //四舍五入
            else s1[count].score[i]=int(ss)+1;
            s1[count].sum+=s1[count].score[i];              //计算总分
        }
        s1[count].avg=s1[count].sum/s1[count].m;            //计算平均分
        printf("\n\n##编号：%d\n##学号：%s\n##姓名：%s\n##总分：%.2f\n平均分：%.2f\n",count,s1[count].num,&s1[count].name,s1[count].sum,s1[count].avg);
        printf("\n####追加成功！####\n");
    }
}

void List()            //列出记录
{
    int i,j;
    printf("\n   #学号#      #姓名#   #总分#   #平均分#\n");
    for(i=1;i<=count;i++){
        printf("%8s     %-8s%8.2f%10.2f   ",s1[i].num,&s1[i].name,s1[i].sum,s1[i].avg);
        for(j=0;j<s1[i].m;j++){
            printf("##科目%-2d：%3d分   ",j+1,s1[i].score[j]);
        }
        printf("\n");
    }
    printf("\n####列出完成！####\n");
}

void Search()            //查找记录
{
    char a[11];
    int i,flag=0,j;
    printf("\n##请输入需要查找的学号：");
    scanf("%s",a);
    for(i=1;i<=count;i++)
    {
        if(strcmp(a,s1[i].num)==0)
        {
            printf("\n####查找成功！####\n");
            flag=i;
            break;
        }
    }
    if(flag!=0)
    {
        printf("\n   #学号#      #姓名#   #总分#   #平均分#\n");
        printf("%8s     %-8s%8.2f%10.2f   ",s1[flag].num,&s1[flag].name,s1[flag].sum,s1[flag].avg);
        for(j=0;j<s1[i].m;j++){
            printf("##科目%-2d：%3d分   ",j+1,s1[flag].score[j]);
        }
        printf("\n");
    }
    if(flag==0){
        printf("\n####查找失败！####\n");
    }
}

void Modify()            //修改记录
{
    char a[11];
    int i,flag=0,j;
    printf("\n##请输入需要修改的学号：");
    scanf("%s",a);
    for(i=1;i<=count;i++)
    {
        if(strcmp(a,s1[i].num)==0)
        {
            printf("\n####查找成功！####\n");         //查找记录
            flag=i;
            break;
        }
    }
    if(flag!=0)          //重新填入数据
    {
        printf("\n   #学号#      #姓名#   #总分#   #平均分#\n");
        printf("%8s     %-8s%8.2f%10.2f   ",s1[flag].num,&s1[flag].name,s1[flag].sum,s1[flag].avg);
        for(j=0;j<s1[i].m;j++){
            printf("##科目%-2d：%3d分   ",j+1,s1[flag].score[j]);
        }
        s1[flag].avg=0;
        s1[flag].sum=0;
        printf("\n\n");
        printf("\n##请重新输入学号：");
        scanf("%s",s1[flag].num);
        printf("\n##请重新输入姓名：");
        scanf("%s",&s1[flag].name);
        printf("\n##请重新输入科数：");
        scanf("%d",&s1[flag].m);
        if(s1[flag].m>20)
        {
            printf("####追加失败，超出范围，请重新输入。####\n");
        }
        else
        {
            printf("\n##请输入各科成绩(空格隔开)：");
            for(i=0;i<s1[flag].m;i++){
                s1[flag].score[i]=0;
                float ss;
                scanf("%f",&ss);
                if(ss-(int)ss<0.5) s1[flag].score[i]=int(ss);
                else s1[flag].score[i]=int(ss)+1;
                s1[flag].sum+=s1[flag].score[i];
            }
            s1[flag].avg=s1[flag].sum/s1[flag].m;
            printf("\n####修改成功！####\n");
            printf("\n\n##编号：%d\n##学号：%s\n##姓名：%s\n##总分：%.2f\n平均分：%.2f\n",flag,s1[flag].num,&s1[flag].name,s1[flag].sum,s1[flag].avg);
        }
    }
    if(flag==0){
        printf("\n####查找失败！修改失败！####\n");
    }
}

void Delete()            //删除记录
{
    printf("是否全部删除？全部删除请输入‘1’。\n请输入：");
    getchar();
    char b;
    scanf("%c",&b);
    if(b=='1')
    {
        count=0;          //清空记录
    }
    else
    {
        char a[11];
        int i,flag=0,j;
        printf("\n##请输入需要删除的学号：");
        scanf("%s",a);
        for(i=1;i<=count;i++)
        {
            if(strcmp(a,s1[i].num)==0)         //查找对应学号
            {
                printf("\n####查找成功！");
                flag=i;
                break;
            }
        }
        if(flag!=0)
        {
            for(i=flag;i<=count;i++)
            {
                s1[i]=s1[i+1];            //删除记录
            }
           count--;
            printf("删除成功！####\n");
            List();
        }
        if(flag==0)
        {
        printf("\n####查找失败！删除失败！####\n");
        }
    }
    
}