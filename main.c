#include"function.h"

int main()
{
    int score[N], n = 0, order, order1;
    long num[N];
    char name[N][S];
Menu:
    Menu();
    scanf("%d", &order);
    switch (order)
    {

    case 1://录入数据
    enter:
        printf("Please enter the number of people(No more than %d)：\n", N);
        scanf("%d", &n);
        while (n <= 0 || n > N)//检查人数是否合格
        {
            printf("Data error, please re-enter\n");
            scanf("%d", &n);
        }
        Input(num, score, name, n);
        goto Menu;
        break;

    case 2:
        if (n == 0)//检查是否录入数据
        {
            printf("You have not entered data.Will jump to enter data\n......\n");
            goto enter;
        }
        TotalAverage(score, n);
        printf("==============\n1.Return to menu\n2.Exit program\nPlease enter your choice:\n");//提示
        scanf("%d", &order1);
        while (order1 != 1 && order != 2)
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
            goto Exit;
            break;
        }
        break;
    case 3:
        if (n == 0)//检查是否录入数据
        {
            printf("You have not entered data.Will jump to enter data\n......\n");
            goto enter;
        }
        Seqencing(num, score, name, n, Descending);//降序
        printf("==============\n1.Return to menu\n2.Exit program\nPlease enter your choice:\n");//提示
        scanf("%d", &order1);
        while (order1 != 1 && order != 2)
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
            goto Exit;
            break;
        }
        break;
    case 4:
        if (n == 0)//检查是否录入数据
        {
            printf("You have not entered data.Will jump to enter data\n......\n");
            goto enter;
        }
        Seqencing(num, score, name, n, Ascending);//升序
        printf("==============\n1.Return to menu\n2.Exit program\nPlease enter your choice:\n");//提示
        scanf("%d", &order1);
        while (order1 != 1 && order != 2)
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
            goto Exit;
            break;
        }
        break;
    case 5:
        if (n == 0)//检查是否录入数据
        {
            printf("You have not entered data.Will jump to enter data\n......\n");
            goto enter;
        }
        Seqencing2(num, score, name, n);//升序
        printf("==============\n1.Return to menu\n2.Exit program\nPlease enter your choice:\n");//提示
        scanf("%d", &order1);
        while (order1 != 1 && order != 2)
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
            goto Exit;
            break;
        }
        break;
    case 6:
        DictionaryOrder(num, score, name, n);
        printf("==============\n1.Return to menu\n2.Exit program\nPlease enter your choice:\n");//提示
        scanf("%d", &order1);
        while (order1 != 1 && order != 2)
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
            goto Exit;
            break;
        }
        break;
    case 7:
        LookupByNum(num, score, n, name);
        printf("==============\n1.Return to menu\n2.Exit program\nPlease enter your choice:\n");//提示
        scanf("%d", &order1);
        while (order1 != 1 && order != 2)
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
            goto Exit;
            break;
        }
        break;
    case 8:
        LookupByName(num, score, n, name);
        printf("==============\n1.Return to menu\n2.Exit program\nPlease enter your choice:\n");//提示
        scanf("%d", &order1);
        while (order1 != 1 && order != 2)
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
            goto Exit;
            break;
        }
        break;
    case 9:
        StatisticAnalysis(score, n);
        printf("==============\n1.Return to menu\n2.Exit program\nPlease enter your choice:\n");//提示
        scanf("%d", &order1);
        while (order1 != 1 && order != 2)
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
            goto Exit;
            break;
        }
        break;
    case 10:
        Seqencing2(num, score, name, n);
        printf("------------------\n");
        TotalAverage(score, n);
        printf("==============\n1.Return to menu\n2.Exit program\nPlease enter your choice:\n");//提示
        scanf("%d", &order1);
        while (order1 != 1 && order != 2)
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
            goto Exit;
            break;
        }
        break;
    Exit:
    case 0:
        exit(0);
        break;
    }
    return 0;
}
