#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 30
#define S 10
#define W 6

typedef struct student
{
    long num;
    char name[S];
    int score[W];
}STUDENT;

STUDENT stu[N];
STUDENT* pt = stu;


/*函数原型声明*/
void Menu();//菜单
void Input(STUDENT stu[], int n, int m);//录入数据
void TotalAverage_Subject(STUDENT stu[], int n, int m);//课程总分和平均分
void TotalAverage_Student(STUDENT stu[], int n, int m);
void Seqencing_Score(STUDENT stu[], int n, int m, int (*f)(int a, int b));//成绩排序
void Seqencing_Num(STUDENT stu[], int n, int m);//学号排序
void Dictionary_Order(STUDENT stu[], int n, int m);//字典顺序排序
void LookupBy_Num(STUDENT stu[], int n, int m);//按学号查找
void LookupBy_Name(STUDENT stu[], int n, int m);//按姓名查找
void Statistic_Analysis(STUDENT stu[], int n, int m);//数据分析
void List_Record(STUDENT stu[], int n, int m, int (*f)(int a, int b));
void Total(STUDENT stu[], int sum[N], int n, int m);
void Grade_Table(STUDENT stu[], int sum[], int n, int m);
void Swap(int* x, int* y, long* a, long* b, char* j, char* k,int *c,int *d);//交换函数
int Ascending(int a, int b);//返回a<b
int Descending(int a, int b);//返回a>b


/*函数定义*/
void Menu()
{
    for (int i = 0; i <= 45; i++)
        printf("=");
    printf("\n");
    printf("1. Input record\n");
    printf("2. Calculate total and average score of every course\n");
    printf("3. Calculate total and average score of every student\n");
    printf("4. Sort in descending order by total score of every student\n");
    printf("5. Sort in asending order by total score of every student\n");
    printf("6. Sort in ascending order by number\n");
    printf("7. Sort in dictionary order by name\n");
    printf("8. Search by number\n");
    printf("9. Search by name\n");
    printf("10.Statistic analysis\n");
    printf("11.	List record\n");
    printf("0.Exit\n");
    for (int i = 0; i <= 45; i++)
        printf("=");
    printf("\n");
    printf("please enter your choice:\n");
}

void Input(STUDENT stu[], int n, int m)//录入数据
{
    //memset(score, 0, sizeof(score)); //初始化成绩数组
    printf("Please enter the ID,name and score：\n");
    printf("ID\tname\t");
    for (int i = 0; i < m; i++)
    {
        printf("subject%d\t", i + 1);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%ld %s", &stu[i].num,&stu[i].name);
        for(int j=0;j<m;j++)
        scanf("%d",&stu[i].score[j]);
    }
    printf(".......\n");
    printf("After data entry:\n");
}

void TotalAverage_Subject(STUDENT stu[], int n, int m)//计算课程总分和平均分
{
    int i, j, sum[W];
    for (i = 0; i < m; i++)
    {
        sum[i] = 0;
        for (j = 0; j < n; j++)
        {
            sum[i] =sum[i]+stu[j].score[i];
        }
    }
    printf("\t\tTotal\tAverage\n");
    for (i = 0; i < m; i++)
    {
        printf("Subject%d:\t%d\t%0.2f\n", i + 1, sum[i], (float)sum[i] / n);
    }
}

void TotalAverage_Student(STUDENT stu[], int n, int m)
{
    int i, sum[N];
    Total(stu, sum, n, m);
    printf("ID\tName\tTotal\tAverage\n");
    for (i = 0; i < n; i++)
    {
        printf("%ld\t%s\t%d\t%0.2f\n", stu[i].num, stu[i].name, sum[i], (float)sum[i] / n);
    }
}

void Seqencing_Score(STUDENT stu[], int n, int m, int (*f)(int a, int b))//排序
{
    int i, j, k, sum[N],temp_;
    STUDENT temp;
    Total(stu, sum, n,m);
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if ((*f)(sum[j], sum[k]))
                k = j;
        }
        if (k != i)
        {
            temp = stu[i];
            stu[i] = stu[k];
            stu[k] = temp;
            temp_ = sum[i];
            sum[i] = sum[k];
            sum[k] = temp_;
            //Swap(&score[i], &score[k], &num[i], &num[k], name[i], name[k],&sum[i],&sum[k]);
        }
    }
    Grade_Table(stu, sum, n, m);
}

void Seqencing_Num(STUDENT stu[], int n, int m)//排序
{
    int i, j, k,sum[N],temp_;
    STUDENT temp;
    Total(stu, sum, n, m);
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (stu[j].num < stu[k].num)
                k = j;
        }
        if (k != i)
        {
            temp = stu[i];
            stu[i] = stu[k];
            stu[k] = temp;
            temp_ = sum[i];
            sum[i] = sum[k];
            sum[k] = temp_;
            //Swap(&score[i], &score[k], &num[i], &num[k], name[i], name[k],&sum[i],&sum[k]);
        }
    } 
    Grade_Table(stu, sum, n, m);
}

void Dictionary_Order(STUDENT stu[], int n, int m)
{
    int i, j, k,sum[N],temp_;
    STUDENT temp;
    Total(stu, sum, n, m);
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(stu[j].name, stu[k].name) < 0)
                k = j;
        }
        if (k != i)
        {
            temp = stu[i];
            stu[i] = stu[k];
            stu[k] = temp;
            temp_ = sum[i];
            sum[i] = sum[k];
            sum[k] = temp_;
          // Swap(&score[i], &score[k], &num[i], &num[k], name[i], name[k],&sum[i],&sum[k]);
        }
    }
    Grade_Table(stu, sum, n, m);
}

void LookupBy_Num(STUDENT stu[], int n, int m)
{
    long Num_ = 0;
    int x = -1, i;
    printf("please enter number you want search:\n");
    scanf("%ld", &Num_);
    for (i = 0; i < n; i++)
    {
        if (Num_ == stu[i].num)
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
        printf("ID\tname\t");
        for (i = 0; i < m; i++)
        {
            printf("subject%d\t", i + 1);
        }
        printf("\n%ld\t%s\t", stu[x].num, stu[x].name);
        for (i = 0; i < m; i++)
        {
            printf("%d\t\t", stu[x].score[i]);
        }
        printf("\n");
    }
}

void LookupBy_Name(STUDENT stu[], int n, int m)
{
    char Name_[S]={0};
    int x = -1, i, r;
    printf("please enter name you want search:\n");
    scanf("%s", Name_);
    for (i = 0; i < n; i++)
    {
        r = strcmp(Name_,stu[i].name);
        if (!r)
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
        printf("ID\tname\t");
        for (i = 0; i < m; i++)
        {
            printf("subject%d\t", i + 1);
        }
        printf("\n%ld\t%s\t", stu[x].num, stu[x].name);
        for (i = 0; i < m; i++)
        {
            printf("%d\t\t",stu[x].score[i]);
        }
        printf("\n");
    }
}

void Statistic_Analysis(STUDENT stu[], int n, int m)
{
    
    for (int j = 0; j < m; j++)
    {
        int A = 0, B = 0, C = 0, D = 0, E = 0;
        for (int i = 0; i < n; i++)
        {
            if (stu[i].score[j] >= 90 && stu[i].score[j] <= 100)
                A++;
            else if (stu[i].score[j] >= 80 && stu[i].score[j] <= 89)
                B++;
            else if (stu[i].score[j] >= 70 && stu[i].score[j] <= 79)
                C++;
            else if (stu[i].score[j] >= 60 && stu[i].score[j] <= 69)
                D++;
            else if (stu[i].score[j] >= 0 && stu[i].score[j] <= 59)
                E++;
        }
        printf("subject%d:", j + 1);
        printf("\tExcellent:\t%.2f%%\n", (double)A / n * 100);
        printf("\t\tGood:\t%.2f%%\n", (double)B / n * 100);
        printf("\t\tMedium:\t%.2f%%\n", (double)C / n * 100);
        printf("\t\tPass:\t%.2f%%\n", (double)D / n * 100);
        printf("\t\tFailed:\t%.2f%%\n", (double)E / n * 100);
    }

}

void List_Record(STUDENT stu[], int n, int m, int (*f)(int a, int b))
{
    int i, j, k, sum[N], temp_;
    STUDENT temp;
    Total(stu, sum, n, m);
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if ((*f)(sum[j], sum[k]))
                k = j;
        }
        if (k != i)
        {
            temp = stu[i];
            stu[i] = stu[k];
            stu[k] = temp;
            temp_ = sum[i];
            sum[i] = sum[k];
            sum[k] = temp_;
        }
    }
    printf("ID\tName\t");
    for (i = 0; i < m; i++)
    {
        printf("subject%d\t", i + 1);
    }
    printf("TotalScore\tAverage\n");
    for (i = 0; i < n; i++)
    {
        printf("%ld\t%s\t", stu[i].num, stu[i].name);
        for (j = 0; j < m; j++)
        {
            printf("%d\t\t", stu[i].score[j]);
        }
        printf("%d\t\t%0.2f\n", sum[i],(double)sum[i]);
    }
    printf("--------------------------------------\n");
    TotalAverage_Subject(stu, n, m);
}

void Grade_Table(STUDENT stu[], int sum[], int n, int m)
{
    int i, j;
    printf("ID\tName\t");
    for (i = 0; i < m; i++)
    {
        printf("subject%d\t", i + 1);
    }
    printf("TotalScore\n");
    for (i = 0; i < n; i++)
    {
        printf("%ld\t%s\t", stu[i].num, stu[i].name);
        for (j = 0; j < m; j++)
        {
            printf("%d\t\t", stu[i].score[j]);
        }
        printf("%d\n", sum[i]);
    }
}

void Swap(int* x, int* y, long* a, long* b, char* j, char* k,int *c,int *d)
{
    int temp0,temp1;
    long temp2;
    char temp3[S];
    temp0 = *c; *c = *d; *d = temp0;
    temp1 = *x; *x = *y; *y = temp1;
    temp2 = *a; *a = *b; *b = temp2;
    strcpy(temp3, j);
    strcpy(j, k);
    strcpy(k, temp3);
}

void Swap_(STUDENT* x, STUDENT* y,int *a,int *b)
{
    /*STUDENT z;
    int c;
    z = x->stu[];
    *x = *y;
    y = z;*/
}

void Total(STUDENT stu[], int sum[N], int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        sum[i] = 0;
        for (j = 0; j < m; j++)
        {
            sum[i] = sum[i] + stu[i].score[j];
        }
    }
}

int Ascending(int a, int b)
{
    return a < b;
}

int Descending(int a, int b)
{
    return a > b;
}

#pragma once
