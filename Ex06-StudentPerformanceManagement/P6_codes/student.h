#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <math.h>

#define MAX 100
#define SUBJECT 20

struct student                 //学生成绩
{
    char num[11];
    char *name[20];
    int score[SUBJECT];
    int m;
    float sum;
    float avg;
}s1[MAX];