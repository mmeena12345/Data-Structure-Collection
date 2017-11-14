#include<stdio.h>
#include<stdlib.h>
#define MAX 50
#include "Algo.h"

void Algo()
{
void searching()
{
void linear_search()
{
  int LinearSearch(int arr[], int n, int item)
{
	int i=0;
	while(i<n && item!=arr[i])
			i++;
	if(i < n)
		return i;
	else
		return -1;
}
int i, n, item, arr[MAX], index;
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	printf("Enter the elements : \n");
	for(i=0; i<n; i++)
		scanf("%d", &arr[i] );

	printf("Enter the item to be searched : ");
	scanf("%d", &item);

	index = LinearSearch(arr, n, item);

	if(index == -1)
		printf("%d not found in array\n", item);
	else
		printf("%d found at position %d\n", item, index);


}

void binary_search()
{
 int BinarySearch(int arr[], int size, int item)
{
	int low=0, up=size-1, mid;
	while(low<=up)
	{
		mid = (low+up)/2;
		if(item>arr[mid])
			low = mid+1;	/*Search in right half */
		else if(item<arr[mid])
			up = mid-1;		/*Search in left half */
		else
			return mid;
	}
	return -1;
}
 	int i, size, item, arr[MAX], index;

	printf("Enter the number of elements : ");
	scanf("%d",&size);
	printf("Enter the elements (in sorted order) : \n");
	for(i=0; i<size; i++)
		scanf("%d", &arr[i] );

	printf("Enter the item to be searched : ");
	scanf("%d", &item);

	index = BinarySearch(arr, size, item);

	if(index==-1)
		printf("%d not found in array\n", item);
	else
		printf("%d found at position %d\n", item, index);
}

int ch;
do
{
    printf("\n MENU \n");
    printf("1.linear Searching\n");
    printf("2.Binary Searching\n");
    printf("3.Return to Algo\n");
    printf("4.Exit\n");

    printf("Enter your choice\n");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
        linear_search();
        break;
    case 2:
        binary_search();
        break;
    case 3:
        Algo();
    case 4:
        exit(1);
    default:
        printf("wrong choice\n");
    }
}
while(1);
}

void Sorting()
{
void selection()
{
  int arr[MAX],i,j,n,temp,min;

	printf("Enter the number of elements : ");
	scanf("%d",&n);

	for(i=0; i<n; i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d", &arr[i]);
	}

	/*Selection sort*/
	for(i=0; i<n-1; i++)
	{
		/*Find the index of smallest element*/
		min=i;
		for(j=i+1; j<n ; j++)
		{
			if(arr[min] > arr[j])
				min=j ;
		}
		if(i!=min)
		{
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp ;
		}
	}
	printf("Sorted list is : \n");
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	Sorting();
}

void Bubble()
{
 int arr[MAX],i,j,temp,n,xchanges;

	printf("Enter the number of elements : ");
	scanf("%d",&n);

	for(i=0; i<n; i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&arr[i]);
	}

	/*Bubble sort*/
	for(i=0; i<n-1; i++)
	{
		xchanges=0;
		for(j=0; j<n-1-i; j++)
		{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				xchanges++;
			}
		}
		if(xchanges==0) /*If list is sorted*/
			break;
	}

	printf("Sorted list is :\n");
	for(i=0; i<n; i++)
		printf("%d ",arr[i]);
	printf("\n");
 Sorting();
}

void Insertion()
{
 int arr[MAX],i,j,k,n;

	printf("Enter the number of elements : ");
	scanf("%d",&n);

	for(i=0; i<n; i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d", &arr[i]);
	}

	/*Insertion sort*/
	for(i=1; i<n; i++)
	{
		k=arr[i]; /*k is to be inserted at proper place*/

		for(j=i-1; j>=0 && k<arr[j]; j--)
			arr[j+1]=arr[j];
		arr[j+1]=k;
	}

	printf("Sorted list is :\n");
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	Sorting();
}

void Shell()
{

	int arr[MAX],i,j,k,n,incr;

	printf("Enter the number of elements : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&arr[i]);
	}

	printf("\nEnter maximum increment (odd value) : ");
	scanf("%d",&incr);

	/*Shell sort*/
	while(incr>=1)
	{
		for(i=incr; i<n; i++)
		{
			k=arr[i];
			for(j=i-incr; j>=0 && k<arr[j]; j=j-incr)
				arr[j+incr]=arr[j];
			arr[j+incr]=k;
		}
		incr=incr-2; /*Decrease the increment*/
	}/*End of while*/

	printf("Sorted list is :\n");
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	Sorting();
}

void Merge()
{
 void merge(int arr1[], int arr2[], int arr3[], int n1, int n2)
{
	int i,j,k;
	i=0;  	/*Index for first array*/
	j=0;  	/*Index for second array*/
	k=0;  	/*Index for merged array*/

	while( (i<=n1-1 ) && (j<=n2-1) )
	{
		if(arr1[i] < arr2[j])
			arr3[k++]=arr1[i++];
		else
			arr3[k++]=arr2[j++];
	}
	/*Put remaining elements of arr1 into arr3*/
	while(i<=n1-1)
		arr3[k++]=arr1[i++];

	/*Put remaining elements of arr2 into arr3*/
	while(j<=n2-1)
		arr3[k++]=arr2[j++];

}/*End of merge()*/


	int arr1[MAX],arr2[MAX],arr3[2*MAX],n1,n2,i;

	printf("Enter the number of elements in array 1 : ");
	scanf("%d",&n1);
	printf("Enter all the elements in sorted order :\n");
	for(i=0;i<n1;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&arr1[i]);
	}

	printf("Enter the number of elements in array 2 : ");
	scanf("%d",&n2);
	printf("Enter all the elements in sorted order :\n");
	for(i=0;i<n2;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&arr2[i]);
	}

	merge( arr1, arr2, arr3, n1, n2);

	printf("\n\nMerged list : ");
	for(i=0;i<n1+n2;i++)
		printf("%d ",arr3[i]);
	printf("\n");
	Sorting();
}

void Quick()
{
 int partition(int arr[], int low, int up)
{
	int temp,i,j,pivot;

	i=low+1;
	j=up;
	pivot=arr[low];

	while(i <= j)
	{
		while( arr[i] < pivot && i<up )
			i++;

		while( arr[j] > pivot )
			j--;

		if(i < j)
		{
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			i++;
			j--;
		}
		else
			i++;
	}
	arr[low]=arr[j];
	arr[j]=pivot;

	return j;
}/*End of partition()*/

 void quick(int arr[],int low,int up)
{
	int pivloc;

	if(low>=up)
		return;
	pivloc = partition(arr,low,up);
	quick(arr,low,pivloc-1); /*process left sublist*/
	quick(arr,pivloc+1,up);  /*process right sublist*/
}/*End of quick()*/


  int array[MAX],n,i;
	printf("Enter the number of elements : ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&array[i]);
	}

	quick(array,0,n-1);

	printf("Sorted list is :\n");

	for( i=0; i<n; i++ )
		printf("%d ",array[i]);
	printf("\n");
Sorting();
}

void BTS()
{
 struct node
{
	struct node *lchild;
	int info;
	struct node *rchild;
};
struct node *stack[MAX];
int top=-1;

struct node *insert(struct node *root, int ikey)
{
	struct node *tmp,*par,*ptr;

	ptr = root;
	par = NULL;

	while(ptr!=NULL)
	{
		par = ptr;
		if(ikey < ptr->info)
			ptr = ptr->lchild;
		else
			ptr = ptr->rchild;
	}

	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=ikey;
	tmp->lchild=NULL;
	tmp->rchild=NULL;

	if(par==NULL)
		root=tmp;
	else if(ikey < par->info)
		par->lchild=tmp;
	else
		par->rchild=tmp;

	return root;
}/*End of insert( )*/

void push_stack(struct node *item)
{
	if(top==(MAX-1))
	{
		printf("Stack Overflow\n");
		return;
	}
	stack[++top]=item;
}/*End of push_stack()*/

int stack_empty()
{
	if(top==-1)
		return 1;
	else
		return 0;
} /*End of stack_empty*/

struct node *pop_stack()
{
	struct node *item;
	if(top==-1)
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	item=stack[top--];
	return item;
}/*End of pop_stack()*/

void inorder(struct node *root, int arr[])
{
	struct node *ptr=root;
	int i=0;
	if( ptr==NULL )
	{
		printf("Tree is empty\n");
		return;
	}
	while(1)
	{
      while(ptr->lchild!=NULL )
		{
			push_stack(ptr);
			ptr = ptr->lchild;
		}

		while( ptr->rchild==NULL )
		{
			arr[i++]=ptr->info;
			if(stack_empty())
				return;
			ptr = pop_stack();
		}
		arr[i++]=ptr->info;
		ptr = ptr->rchild;
	}
	printf("\n");
}/*End of inorder( )*/
/*Delete all nodes of the tree*/
struct node *Destroy(struct node *ptr)
{
	if(ptr!=NULL)
	{
		Destroy(ptr->lchild);
		Destroy(ptr->rchild);
		free(ptr);
	}
	return NULL;
}/*End of Destroy()*/
/*Functions for implementation of stack*/



struct node *root=NULL;
	int arr[MAX], n, i;

	printf("Enter the number of elements : ");
	scanf("%d",&n);

	for(i=0; i<n; i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&arr[i]);
	}

	for(i=0; i<n; i++)
		root = insert(root, arr[i]);

	inorder(root, arr);

	printf("\nSorted list is :\n");
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
   	root=Destroy(root);
Sorting();
}

void Heap()
{
void heap_sort(int arr[], int size)
{
	int max;
	buildHeap(arr, size);
	printf("Heap is : ");
	display(arr,size);

	while(size>1)
	{
		max = del_root(arr,&size);
		arr[size+1]=max;
	}
}/*End of heap_sort*/

void buildHeap(int arr[], int size)
{
	int i;
	for(i=size/2; i>=1; i--)
		restoreDown(arr,i,size);
}/*End of buildHeap()*/

int del_root(int arr[], int *size)
{
	int max = arr[1];
	arr[1] = arr[*size];
	(*size)--;
	restoreDown(arr,1,*size);
	return max;
}/*End of del_root()*/

void restoreDown(int arr[], int i, int size )
{
	int left=2*i, right=left+1;

	int num=arr[i];

	while(right<=size)
	{
		if( num>=arr[left] && num>=arr[right] )
		{
			arr[i] = num;
			return;
		}
		else if(arr[left] > arr[right])
		{
			arr[i] = arr[left];
			i = left;
		}
		else
		{
			arr[i] = arr[right];
			i = right;
		}
		left = 2 * i;
		right = left + 1;
	}

	if(left == size && num < arr[left] ) /*when right == size+1*/
	{
		arr[i]=arr[left];
		i = left;
	}
	arr[i]=num;
}/*End of restoreDown()*/

void display(int arr[], int n)
{
	int i;
	for(i=1;i<=n;i++)
		printf("%d  ",arr[i]);
	printf("\n");
	Sorting();
}/*End of display()*/



}

void Radix()
{

struct  node
{
	int info ;
	struct node *link;
}*start=NULL;
int large_dig()
{
	struct node *p=start;
	int large=0,ndig=0;

	/*Find largest element*/
	while(p != NULL)
	{
		if(p ->info > large)
			large = p->info;
		p = p->link ;
	}
	/*Find number of digits in largest element*/
	while(large != 0)
	{
		ndig++;
		large = large/10 ;
	}
	return(ndig);
} /*End of large_dig()*/

int digit(int number, int k)
{
	int digit, i ;
	for(i=1; i<=k; i++)
	{
		digit = number % 10 ;
		number = number /10 ;
	}
	return(digit);
}/*End of digit()*/

void radix_sort()
{
	int i,k,dig,least_sig,most_sig;
	struct node *p, *rear[10], *front[10];

	least_sig=1;
	most_sig=large_dig(start);

	for(k=least_sig; k<=most_sig; k++)
	{
		/*Make all the queues empty at the beginning of each pass*/
		for(i=0; i<=9 ; i++)
		{
			rear[i] = NULL;
			front[i] = NULL ;
		}

		for( p=start; p!=NULL; p=p->link )
		{
			/*Find kth digit in the number*/
			dig = digit(p->info, k);

			/*Add the number to queue of dig*/
			if(front[dig] == NULL)
				front[dig] = p ;
			else
				rear[dig]->link = p;
			rear[dig] = p;
		}

		/*Join all the queues to form the new linked list*/

		i=0;
		while(front[i] == NULL)
			i++;
		start = front[i];
		while(i<9)
		{
			if(rear[i+1]!=NULL)
				rear[i]->link=front[i+1];
			else
				rear[i+1]=rear[i];
			i++;
		}
		rear[9]->link=NULL;
	}
}/*End of radix_sort*/

/*This function finds number of digits in the largest element of the list */

/*This function returns kth digit of a number*/

struct node *tmp,*q;
	int i,n,item;

	printf("Enter the number of elements in the list : ");
	scanf("%d", &n);

	for(i=0;i<n;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&item);

		/*Inserting elements in the linked list*/
		tmp= malloc(sizeof(struct node));
		tmp->info=item;
		tmp->link=NULL;

		if(start==NULL) /*Inserting first element */
			start=tmp;
		else
		{
			q=start;
			while(q->link!=NULL)
				q=q->link;
			q->link=tmp;
		}
	}/*End of for*/

	radix_sort();
	printf("Sorted list is :\n");

	q=start;
	while( q !=NULL)
	{
		printf("%d ", q->info);
		q = q->link;
	}
	printf("\n");
Sorting();
}

int ch;
do
{
    printf("\n Menu \n");
    printf("1.Selection\n");
    printf("2.Bubble Sort\n");
    printf("3.Insertion Sort\n");
    printf("4.Shell Sort\n");
    printf("5.Merge Sort\n");
    printf("6.Quick Sort\n");
    printf("7.Binary Tree Sort\n");
    printf("8.Heap Sort\n");
    printf("9.Radix Sort\n");
    printf("10.Exit\n");
    printf("11.Return to Algorithms\n");

    printf("Enter Your Choice\n");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
        selection();
        break;
    case 2:
        Bubble();
        break;
    case 3:
        Insertion();
        break;
    case 4:
        Shell();
        break;
    case 5:
        Merge();
        break;
    case 6:
        Quick();
        break;
    case 7:
        BTS();
        break;
    case 8:
        Heap();
        break;
    case 9:
        Radix();
        break;
    case 10:
        exit(1);
    case 11:
        Algo();
        break;
    default:
        printf("wrong choice\n");
   }

}
while(1);
}

void warshall_algorithm()
{
    int n;
    int adj[MAX][MAX];
void display(int matrix[MAX][MAX],int n)
{
	int i,j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			printf("%3d",matrix[i][j]);
		printf("\n");
	}
}/*End of display()*/

void create_graph()
{
	int i,max_edges,origin,destin;

	printf("Enter number of vertices : ");
	scanf("%d",&n);

	max_edges = n*(n-1);

	for( i=1; i<=max_edges; i++ )
	{
		printf("Enter edge %d( -1 -1 ) to quit : ",i);
		scanf("%d %d",&origin,&destin);
		if((origin == -1) && (destin == -1))
			break;
		if( origin >= n || destin >= n || origin<0 || destin<0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
			adj[origin][destin] = 1;
	}/*End of for*/
}/*End of create_graph()*/

int i,j,k;
	int P[MAX][MAX];

	create_graph();
	printf("The adjacency matrix is :\n");
	display(adj,n);

	for(i=0; i<n; i++)
	   for(j=0; j<n; j++)
		 P[i][j] = adj[i][j];

	for(k=0; k<n; k++)
	{
		for(i=0; i<n; i++)
		  for(j=0; j<n; j++)
		      P[i][j] = ( P[i][j] || ( P[i][k] && P[k][j] ) );
		printf("P%d is :\n",k);
		display(P,n);
	}
	printf("P%d is the path matrix of the given graph\n",k-1);
}

void prim_algorithm()
{
#define MAX 10
#define TEMP 0
#define PERM 1
#define infinity 9999
#define NIL -1

struct edge
{
	int u;
	int v;
};

int n;
int adj[MAX][MAX];

int predecessor[MAX];
int status[MAX];
int length[MAX];

int min_temp()
{
	int i;
	int min = infinity;
	int k = -1;

	for(i=0; i<n; i++)
	{
		if(status[i] == TEMP && length[i] < min)
		{
			min = length[i];
			k = i;
		}
	}

	return k;
}/*End of min_temp()*/

void maketree(int r, struct edge tree[MAX])
{
	int current,i;
	int count = 0;/*number of vertices in the tree*/

	/*Initialize all vertices*/
	for(i=0; i<n; i++)
	{
		predecessor[i] = NIL;
		length[i] = infinity;
		status[i] = TEMP;
	}

	/*Make length of root vertex 0*/
	length[r] = 0;

	while(1)
	{
		/*Search for temporary vertex with minimum length
		and  make it current vertex*/
		current = min_temp();

		if(current == NIL)
		{
			if(count == n-1) /*No temporary vertex left*/
				return;
			else /*Temporary vertices left with length infinity*/
			{
				printf("Graph is not connected, No spanning tree possible\n");
				return(Algo());
			}
		}

		/*Make the current vertex permanent*/
        status[current] = PERM;

		/*Insert the edge ( predecessor[current], current) into the tree,
		except when the current vertex is root*/
		if(current != r)
		{
           count++;
		   tree[count].u = predecessor[current];
		   tree[count].v = current;
		}

		for(i=0; i<n; i++)
			if(adj[current][i] > 0 && status[i] == TEMP)
				if(adj[current][i] < length[i])
				{
					predecessor[i] = current;
					length[i] = adj[current][i];
				}
	}

}/*End of make_tree( )*/

/*Returns the temporary vertex with minimum value of length
  Returns NIL if no temporary vertex left or
  all temporary vertices left have pathLength infinity*/

void create_graph()
{
	int i,max_edges,origin,destin,wt;

	printf("Enter number of vertices : ");
	scanf("%d",&n);
	max_edges = n*(n-1)/2;

	for(i=1; i<=max_edges; i++)
	{
		printf("Enter edge %d(-1 -1 to quit) : ",i);
		scanf("%d %d",&origin,&destin);
		if((origin == -1) && (destin == -1))
			break;
		printf("Enter weight for this edge : ");
		scanf("%d",&wt);
		if( origin >= n || destin >= n || origin < 0 || destin < 0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
		{
			adj[origin][destin] = wt;
			adj[destin][origin] = wt;
		}
	}
}

int wt_tree = 0;
	int i, root;
	struct edge tree[MAX];

	create_graph();

	printf("Enter root vertex : ");
	scanf("%d",&root);

	maketree(root, tree);

	printf("Edges to be included in spanning tree are : \n");

	for(i=1; i<=n-1; i++)
	{
		printf("%d->",tree[i].u);
		printf("%d\n",tree[i].v);
		wt_tree += adj[tree[i].u][tree[i].v];
	}
	printf("Weight of spanning tree is : %d\n", wt_tree);

}

void kruskal_algorithm()
{
#define MAX 100
#define NIL -1

struct edge
{
	int u;
	int v;
	int weight;
	struct edge *link;
}*front = NULL;

 int n;

 struct edge *del_pque()
{
	struct edge *tmp;
	tmp = front;
	front = front->link;
	return tmp;
}/*End of del_pque()*/

int isEmpty_pque( )
{
	if ( front == NULL )
		return 1;
	else
		return 0;
}/*End of isEmpty_pque()*/

 void make_tree(struct edge tree[])
{
	struct edge *tmp;
	int v1,v2,root_v1,root_v2;
	int father[MAX]; /*Holds father of each vertex */
	int i,count = 0;    /* Denotes number of edges included in the tree */

	for(i=0; i<n; i++)
		father[i] = NIL;

	/*Loop till queue becomes empty or
	till n-1 edges have been inserted in the tree*/
	while( !isEmpty_pque( ) && count < n-1 )
	{
		tmp = del_pque();
		v1 = tmp->u;
		v2 = tmp->v;

		while( v1 !=NIL )
		{
			root_v1 = v1;
			v1 = father[v1];
		}
		while( v2 != NIL  )
		{
			root_v2 = v2;
			v2 = father[v2];
		}

		if( root_v1 != root_v2 )/*Insert the edge (v1, v2)*/
		{
		    count++;
			tree[count].u = tmp->u;
			tree[count].v = tmp->v;
			tree[count].weight = tmp->weight;
			father[root_v2]=root_v1;
		}
	}

	if(count < n-1)
	{
		printf("Graph is not connected, no spanning tree possible\n");
		return(Algo());
	}

}/*End of make_tree()*/

/*Inserting edges in the linked priority queue */
void insert_pque(int i,int j,int wt)
{
	struct edge *tmp,*q;

	tmp = (struct edge *)malloc(sizeof(struct edge));
	tmp->u = i;
	tmp->v = j;
	tmp->weight = wt;

	/*Queue is empty or edge to be added has weight less than first edge*/
	if( front == NULL || tmp->weight < front->weight )
	{
		tmp->link = front;
		front = tmp;
	}
	else
	{
		q = front;
		while( q->link != NULL && q->link->weight <= tmp->weight )
			q = q->link;
		tmp->link = q->link;
		q->link = tmp;
		if(q->link == NULL)	/*Edge to be added at the end*/
			tmp->link = NULL;
	}
}/*End of insert_pque()*/

/*Deleting an edge from the linked priority queue*/


void create_graph()
{
	int i,wt,max_edges,origin,destin;

	printf("Enter number of vertices : ");
	scanf("%d",&n);
	max_edges = n*(n-1)/2;

	for(i=1; i<=max_edges; i++)
	{
		printf("Enter edge %d(-1 -1 to quit): ",i);
		scanf("%d %d",&origin,&destin);
		if( (origin == -1) && (destin == -1) )
			break;
		printf("Enter weight for this edge : ");
		scanf("%d",&wt);
		if( origin >= n || destin >= n || origin<0 || destin<0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
			insert_pque(origin,destin,wt);
	}
}


	int i;
	struct edge tree[MAX]; /* Will contain the edges of spanning tree */
	int wt_tree = 0; /* Weight of the spanning tree */

	create_graph();

	make_tree(tree);

	printf("Edges to be included in minimum spanning tree are :\n");
	for(i=1; i<=n-1; i++)
	{
		printf("%d->",tree[i].u);
		printf("%d\n",tree[i].v);
		wt_tree += tree[i].weight;
	}
	printf("Weight of this minimum spanning tree is : %d\n", wt_tree);
}

int ch;
do
{
    printf("\n Menu \n");
    printf("1.searching\n");
    printf("2.Sorting\n");
    printf("3.Warshall Algorithm for Path Matrix\n");
    printf("4.Prim Algorithm for minimum spanning tree\n");
    printf("5.Kruskal Algorithm for minimum spanning tree\n");
    printf("6.return to main\n");
    printf("7.exit\n");

    printf("Enter your choice\n");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
        searching();
        break;
    case 2:
        Sorting();
        break;
    case 3:
        warshall_algorithm();
        break;
    case 4:
        prim_algorithm();
        break;
    case 5:
        kruskal_algorithm();
        break;
    case 6:
        main();
        break;
    case  7:
        exit(1);
    default:
        printf("wrong choice\n");
}
}
while(1);
}
