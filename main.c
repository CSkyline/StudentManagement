#include"function.h"

/*typedef struct student
{
    long num;
    char name[S];
    int score[W];
}STUDENT;

STUDENT stu[N];
STUDENT* pt = stu;*/


int main()
{
    int n = 0,m=0, order, order1;
    //long num[N];
    //char name[N][S];score[N][W],

Menu:
    Menu();
    scanf("%d", &order);
    while (order < 0 || order>11)
    {
        printf("Data error, please re-enter(0-11)\n");
        scanf("%d", &order);
    }
    switch (order)
    {

    case 1://录入数据
    enter:
        printf("Please enter the number of people(No more than %d)：\n", N);
        scanf("%d", &n);
        while (n<=0||n>N)//检查人数是否合格
        {
            printf("Data error, please re-enter\n");
            scanf("%d", &n);
        }
        printf("Please enter the number of test subjects(No more than %d):\n",W);
        scanf("%d", &m);
        while (m <= 0 || m > W)//检查科目是否合格
        {
            printf("Data error, please re-enter\n");
            scanf("%d", &m);
        }
        Input(stu, n,m);
        goto Menu;
        break;


    case 2:
        if (n == 0)//检查是否录入数据
        {
            printf("You have not entered data.Will jump to enter data\n......\n");
            goto enter;
        }
        TotalAverage_Subject(stu, n, m);
        printf("==============\n1.Return to menu\n2.Exit program\nPlease enter your choice:\n");//提示
        scanf("%d", &order1);
        while (order1 != 1 && order1 != 2)
        {
            printf("Data error, please re-enter\n");
            scanf("%d", &order1);
        }
        switch (order1)
        {
        case 1:
            goto Menu;
            break;
        case 2:
            exit(0);
            break;
        }
        break;


    case 3:
        if (n == 0)//检查是否录入数据
        {
            printf("You have not entered data.Will jump to enter data\n......\n");
            goto enter;
        }
        TotalAverage_Student(stu,n,m);//
        printf("==============\n1.Return to menu\n2.Exit program\nPlease enter your choice:\n");//提示
        scanf("%d", &order1);
        while (order1 != 1 && order1 != 2)
        {
            printf("Data error, please re-enter\n");
            scanf("%d", &order1);
        }
        switch (order1)
        {
        case 1:
            goto Menu;
            break;
        case 2:
            exit(0);
            break;
        }
        break;


    case 4:
        if (n == 0)//检查是否录入数据
        {
            printf("You have not entered data.Will jump to enter data\n......\n");
            goto enter;
        }
        Seqencing_Score(stu, n,m,Descending);//升序
        printf("==============\n1.Return to menu\n2.Exit program\nPlease enter your choice:\n");//提示
        scanf("%d", &order1);
        while (order1 != 1 && order1 != 2)
        {
            printf("Data error, please re-enter\n");
            scanf("%d", &order1);
        }
        switch (order1)
        {
        case 1:
            goto Menu;
            break;
        case 2:
            exit(0);
            break;
        }
        break;


    case 5:
        if (n == 0)//检查是否录入数据
        {
            printf("You have not entered data.Will jump to enter data\n......\n");
            goto enter;
        }
        Seqencing_Score(stu, n, m,Ascending);//升序
        printf("==============\n1.Return to menu\n2.Exit program\nPlease enter your choice:\n");//提示
        scanf("%d", &order1);
        while (order1 != 1 && order1 != 2)
        {
            printf("Data error, please re-enter\n");
            scanf("%d", &order1);
        }
        switch (order1)
        {
        case 1:
            goto Menu;
            break;
        case 2:
            exit(0);
            break;
        }
        break;


    case 6:
        Seqencing_Num(stu, n,m);
        printf("==============\n1.Return to menu\n2.Exit program\nPlease enter your choice:\n");//提示
        scanf("%d", &order1);
        while (order1 != 1 && order1 != 2)
        {
            printf("Data error, please re-enter\n");
            scanf("%d", &order1);
        }
        switch (order1)
        {
        case 1:
            goto Menu;
            break;
        case 2:
            exit(0);
            break;
        }
        break;



    case 7:
        Dictionary_Order(stu,n,m);
        printf("==============\n1.Return to menu\n2.Exit program\nPlease enter your choice:\n");//提示
        scanf("%d", &order1);
        while (order1 != 1 && order1 != 2)
        {
            printf("Data error, please re-enter\n");
            scanf("%d", &order1);
        }
        switch (order1)
        {
        case 1:
            goto Menu;
            break;
        case 2:
            exit(0);;
            break;
        }
        break;


    case 8:
        LookupBy_Num(stu, n, m);
        printf("==============\n1.Return to menu\n2.Exit program\nPlease enter your choice:\n");//提示
        scanf("%d", &order1);
        while (order1 != 1 && order1 != 2)
        {
            printf("Data error, please re-enter\n");
            scanf("%d", &order1);
        }
        switch (order1)
        {
        case 1:
            goto Menu;
            break;
        case 2:
            exit(0);
            break;
        }
        break;


    case 9:
        LookupBy_Name(stu, n,m);
        printf("==============\n1.Return to menu\n2.Exit program\nPlease enter your choice:\n");//提示
        scanf("%d", &order1);
        while (order1 != 1 && order1 != 2)
        {
            printf("Data error, please re-enter\n");
            scanf("%d", &order1);
        }
        switch (order1)
        {
        case 1:
            goto Menu;
            break;
        case 2:
            exit(0);
            break;
        }
        break;


    case 10:
        Statistic_Analysis(stu, n, m);
        printf("------------------\n");
       // TotalAverage(score, n);
        printf("==============\n1.Return to menu\n2.Exit program\nPlease enter your choice:\n");//提示
        scanf("%d", &order1);
        while (order1 != 1 && order1 != 2)
        {
            printf("Data error, please re-enter\n");
            scanf("%d", &order1);
        }
        switch (order1)
        {
        case 1:
            goto Menu;
            break;
        case 2:
            exit(0);
            break;
        }
        break;

    case 11:
        if (n == 0)//检查是否录入数据
        {
            printf("You have not entered data.Will jump to enter data\n......\n");
            goto enter;
        }
        List_Record(stu, n, m,Ascending);
        printf("==============\n1.Return to menu\n2.Exit program\nPlease enter your choice:\n");//提示
        scanf("%d", &order1);
        while (order1 != 1 && order1 !=2)
        {
            printf("Data error, please re-enter\n");
            scanf("%d", &order1);
        }
        switch (order1)
        {
        case 1:
            goto Menu;
            break;
        case 2:
            exit(0);
            break;
        }
        break;

    case 0:
        exit(0);
        break;
    }
    return 0;
}
