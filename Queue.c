#include<stdio.h>
#include<stdlib.h>
#include"dsa.h"
#define MAX 10

void Queue()
{
    void Simple_Queue()
    {
   void simple_Queue_array()
   {
       int queue_arr[MAX];
int rear=-1;
int front=-1;

void insert(int item)
{
	int isFull()
{
	if( rear==MAX-1 )
		return 1;
	else
		return 0;
}/*End of isFull()*/

	if( front == -1 )
		front=0;
	rear=rear+1;
	queue_arr[rear]=item ;
}/*End of insert()*/

int del()
{
	int item;

	item=queue_arr[front];
	front=front+1;
	return item;
}/*End of del()*/

int peek()
{
	int isEmpty()
	{
	   if( front==-1 || front==rear+1 )
       {
		printf("Queue Underflow\n");
		exit(1);
       }
	else
		return 0;
	}
	return queue_arr[front];
}/*End of peek()*/

void display()
{
	int i;
 int isEmpty()
	{
	   if( front==-1 || front==rear+1 )
       {
		printf("Queue Underflow\n");
		exit(1);
       }
	else
		return 0;
	}
	printf("Queue is :\n\n");
	for(i=front;i<=rear;i++)
		printf("%d  ",queue_arr[i]);
	printf("\n\n");
}/*End of display() */

int choice,item;
	while(1)
	{
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display element at the front\n");
		printf("4.Display all elements of the queue\n");
		printf("5.Return to simple queue\n");
		printf("6.exit\n");

		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1:
			printf("Input the element for adding in queue : ");
			scanf("%d",&item);
			insert(item);
			break;
		case 2:
			item=del();
			printf("Deleted element is  %d\n",item);
			break;
		case 3:
			printf("Element at the front is %d\n",peek());
			break;
		case 4:
			display();
			break;
		case 5:
             Simple_Queue();
        case 6:
            exit(1);
		default:
			printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while*/
   }

void Queue_by_linkedlist()
{
    struct node
{
	int info;
	struct node *link;
}*front=NULL,*rear=NULL;

int isEmpty_l()
{
	if(front==NULL)
		return 1;
	else
		return 0;

}

void insert_l(int item)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	if(tmp==NULL)
	{
		printf("Memory not available\n");
		return;
	}
	tmp->info = item;
	tmp->link=NULL;
	if(front==NULL)		 /*If Queue is empty*/
		front=tmp;
	else
		rear->link=tmp;
	rear=tmp;
}/*End of insert()*/
int del_l()
{
	struct node *tmp;
	int item;
	if( isEmpty_l( ) )
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	tmp=front;
	item=tmp->info;
	front=front->link;
	free(tmp);
	return item;
}/*End of del()*/
int peek_l()
{
	if( isEmpty_l( ) )
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	return front->info;
}/*End of peek()*/
/*End of isEmpty()*/
void display_l()
{
	struct node *ptr;
	ptr=front;
	if(isEmpty_l())
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements :\n\n");
	while(ptr!=NULL)
	{
		printf("%d ",ptr->info);
		ptr=ptr->link;
	}
	printf("\n\n");
}/*End of display()*/

int choice,item;
	while(1)
	{
	    printf("\n Menu \n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display the element at the front\n");
		printf("4.Display all elements of the queue\n");
		printf("5.return to simple queue\n");
		printf("6.Quit\n");


		printf("Enter your choice : ");
		scanf("%d", &choice);

		switch(choice)
		{
		case 1:
			printf("Input the element for adding in queue : ");
			scanf("%d",&item);
			insert_l(item);
			break;
		case 2:
			printf("Deleted element is  %d\n",del_l());
			break;
		case 3:
			printf("Element at the front of the queue is %d\n", peek_l() );
			break;
		case 4:
			display_l();
			break;
        case 5:
            Simple_Queue();
		case 6:
			exit(1);
		default :
			printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while*/
}

void Queue_by_cirlist()
{
    struct node
{
	int info;
	struct node *link;
}*rear=NULL;

int isEmpty_s()
{
	if( rear == NULL )
		return 1;
	else
		return 0;
}

void insert_s(int item)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=item;
	if(tmp==NULL)
	{
		printf("Memory not available\n");
		return;
	}

	if( isEmpty_s() ) /*If queue is empty */
	{
		rear=tmp;
		tmp->link=rear;
	}
	else
	{
		tmp->link=rear->link;
		rear->link=tmp;
		rear=tmp;
	}
}/*End of insert()*/

int del_s()
{
	int item;
	struct node *tmp;
	if( isEmpty_s() )
	{
		printf("Queue underflow\n");
		exit(1);
	}
	if(rear->link==rear)  /*If only one element*/
	{
		tmp=rear;
		rear=NULL;
	}
	else
	{
		tmp=rear->link;
		rear->link=rear->link->link;
	}
	item=tmp->info;
	free(tmp);
	return item;
}/*End of del()*/

int peek_s()
{
	if( isEmpty_s() )
	{
		printf("Queue underflow\n");
		exit(1);
	}
	return rear->link->info;
}/* End of peek() */

void display_s()
{
	struct node *p;
	if(isEmpty_s())
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue is :\n");
	p=rear->link;
	do
	{
		printf("%d ",p->info);
		p=p->link;
	}while(p!=rear->link);
	printf("\n");
}/*End of display()*/

int choice,item;
	while(1)
	{
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Peek\n");
		printf("4.Display\n");
		printf("5.Quit\n");
		printf("6.Return to Simple Queue\n");

		printf("Enter your choice : ");
		scanf("%d", &choice);

		switch(choice)
		{
		 case 1:
			printf("Enter the element for insertion : ");
			scanf("%d",&item);
			insert_s(item);
			break;
		 case 2:
			printf("Deleted element is %d\n",del_s());
			break;
		 case 3:
			printf("Item at the front of queue is %d\n",peek_s());
			break;
		 case 4:
			display_s();
			break;
		 case 5:
			exit(1);
         case 6:
            Simple_Queue();
		 default:
			printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while*/

}
int ch;
do
{
    printf("\n MENU \n");
    printf("1.simple queue using array \n");
    printf("2.simple queue using linked list\n");
    printf("3.simple queue using circular list\n");
    printf("4.Return to Queue\n");
    printf("5.exit\n");

    printf("Enter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        simple_Queue_array();
        break;
    case 2:
        Queue_by_linkedlist();
        break;
    case 3:
        Queue_by_cirlist();
        break;
    case 4:
        Queue();
        break;
    case 5:
        exit(1);
    default:
        printf("wrong choice\n");
 }
}
while(1);
}

void Circular_Queue()
{
int cqueue_arr[MAX];
int front=-1;
int rear=-1;

int isEmpty_c()
{
	if(front==-1)
		return 1;
	else
		return 0;
}/*End of isEmpty()*/

int isFull_c()
{
	if((front==0 && rear==MAX-1) || (front==rear+1))
		return 1;
	else
		return 0;
}/*End of isFull()*/

void insert_c(int item)
{
	if( isFull_c() )
	{
		printf("Queue Overflow\n");
		return;
	}
	if(front == -1 )
		front=0;

	if(rear==MAX-1)/*rear is at last position of queue*/
		rear=0;
	else
		rear=rear+1;
	cqueue_arr[rear]=item ;
}/*End of insert()*/

int del_c()
{
	int item;
	if( isEmpty_c() )
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	item=cqueue_arr[front];
	if(front==rear) /* queue has only one element */
	{
		front=-1;
		rear=-1;
	}
	else if(front==MAX-1)
		front=0;
	else
		front=front+1;
	return item;
}/*End of del() */

int peek_c()
{
	if( isEmpty_c() )
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	return cqueue_arr[front];
}/*End of peek()*/

void display_c()
{
	int i;
	if(isEmpty_c())
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements :\n");
	i=front;
	if( front<=rear )
	{
		while(i<=rear)
			printf("%d ",cqueue_arr[i++]);
	}
	else
	{
		while(i<=MAX-1)
			printf("%d ",cqueue_arr[i++]);
		i=0;
		while(i<=rear)
			printf("%d ",cqueue_arr[i++]);
	}
	printf("\n");
}/*End of display() */

int choice,item;
	while(1)
	{
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Peek\n");
		printf("4.Display\n");
		printf("5.Quit\n");
		printf("6.Return to Queue\n");

		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1 :
			printf("Input the element for insertion : ");
			scanf("%d",&item);
			insert_c(item);
			break;
		case 2 :
			printf("Element deleted is : %d\n",del_c());
			break;
		case 3:
			printf("Element at the front is  : %d\n",peek_c());
			break;
		case 4:
			display_c();
			break;
		case 5:
			exit(1);
        case 6:
            Queue();
            break;
		default:
			printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while */
}

void Deque()
{
    int deque_arr[MAX];
int front=-1;
int rear=-1;

int isFull()
{
	if ( (front==0 && rear==MAX-1) || (front==rear+1) )
		return 1;
	else
		return 0;
}/*End of isFull()*/

int isEmpty()
{
	if( front == -1)
		return 1;
	else
		return 0;
}/*End of isEmpty()*/

void insert_frontEnd(int item)
{
	if( isFull() )
	{
		printf("Queue Overflow\n");
		return;
	}
	if( front==-1 )/*If queue is initially empty*/
	{
		front=0;
		rear=0;
	}
	else if(front==0)
		front=MAX-1;
	else
		front=front-1;
	deque_arr[front]=item ;
}/*End of insert_frontEnd()*/

void insert_rearEnd(int item)
{
	if( isFull() )
	{
		printf("Queue Overflow\n");
		return;
	}
	if(front==-1)  /*if queue is initially empty*/
	{
		front=0;
		rear=0;
	}
	else if(rear==MAX-1)  /*rear is at last position of queue */
		rear=0;
	else
		rear=rear+1;
	deque_arr[rear]=item ;
}/*End of insert_rearEnd()*/

int delete_frontEnd()
{
	int item;
	if( isEmpty() )
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	item=deque_arr[front];
	if(front==rear) /*Queue has only one element */
	{
		front=-1;
		rear=-1;
	}
	else
		if(front==MAX-1)
			front=0;
		else
			front=front+1;
	return item;
}/*End of delete_frontEnd()*/

int delete_rearEnd()
{
	int item;
	if( isEmpty() )
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	item=deque_arr[rear];

	if(front==rear) /*queue has only one element*/
	{
		front=-1;
		rear=-1;
	}
	else if(rear==0)
		rear=MAX-1;
	else
		rear=rear-1;
	return item;
}/*End of delete_rearEnd() */

void display()
{
	int i;
	if( isEmpty() )
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements :\n");
	i=front;
	if( front<=rear )
	{
		while(i<=rear)
			printf("%d ",deque_arr[i++]);
	}
	else
	{
		while(i<=MAX-1)
			printf("%d ",deque_arr[i++]);
		i=0;
		while(i<=rear)
			printf("%d ",deque_arr[i++]);
	}
	printf("\n");
}/*End of display() */

int choice,item;
	while(1)
	{
		printf("1.Insert at the front end\n");
		printf("2.Insert at the rear end\n");
		printf("3.Delete from front end\n");
		printf("4.Delete from rear end\n");
		printf("5.Display\n");
		printf("6.Quit\n");
		printf("7.Return to Queue\n");

		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1:
			printf("Input the element for adding in queue : ");
			scanf("%d",&item);
			insert_frontEnd(item);
			break;
		case 2:
			printf("Input the element for adding in queue : ");
			scanf("%d",&item);
			insert_rearEnd(item);
			break;
		 case 3:
			printf("Element deleted from front end is : %d\n",delete_frontEnd());
			break;
		 case 4:
			printf("Element deleted from rear end is : %d\n",delete_rearEnd());
			break;
		 case 5:
			display();
			break;
		 case 6:
			exit(1);
         case 7:
            Queue();
            break;
		 default:
			printf("Wrong choice\n");
		}/*End of switch*/
		printf("front = %d, rear =%d\n", front , rear);
		display();
	}/*End of while*/

}

void Priority_Queue()
{
    struct node
{
	int priority;
	int info;
	struct node *link;
}*front=NULL;

int isEmpty()
{
	if( front == NULL )
		return 1;
	else
		return 0;

}/*End of isEmpty()*/

void insert(int item,int item_priority)
{
	struct node *tmp,*p;

	tmp=(struct node *)malloc(sizeof(struct node));
	if(tmp==NULL)
	{
		printf("Memory not available\n");
		return;
	}
	tmp->info=item;
	tmp->priority=item_priority;
	/*Queue is empty or item to be added has priority more than first element*/
	if( isEmpty() || item_priority < front->priority )
	{
		tmp->link=front;
		front=tmp;
	}
	else
	{
		p = front;
		while( p->link!=NULL && p->link->priority<=item_priority )
			p=p->link;
		tmp->link=p->link;
		p->link=tmp;
	}
}/*End of insert()*/

int del()
{
	struct node *tmp;
	int item;
	if( isEmpty() )
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	else
	{
		tmp=front;
		item=tmp->info;
		front=front->link;
		free(tmp);
	}
	return item;
}/*End of del()*/

void display()
{
	struct node *ptr;
	ptr=front;
	if( isEmpty() )
		printf("Queue is empty\n");
	else
	{	printf("Queue is :\n");
		printf("Priority  Item\n");
		while(ptr!=NULL)
		{
			printf("%5d        %5d\n",ptr->priority,ptr->info);
			ptr=ptr->link;
		}
	}
}/*End of display() */

int choice,item,item_priority;
	while(1)
	{
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display\n");
		printf("4.Quit\n");
		printf("5.Return to Queue\n");

		printf("Enter your choice : ");
		scanf("%d", &choice);

		switch(choice)
		{
		 case 1:
			printf("Input the item to be added in the queue : ");
			scanf("%d",&item);
			printf("Enter its priority : ");
			scanf("%d",&item_priority);
			insert(item, item_priority);
			break;
		 case 2:
			printf("Deleted item is %d\n",del());
			break;
		 case 3:
			display();
			break;
		 case 4:
			exit(1);
         case 5:
            Queue();
            break;
		 default :
			printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while*/

}


int ch;
do
{
    printf("\n MENU \n");
    printf("1.Simple Queue\n");
    printf("2.Circular Queue\n");
    printf("3.Deque\n");
    printf("4.Priority Queue\n");
    printf("5.Return to main\n");
    printf("6.Exit\n");

    printf("Enter your choice\n");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
        Simple_Queue();
        break;
    case 2:
        Circular_Queue();
        break;
    case 3:
        Deque();
        break;
    case 4:
        Priority_Queue();
        break;
    case 5:
        main();
        break;
    case 6:
        exit(1);
    default:
        printf("wrong choice\n");
    }
}
while(1);
}


