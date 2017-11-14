#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"dsa.h"
void linked_list()
{
void single_linked_list()
{
  struct node
{
	int info;
	struct node *link;
};

struct node *addatbeg(struct node *start,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=start;
	start=tmp;
	return start;
}/*End of addatbeg()*/

struct node *addatend(struct node *start,int data)
{
	struct node *p,*tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	p=start;
	while(p->link!=NULL)
		p=p->link;
	p->link=tmp;
	tmp->link=NULL;
	return start;
}/*End of addatend()*/

 struct node *create_list(struct node *start)
{
	int i,n,data;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	start=NULL;
	if(n==0)
		return start;

	printf("Enter the element to be inserted : ");
	scanf("%d",&data);
	start=addatbeg(start,data);

	for(i=2;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		start=addatend(start,data);
	}
	return start;
}/*End of create_list()*/

void display(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=start;
	printf("List is :\n");
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->link;
	}
	printf("\n\n");
}/*End of display() */

void count(struct node *start)
{
	struct node *p;
	int cnt=0;
	p=start;
	while(p!=NULL)
	{
		p=p->link;
		cnt++;
	}
	printf("Number of elements are %d\n",cnt);
}/*End of count() */

void search(struct node *start,int item)
{
	struct node *p=start;
	int pos=1;
	while(p!=NULL)
	{
		if(p->info==item)
		{
			printf("Item %d found at position %d\n",item,pos);
			return;
		}
		p=p->link;
		pos++;
	}
	printf("Item %d not found in list\n",item);
}/*End of search()*/

struct node *addafter(struct node *start,int data,int item)
{
	struct node *tmp,*p;
	p=start;
	while(p!=NULL)
	{
		if(p->info==item)
		{
			tmp=(struct node *)malloc(sizeof(struct node));
			tmp->info=data;
			tmp->link=p->link;
			p->link=tmp;
			return start;
		}
		p=p->link;
	}
	printf("%d not present in the list\n",item);
	return start;
}/*End of addafter()*/

struct node *addbefore(struct node *start,int data,int item)
{
	struct node *tmp,*p;
	if(start==NULL )
	{
		printf("List is empty\n");
		return start;
	}
	/*If data to be inserted before first node*/
	if(item==start->info)
	{
		tmp=(struct node *)malloc(sizeof(struct node));
		tmp->info=data;
		tmp->link=start;
		start=tmp;
		return start;
	}
	p=start;
	while(p->link!=NULL)
	{
		if(p->link->info==item)
		{
			tmp=(struct node *)malloc(sizeof(struct node));
			tmp->info=data;
			tmp->link=p->link;
			p->link=tmp;
			return start;
		}
		p=p->link;
	}
	printf("%d not present in the list\n",item);
	return start;
}/*End of addbefore()*/

struct node *addatpos(struct node *start,int data,int pos)
{
	struct node *tmp,*p;
	int i;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	if(pos==1)
	{
		tmp->link=start;
		start=tmp;
		return start;
	}
	p=start;
	for(i=1; i<pos-1 && p!=NULL; i++)
		p=p->link;
	if(p==NULL)
		printf("There are less than %d elements\n",pos);
	else
	{
		tmp->link=p->link;
		p->link=tmp;
	}
	return start;
}/*End of addatpos()*/

struct node *del(struct node *start,int data)
{
	struct node *tmp,*p;
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}
	/*Deletion of first node*/
	if(start->info==data)
	{
		tmp=start;
		start=start->link;
		free(tmp);
		return start;
	}
	/*Deletion in between or at the end*/
	p=start;
	while(p->link!=NULL)
	{
		if(p->link->info==data)
		{
			tmp=p->link;
			p->link=tmp->link;
			free(tmp);
			return start;
		}
		p=p->link;
	}
	printf("Element %d not found\n",data);
	return start;
}/*End of del()*/

struct node *reverse(struct node *start)
{
	struct node *prev, *ptr, *next;
	prev=NULL;
   	ptr=start;
	while(ptr!=NULL)
	{
		next=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
	}
	start=prev;
	printf("list reversed\n");
	return start;
}/*End of reverse()*/


	struct node *start=NULL;
	int choice,data,item,pos;

	while(1)
	{
	    printf("\n Menu \n");
		printf("1.Create List\n");
		printf("2.Display\n");
		printf("3.Count\n");
		printf("4.Search\n");
		printf("5.Add to empty list / Add at beginning\n");
		printf("6.Add at end\n");
		printf("7.Add after node\n");
		printf("8.Add before node\n");
		printf("9.Add at position\n");
		printf("10.Delete\n");
		printf("11.Reverse\n");
		printf("12.Quit\n");
		printf("13.Return to Linked list\n");

		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			start=create_list(start);
			break;
		 case 2:
			display(start);
			break;
		 case 3:
			count(start);
			break;
		 case 4:
			printf("Enter the element to be searched : ");
			scanf("%d",&data);
			search(start,data);
			break;
		 case 5:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			start=addatbeg(start,data);
			break;
		 case 6:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			start=addatend(start,data);
			break;
		 case 7:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element after which to insert : ");
			scanf("%d",&item);
			start=addafter(start,data,item);
			break;
		 case 8:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element before which to insert : ");
			scanf("%d",&item);
			start=addbefore(start,data,item);
			break;
		 case 9:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the position at which to insert : ");
			scanf("%d",&pos);
			start=addatpos(start,data,pos);
			break;
		 case 10:
			printf("Enter the element to be deleted : ");
			scanf("%d",&data);
			start=del(start, data);
			break;
		 case 11:
			start=reverse(start);
			break;
		 case 12:
			 exit(1);
         case 13:
            linked_list();
		 default:
			 printf("Wrong choice\n");
		}/*End of switch */
	}/*End of while */

}

void doubly_linked_list()
{

struct node
{
	struct node *prev;
	int info;
	struct node *next;
};

struct node *addtoempty(struct node *start,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->prev=NULL;
	tmp->next=NULL;
	start=tmp;
	return start;
}/*End of addtoempty( )*/
struct node *addatend(struct node *start,int data)
{
	struct node *tmp,*p;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	p=start;
	while(p->next!=NULL)
		p=p->next;
	p->next=tmp;
	tmp->next=NULL;
	tmp->prev=p;
	return start;
}/*End of addatend( )*/

struct node *create_list(struct node *start)
{
	int i,n,data;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	start=NULL;
	if(n==0)
		return start;
	printf("Enter the element to be inserted : ");
	scanf("%d",&data);
	start=addtoempty(start,data);

	for(i=2;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		start=addatend(start,data);
	}
	return start;
}/*End of create_list()*/

void display(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=start;
	printf("List is :\n");
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->next;
	}
	printf("\n");
}/*End of display() */


struct node *addatbeg(struct node *start,int data)
{
	struct node *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->prev=NULL;
	tmp->next=start;
	start->prev=tmp;
	start=tmp;
	return start;
}/*End of addatbeg( )*/


struct node *addafter(struct node *start,int data,int item)
{
	struct node *tmp,*p;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	p=start;
	while(p!=NULL)
	{
		if(p->info==item)
		{
			tmp->prev=p;
			tmp->next=p->next;
			if(p->next!=NULL)
				p->next->prev=tmp;
			p->next=tmp;
			return start;
		}
		p=p->next;
	}
	printf("%d not present in the list\n\n",item);
	return start;
}/*End of addafter()*/

struct node *addbefore(struct node *start,int data,int item)
{
	struct node *tmp,*q;
	if(start==NULL )
	{
		printf("List is empty\n");
		return start;
	}
	if(start->info==item)
	{
		tmp = (struct node *)malloc(sizeof(struct node));
		tmp->info=data;
		tmp->prev=NULL;
		tmp->next=start;
		start->prev=tmp;
		start=tmp;
		return start;
	}
	q=start;
	while(q!=NULL)
	{
		if(q->info==item)
		{
			tmp=(struct node *)malloc(sizeof(struct node));
			tmp->info=data;
			tmp->prev=q->prev;
			tmp->next = q;
			q->prev->next=tmp;
			q->prev=tmp;
			return start;
		}
		q=q->next;
	}
	printf("%d not present in the list\n",item);
	return start;
}/*End of addbefore()*/

struct node *del(struct node *start,int data)
{
	struct node *tmp;
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}
	if(start->next==NULL)	/*only one node in the list*/
		if(start->info==data)
		{
			tmp=start;
			start=NULL;
			free(tmp);
			return start;
		}
		else
		{
			printf("Element %d not found\n",data);
			return start;
		}
	/*Deletion of first node*/
	if(start->info==data)
	{
		tmp=start;
		start=start->next;
		start->prev=NULL;
		free(tmp);
		return start;
	}
	/*Deletion in between*/
	tmp=start->next;
	while(tmp->next!=NULL )
	{
		if(tmp->info==data)
		{
			tmp->prev->next=tmp->next;
			tmp->next->prev=tmp->prev;
			free(tmp);
			return start;
		}
		tmp=tmp->next;
	}
	/*Deletion of last node*/
	if(tmp->info==data)
	{
		tmp->prev->next=NULL;
		free(tmp);
		return start;
	}
	printf("Element %d not found\n",data);
	return start;
}/*End of del()*/

struct node *reverse(struct node *start)
{
	struct node *p1,*p2;
	p1=start;
	p2=p1->next;
	p1->next=NULL;
	p1->prev=p2;
	while(p2!=NULL)
	{
		p2->prev=p2->next;
		p2->next=p1;
		p1=p2;
		p2=p2->prev;
	}
	start=p1;
	printf("List reversed\n");
	return start;
}/*End of reverse()*/
 	int choice,data,item;
	struct node *start=NULL;
	while(1)
	{
		printf("1.Create List\n");
		printf("2.Display\n");
		printf("3.Add to empty list\n");
		printf("4.Add at beginning\n");
		printf("5.Add at end\n");
		printf("6.Add after\n");
		printf("7.Add before\n");
		printf("8.Delete\n");
		printf("9.Reverse\n");
		printf("10.Quit\n");
		printf("11.Return to linked list\n");

		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		 case 1:
			start=create_list(start);
			break;
		 case 2:
			display(start);
			break;
		 case 3:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			start=addtoempty(start,data);
			break;
		 case 4:
	        printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			start=addatbeg(start,data);
			break;
		 case 5:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			start=addatend(start,data);
			break;
		 case 6:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element after which to insert : ");
			scanf("%d",&item);
			start=addafter(start,data,item);
			break;
		 case 7:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element before which to insert : ");
			scanf("%d",&item);
			start=addbefore(start,data,item);
			break;
		 case 8:
			printf("Enter the element to be deleted : ");
			scanf("%d",&data);
			start=del(start,data);
	   		break;
		 case 9:
		 	start=reverse(start);
			break;
		 case 10:
			exit(1);
         case 11:
            linked_list();
		 default:
			printf("Wrong choice\n");
	}/*End of switch*/
   }/*End of while*/

}

void circular_linked_list()
{
 struct node
{
	int info;
	struct node *link;
};

struct node *addtoempty(struct node *last,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	last=tmp;
	last->link=last;
	return last;
}/*End of addtoempty( )*/

struct node *addatend(struct node *last,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=last->link;
	last->link=tmp;
	last=tmp;
	return last;
}/*End of addatend( )*/

struct node *create_list(struct node *last)
{
	int i,n,data;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	last=NULL;
	if(n==0)
		return last;
	printf("Enter the element to be inserted : ");
	scanf("%d",&data);
	last=addtoempty(last,data);

	for(i=2;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		last=addatend(last,data);
	}
	return last;
}/*End of create_list()*/


struct node *addatbeg(struct node *last,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=last->link;
	last->link=tmp;
	return last;
}/*End of addatbeg( )*/


struct node *addafter(struct node *last,int data,int item)
{
	struct node *tmp,*p;
	p=last->link;
	do
	{
		if(p->info==item)
		{
			tmp=(struct node *)malloc(sizeof(struct node));
			tmp->info=data;
			tmp->link=p->link;
			p->link=tmp;
			if(p==last)
				last=tmp;
			return last;
		}
		p=p->link;
	}while(p!=last->link);
	printf("%d not present in the list\n",item);
	return last;
}/*End of addafter()*/

struct node *del(struct node *last,int data)
{
	struct node *tmp,*p;
	if(last==NULL)
	{
		printf("List is empty\n");
		return last;
	}
	/*Deletion of only node*/
	if(last->link==last && last->info==data)
	{
		tmp=last;
		last=NULL;
		free(tmp);
		return last;
	}
	/*Deletion of first node*/
	if(last->link->info==data)
	{
		tmp=last->link;
		last->link=tmp->link;
		free(tmp);
		return last;
	}
	/*Deletion in between*/
	p=last->link;
	while(p->link!=last)
	{
		if(p->link->info==data)
		{
			tmp=p->link;
			p->link=tmp->link;
			free(tmp);
			return last;
		}
		p=p->link;
	}
	/*Deletion of last node*/
	if(last->info==data)
	{
		tmp=last;
		p->link=last->link;
		last=p;
		free(tmp);
		return last;
	}
	printf("Element %d not found\n",data);
	return last;
}/*End of del( )*/

void display(struct node *last)
{
	struct node *p;
	if(last==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=last->link;
	do
	{
		printf("%d ",p->info);
		p=p->link;
	}while(p!=last->link);
	printf("\n");
}/*End of display( )*/

 int choice,data,item;
	struct node	*last=NULL;

	while(1)
	{
		printf("1.Create List\n");
		printf("2.Display\n");
		printf("3.Add to empty list\n");
		printf("4.Add at beginning\n");
		printf("5.Add at end\n");
		printf("6.Add after \n");
		printf("7.Delete\n");
		printf("8.Quit\n");
		printf("9.Return to linked list\n");

		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			last=create_list(last);
			break;
		 case 2:
			display(last);
			break;
		 case 3:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			last=addtoempty(last,data);
			break;
		 case 4:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			last=addatbeg(last,data);
			break;
		 case 5:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			last=addatend(last,data);
			break;
		 case 6:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element after which to insert : ");
			scanf("%d",&item);
			last=addafter(last,data,item);
			break;
		 case 7:
			printf("Enter the element to be deleted : ");
			scanf("%d",&data);
			last=del(last,data);
			break;
		 case 8:
		 	exit(1);
         case 9:
            linked_list();
		 default:
			printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while*/
}

int ch;
do
{
    printf("\n Menu:\n");
    printf(" 1:Singly linked list \n");
    printf(" 2:Doubly Linked list \n");
    printf(" 3:circular linked list \n");
    printf(" 4:Return to Main\n");
    printf(" 5:exit \n");

    printf("Enter your choice \n");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
        single_linked_list();
        break;
    case 2:
        doubly_linked_list();
        break;
    case 3:
      circular_linked_list();
      break;
    case 4:
        main();
        break;
    case 5:
        exit(1);
    default:
        printf("wrong choice\n");
    }
}
while(1);
}
