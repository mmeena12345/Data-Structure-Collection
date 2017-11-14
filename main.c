#include "dsa.h"
#include "Algo.h"

int main()
{
  void Data_Structure()
{
    int ch;
    do
    {
    printf("\n Menu: \n");
    printf("1: Array\n");
    printf("2: linked list\n");
    printf("3: stack\n");
    printf("4: Queue\n");
    printf("5: Trees\n");
    printf("6: Graph\n");
    printf("7: Return to main\n");
    printf("8: exit\n");

    printf("enter your choice\n");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
        Array();
        break;
    case 2:
        linked_list();
        break;
    case 3:
        Stack();
        break;
    case 4:
        Queue();
        break;
    case 5:
        Tree();
         break;
    case 6:
        Graph();
        break;
    case 7:
        main();
        break;
    case 8:
        exit(1);
    default:
        printf("wrong choice\n");
    }
}
    while(1);
}

 int ch;
 do
    {
        printf("\n Menu \n");
        printf("1.Data Structures Implementation\n");
        printf("2.Algorithms\n");
        printf("3.Exit\n");

        printf("Enter your choice\n");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            Data_Structure();
            break;
        case 2:
            Algo();
            break;
        case 3:
            exit(1);
        default:
            printf("wrong choice\n");
        }
    }
    while(1);
return 0;
}
