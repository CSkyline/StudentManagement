#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 30
#define S 10


/*函数原型声明*/
void Menu();//菜单
void Input(long num[], int score[], char name[][S], int n);//录入数据
void TotalAverage(int score[], int n);//总分和平均分
void Seqencing(long num[], int score[], char name[][S], int n, int (*f)(int a, int b));//成绩排序
void Seqencing2(long num[], int score[], char name[][S], int n);//学号排序
void DictionaryOrder(long num[], int score[], char name[][S], int n);//字典顺序排序
void LookupByNum(long num[], int score[], int n,  char name[][S]);//按学号查找
void LookupByName(long num[], int score[], int n,  char name[][S]);//按姓名查找
void StatisticAnalysis(int score[], int n);//数据分析
void Swap(int* x, int* y, long* a, long* b, char* j, char* k);//交换函数
int Ascending(int a, int b);//返回a<b
int Descending(int a, int b);//返回a>b

/*函数定义*/
void Menu()
{
    for (int i = 0; i <= 45; i++)
        printf("=");
    printf("\n");
    printf("1. Input record\n");
    printf("2. Caculate total and average score of course\n");
    printf("3. Sort in descending order by score\n");
    printf("4. Sort in ascending order by score\n");
    printf("5. Sort in ascending order by numberme\n");
    printf("6. Sort in dictionary order by name\n");
    printf("7. Search by number\n");
    printf("8. Search by name\n");
    printf("9. Statistic analysis\n");
    printf("10. List record\n");
    printf("0.Exit\n");
    for (int i = 0; i <= 45; i++)
        printf("=");
    printf("\n");
    printf("please enter your choice:\n");
}

void Input(long num[], int score[], char name[][S], int n)//录入数据
{
    memset(score, 0, sizeof(score)); //初始化成绩数组
    printf("Please enter the ID,name and score：\n");
    printf("ID\tname\tscore\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%ld %s %d", &num[i], name[i], &score[i]);
    }
    printf(".......\n");
    printf("After data entry:\n");
}

void TotalAverage(int score[], int n)//计算总分和平均分
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + score[i];
    }
    printf("Total score:%d\nAverage score:%.2f\n", sum, (double)sum / n);
}

void Seqencing(long num[], int score[], char name[][S], int n, int (*f)(int a, int b))//排序
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if ((*f)(score[j], score[k]))
                k = j;
        }
        printf("%d", score[i]);
        if (k != i)
        {
            Swap(&score[i], &score[k], &num[i], &num[k], name[i], name[k]);
        }
    }
    printf("Score\tName\tID\n");
    for (i = 0; i < n; i++)
        printf("%d\t%s\t%ld\n", score[i], name[i], num[i]);
}

void Seqencing2(long num[], int score[], char name[][S], int n)//排序
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (num[j] < num[k])
                k = j;
        }
        if (k != i)
        {
            Swap(&score[i], &score[k], &num[i], &num[k], name[i], name[k]);
        }
    }
    printf("ID\tName\tScore\n");
    for (i = 0; i < n; i++)
        printf("%ld\t%s\t%d\n", num[i], name[i], score[i]);
}

void DictionaryOrder(long num[], int score[], char name[][S], int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(name[j], name[k]) > 0)
                k = j;
        }
        if (k != i)
        {
            Swap(&score[i], &score[k], &num[i], &num[k], name[i], name[k]);
        }
    }
    printf("Name\tID\tScore\n");
    for (i = 0; i < n; i++)
        printf("%s\t%ld\t%d\n", name[i], num[i], score[i]);
}


void LookupByNum(long num[], int score[], int n, char name[][S])
{
    long Num_=0;
    int x = -1, i;
    printf("please enter number you want search:\n");
    scanf("%ld", &Num_);
    for (i = 0; i < n; i++)
    {
        if (Num_ == num[i])
        {
            x = i;
        }
    }
    if (x == -1)
    {
        printf("Not Found\n");
    }
    else
    {
        printf("ID\tname\tscore\n");
        printf("%ld\t%s\t%d\n", num[x], name[x], score[x]);
    }
}

void LookupByName(long num[], int score[], int n,  char name[][S])
{
    char Name_[S];
    int x = -1, i,r;
    printf("please enter name you want search:\n");
    scanf("%s", Name_);
    for (i = 0; i < n; i++)
    {
        r=strcmp(Name_, name[i]);
        if ( !r)
        {
            x = i;
        }
    }
    if (x == -1)
    {
        printf("Not Found\n");
    }
    else
    {
        printf("name\tID\tscore\n");
        printf("%s\t%ld\t%d\n", name[x], num[x], score[x]);
    }
}

void StatisticAnalysis(int score[], int n)
{
    int A=0, B=0, C=0, D=0, E=0;
    for (int i=0; i < n; i++)
    {
        if (score[i] >= 90 && score[i] <= 100)
            A++;
        if (score[i] >= 80 && score[i] <= 89)
            B++;
        if (score[i] >= 70 && score[i] <= 79)
            C++;
        if (score[i] >= 60 && score[i] <= 69)
            D++;
        if (score[i] >= 0 && score[i] <= 59)
            E++;
    }
    printf("Excellent:\t%.2f%%\n",(double)A / n * 100);
    printf("Good:\t%.2f%%\n", (double)B/ n * 100);
    printf("Medium:\t%.2f%%\n", (double)C / n * 100);
    printf("Pass:\t%.2f%%\n", (double)D / n * 100);
    printf("Failed:\t%.2f%%\n", (double)E / n * 100);
}



int Ascending(int a, int b)
{
    return a < b;
}

int Descending(int a, int b)
{
    return a > b;
}

void Swap(int* x, int* y, long* a, long* b, char* j, char* k)
{
    int temp1;
    long temp2;
    char temp3[S];
    temp1 = *x; *x = *y; *y = temp1;
    temp2 = *a; *a = *b; *b = temp2;
    strcpy(temp3, j);
    strcpy(j, k);
    strcpy(k, temp3);
}



#pragma once
