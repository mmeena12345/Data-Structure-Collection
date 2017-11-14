#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#include"dsa.h"
int stack_arr[MAX];
int top = -1;
void Stack()
{
void Stack_linkedlist()
{
    struct node
{
	int info;
	struct node *link;
}*top=NULL;

int isEmpty()
{
	if(top == NULL)
		return 1;
	else
		return 0;
}/*isEmpty()*/


void push(int item)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	if(tmp==NULL)
	{
		printf("Stack Overflow\n");
		return ;
	}
	tmp->info=item;
	tmp->link=top;
	top=tmp;
}/*End of push()*/

int pop()
{
	struct node *tmp;
	int item;
	if( isEmpty() )
	{
		printf("Stack Underflow\n");
		return ;
	}
	tmp=top;
	item=tmp->info;
	top=top->link;
	free(tmp);
	return item;
}/*End of pop()*/

int peek()
{
	if( isEmpty() )
	{
		printf("Stack Underflow\n");
		return;
	}
	return top->info;
}/*End of peek() */

void display()
{
	struct node *ptr;
	ptr=top;
	if(isEmpty())
	{
		printf("Stack is empty\n");
		return;
	}
	printf("Stack elements :\n\n");
	while(ptr!=NULL)
	{
		printf(" %d\n",ptr->info);
		ptr=ptr->link;
	}
	printf("\n");
}/*End of display()*/

int choice,item;
	while(1)
	{
	    printf("\n Menu \n");
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Display item at the top\n");
		printf("4.Display all items of the stack\n");
		printf("5.return to stack\n");
		printf("6.exit\n");

		printf("Enter your choice : ") ;
		scanf("%d", &choice);

		switch(choice)
		{
		case 1:
			printf("Enter the item to be pushed : ");
			scanf("%d",&item);
			push(item);
			break;
		case 2:
			item=pop();
			printf("Popped item is : %d\n",item);
			break;
		case 3:
			printf("Item at the top is %d\n",peek());
			break;
		case 4:
			display();
			break;
		case 5:
			Stack();
			break;
        case 6:
            exit(1);
		default :
			printf("Wrong choice\n");
		}/*End of switch */
	}/*End of while */

}

void Stack_Array()
{

int isFull()
{
	if( top == MAX-1 )
		return 1;
	else
		return 0;
}/*End of isFull*/

 void push(int item)
{
	if( isFull() )
	{
		printf("Stack Overflow\n");
		return;
	}
	top = top+1;
	stack_arr[top] = item;
}/*End of push()*/

int isEmpty()
{
	if( top == -1 )
		return 1;
	else
		return 0;
}/*End of isEmpty*/

int pop()
{
	int item;
	if( isEmpty() )
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	item = stack_arr[top];
	top = top-1;
	return item;
}/*End of pop()*/

int peek()
{
	if( isEmpty() )
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	return stack_arr[top];
}/*End of peek()*/

void display()
{
	int i;
	if( isEmpty() )
	{
		printf("Stack is empty\n");
		return;
	}
    printf("Stack elements :\n\n");
	for(i=top;i>=0;i--)
		printf(" %d\n", stack_arr[i] );
	printf("\n");
}/*End of display()*/

int choice,item;
	while(1)
	{
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Display the top element\n");
		printf("4.Display all stack elements\n");
		printf("5.Quit\n");
		printf("6.Return to Stack\n");

		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		 case 1 :
			printf("Enter the item to be pushed : ");
			scanf("%d",&item);
			push(item);
			break;
		 case 2:
			item = pop();
			printf("Popped item is : %d\n",item );
			break;
		 case 3:
			printf("Item at the top is : %d\n", peek() );
			break;
		 case 4:
			display();
			break;
		 case 5:
			exit(1);
         case 6:
            Stack();
		 default:
			printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while*/
}
int ch;
do
{
    printf("\n MANU \n");
    printf("1.linklist implementation\n");
    printf("2.Array implementation\n");
    printf("3.Return to Main\n");
    printf("4.Exit\n");

    printf("Enter your choice\n");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
        Stack_linkedlist();
        break;
    case 2:
        Stack_Array();
        break;
    case 3:
        main();
        break;
    case 4:
        exit(1);
    default:
        printf("wrong choice\n");
    }
}
while(1);
}
