extern int count;

void descending_sum()
{
    int i,j;
    for(i=1;i<=count;i++)
    {
        for(j=1;j<=count-i;j++)
        {
            if(s1[j].sum<s1[j+1].sum)
            {
                s1[0]=s1[j];
                s1[j]=s1[j+1];
                s1[j+1]=s1[0];
            }
        }
    }
    List();
    printf("\n####按总分降序排序完成####\n");
}

void ascending_sum()
{
    int q,p;
    for(q=1;q<=count-1;q++)
    {
        for(p=q+1;p<=count;p++)
        {
            if(s1[q].sum>s1[p].sum)
            {
                s1[0]=s1[q];
                s1[q]=s1[p];
                s1[p]=s1[0];
            }
        }
    }
    List();
    printf("\n####按总分升序排序完成####\n");
}

void descending_num()
{
    int i,j;
    for(i=1;i<=count;i++)
    {
        for(j=1;j<=count-i;j++)
        {
            if(strcmp(s1[j].num,s1[j+1].num)<0)
            {
                s1[0]=s1[j];
                s1[j]=s1[j+1];
                s1[j+1]=s1[0];
            }
        }
    }
    List();
    printf("\n####按学号降序排序完成####\n");
}

void ascending_num()
{
    int q,p;
    for(q=1;q<=count-1;q++)
    {
        for(p=q+1;p<=count;p++)
        {
            if(strcmp(s1[q].num,s1[p].num)>0)
            {
                s1[0]=s1[q];
                s1[q]=s1[p];
                s1[p]=s1[0];
            }
        }
    }
    List();
    printf("\n####按学号升序排序完成####\n");
}