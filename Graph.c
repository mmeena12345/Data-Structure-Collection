#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void Graph()
{
void Adjacency_Matrix()
{
int adj[MAX][MAX]; /*Adjacency matrix*/
int n;    /*Number of vertices in the graph*/

int max_edges,i,j,origin,destin;
	int graph_type;

	printf("Enter 1 for undirected graph or 2 for directed graph : ");
	scanf("%d",&graph_type);

	printf("Enter number of vertices : ");
	scanf("%d",&n);

	if(graph_type==1)
		max_edges = n*(n-1)/2;
	else
		max_edges = n*(n-1);

	for(i=1; i<=max_edges; i++)
	{
		printf("Enter edge %d( -1 -1 to quit ) : ",i);
		scanf("%d %d",&origin,&destin);
		if( (origin == -1) && (destin == -1) )
			break;
		if( origin>=n || destin>=n || origin<0 || destin<0 )
		{
			printf("Invalid vertex!\n");
			i--;
		}
		else
		{
			adj[origin][destin] = 1;
			if( graph_type == 1) /*if undirected graph*/
				adj[destin][origin] = 1;
		}
	}/*End of for*/

	printf("The adjacency matrix is :\n");
	for(i=0; i<=n-1; i++)
	{
		for(j=0; j<=n-1; j++)
			printf("%4d",adj[i][j]);
		printf("\n");
	}
	Graph();
}

void Directed_Graph_Adjacency_Matrix()
{
int adj[MAX][MAX];
int n;

void create_graph()
{
	int i,max_edges,origin,destin;

	printf("Enter number of vertices : ");
	scanf("%d",&n);

	max_edges = n*(n-1); /*directed graph*/

	for(i=1; i<=max_edges; i++)
	{
		printf("Enter edge %d(-1 -1) to quit : ",i);
		scanf("%d %d",&origin,&destin);
		if((origin==-1) && (destin==-1))
			break;
		if(origin>=n || destin>=n || origin<0 || destin<0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
			adj[origin][destin] = 1;
	}/*End of for*/
}/*End of create_graph()*/

void insert_edge(int origin,int destin)
{
	if(origin<0 || origin>=n)
	{
		printf("Origin vertex does not exist\n");
		return;
	}
	if(destin<0 || destin>=n)
	{
		printf("Destination vertex does not exist\n");
		return;
	}
	adj[origin][destin] = 1;
}/*End of insert_edge()*/

void del_edge(int origin, int destin)
{
     if(origin<0 || origin>=n || destin<0 || destin>=n || adj[origin][destin]==0)
     {
		printf("This edge does not exist\n");
		return;
     }
     adj[origin][destin] = 0;
}/*End of del_edge()*/

void display()
{
	int i,j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			printf("%4d",adj[i][j]);
		printf("\n");
	}
}/*End of display()*/

int choice,origin,destin;

	create_graph();

	while(1)
	{
	    printf("\n Menu \n");
		printf("1.Insert an edge\n");
		printf("2.Delete an edge\n");
		printf("3.Display\n");
		printf("4.Exit\n");
		printf("5.Return to graph\n");

		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			printf("Enter an edge to be inserted : ");
			scanf("%d %d",&origin,&destin);
			insert_edge(origin,destin);
			break;
		 case 2:
			printf("Enter an edge to be deleted : ");
			scanf("%d %d",&origin,&destin);
			del_edge(origin,destin);
			break;
		 case 3:
			display();
			break;
		 case 4:
			exit(1);
         case 5:
            Graph();
            break;
		 default:
			printf("Wrong choice\n");
			break;
		 }/*End of switch*/
	}/*End of while*/

}

void Directed_graph_Adjacency_List()
{
struct Vertex
{
	int info;
	struct Vertex *nextVertex;  /*next vertex in the linked list of vertices*/
	struct Edge *firstEdge;  /*first Edge of the adjacency list of this vertex*/
}*start = NULL;

struct Edge
{
	struct Vertex *destVertex;  /*Destination vertex of the Edge*/
	struct Edge *nextEdge; /*next Edge of the adjacency list*/
};

void insertVertex(int u)
{
	struct Vertex *tmp,*ptr;
	tmp = malloc(sizeof(struct Vertex));
	tmp->info = u;
	tmp->nextVertex = NULL;
	tmp->firstEdge = NULL;

	if(start == NULL)
	{
		start = tmp;
		return;
	}
	ptr = start;
	while(ptr->nextVertex!=NULL)
		ptr = ptr->nextVertex;
	ptr->nextVertex = tmp;
}/*End of insertVertex()*/

void deleteVertex(int u)
{
	struct Vertex *tmp,*q;
	struct Edge *p,*temporary;
	if(start == NULL)
	{
		printf("No vertices to be deleted\n");
		return;
	}
	if(start->info == u)/* Vertex to be deleted is first vertex of list*/
	{
		tmp = start;
		start = start->nextVertex;
	}
	else /* Vertex to be deleted is in between or at last */
	{
        q = start;
		while(q->nextVertex != NULL)
		{
			if(q->nextVertex->info == u)
				break;
			q = q->nextVertex;
		}
		if(q->nextVertex==NULL)
		{
			printf("Vertex not found\n");
			return;
		}
		else
		{
			tmp = q->nextVertex;
			q->nextVertex = tmp->nextVertex;
		}
	}
	/*Before freeing the node tmp, free all edges going from this vertex */
	p = tmp->firstEdge;
	while(p!=NULL)
	{
		temporary = p;
		p = p->nextEdge;
		free(temporary);
	}
	free(tmp);
}/*End of deleteVertex()*/

void deleteIncomingEdges(int u)
{
	struct Vertex *ptr;
	struct Edge *q,*tmp;

	ptr = start;
	while(ptr!=NULL)
	{
		if(ptr->firstEdge == NULL)   /*Edge list for vertex ptr is empty*/
		{
			ptr = ptr->nextVertex;
			continue; /* continue searching in other Edge lists */
		}

		if(ptr->firstEdge->destVertex->info == u)
		{
			tmp = ptr->firstEdge;
			ptr->firstEdge = ptr->firstEdge->nextEdge;
			free(tmp);
			continue; /* continue searching in other Edge lists */
		}
		q = ptr->firstEdge;
		while(q->nextEdge!= NULL)
		{
			if(q->nextEdge->destVertex->info == u)
			{
				tmp = q->nextEdge;
				q->nextEdge = tmp->nextEdge;
				free(tmp);
				continue;
			}
			q = q->nextEdge;
		}
		ptr = ptr->nextVertex;
	}/*End of while*/

}/*End of deleteIncomingEdges()*/


struct Vertex *findVertex(int u)
{
	struct Vertex *ptr,*loc;
	ptr = start;
	while(ptr!=NULL)
	{
		if(ptr->info == u )
		{
			loc = ptr;
			return loc;
		}
		else
			ptr = ptr->nextVertex;
	}
	loc = NULL;
	return loc;
}/*End of findVertex()*/

void insertEdge(int u,int v)
{
	struct Vertex *locu,*locv;
	struct Edge *ptr,*tmp;

	locu = findVertex(u);
	locv = findVertex(v);

	if(locu == NULL )
	{
		printf("Start vertex not present, first insert vertex %d\n",u);
		return;
	}
	if(locv == NULL )
	{
		printf("End vertex not present, first insert vertex %d\n",v);
		return;
	}
	tmp = malloc(sizeof(struct Edge));
	tmp->destVertex = locv;
	tmp->nextEdge = NULL;

	if(locu->firstEdge == NULL)
	{
		 locu->firstEdge = tmp;
         return;
	}
	ptr = locu->firstEdge;
	while(ptr->nextEdge!=NULL)
		ptr = ptr->nextEdge;
	ptr->nextEdge = tmp;

}/*End of insertEdge()*/

void deleteEdge(int u,int v)
{
	struct Vertex *locu;
	struct Edge *tmp,*q;

	locu = findVertex(u);

	if(locu == NULL )
	{
		printf("Start vertex not present\n");
		return;
	}
	if(locu->firstEdge == NULL)
	{
		printf("Edge not present\n");
		return;
	}

	if(locu->firstEdge->destVertex->info == v)
	{
		tmp = locu->firstEdge;
		locu->firstEdge = locu->firstEdge->nextEdge;
		free(tmp);
		return;
	}
	q = locu->firstEdge;
	while(q->nextEdge != NULL)
	{
		if(q->nextEdge->destVertex->info == v)
		{
			tmp = q->nextEdge;
			q->nextEdge = tmp->nextEdge;
			free(tmp);
			return;
		}
		q = q->nextEdge;
	}/*End of while*/

	printf("This Edge not present in the graph\n");
}/*End of deleteEdge()*/

void display()
{
	struct Vertex *ptr;
	struct Edge *q;

	ptr = start;
	while(ptr!=NULL)
	{
		printf("%d ->",ptr->info);
		q = ptr->firstEdge;
		while(q!=NULL)
		{
			printf(" %d",q->destVertex->info);
			q = q->nextEdge;
		}
		printf("\n");
		ptr = ptr->nextVertex;
	 }
}/*End of display()*/


	int choice,u,origin,destin;

	while(1)
	{
	    printf("\n Menu \n");
		printf("1.Insert a Vertex\n");
		printf("2.Insert an Edge\n");
		printf("3.Delete a Vertex\n");
		printf("4.Delete an Edge\n");
		printf("5.Display\n");
		printf("6.Exit\n");
		printf("7.Return to Graph\n");

		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			printf("Enter a vertex to be inserted : ");
			scanf("%d",&u);
			insertVertex(u);
			break;
		 case 2:
			printf("Enter an Edge to be inserted : ");
			scanf("%d %d",&origin,&destin);
			insertEdge(origin,destin);
			break;
		 case 3:
			printf("Enter a vertex to be deleted : ");
			scanf("%d",&u);
			/*This function deletes all edges coming to this vertex*/
			deleteIncomingEdges(u);
			/*This function deletes the vertex from the vertex list*/
			deleteVertex(u);
			break;
		 case 4:
			printf("Enter an edge to be deleted : ");
			scanf("%d %d",&origin,&destin);
			deleteEdge(origin,destin);
			break;
		 case 5:
			display();
			break;
		 case 6:
			exit(1);
         case 7:
            Graph();
            break;
		 default:
			printf("Wrong choice\n");
		 }/*End of switch*/
	}/*End of while*/

}

void path_matrix()
{

int adj[MAX][MAX];
int n;

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
		if( (origin == -1) && (destin == -1) )
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

void multiply(int mat1[MAX][MAX],int mat2[MAX][MAX],int mat3[MAX][MAX])
{
	int i,j,k;

	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
		{
			mat3[i][j] = 0;
			for(k=0; k<n; k++)
				mat3[i][j] = mat3[i][j]+ mat1[i][k] * mat2[k][j];
	   }
}/*End of multiply()*/


/*This function computes the pth power of matrix adj and stores result in adjp */
void pow_matrix(int p,int adjp[MAX][MAX])
{

	int i,j,k,tmp[MAX][MAX];

	/*Initially adjp is equal to adj*/
	for(i=0; i<n; i++)
	  for(j=0; j<n; j++)
	   adjp[i][j] = adj[i][j];

	for(k=1; k<p; k++)
	{
		/*Multiply adjp with adj and store result in tmp */
		multiply(adjp,adj,tmp);
		for(i=0; i<n; i++)
		  for(j=0; j<n; j++)
		     adjp[i][j] = tmp[i][j]; /* New adjp is equal to tmp */
	}
}/*End of pow_matrix()*/

/*This function multiplies mat1 and mat2 and stores the result in mat3 */

void display(int matrix[MAX][MAX])
{
	int i,j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			printf("%4d",matrix[i][j]);
		printf("\n");
	}
	printf("\n");
}/*End of display()*/

int adjp[MAX][MAX];
	int x[MAX][MAX],path[MAX][MAX],i,j,p;

	create_graph();

	printf("The adjacency matrix is :\n");
	display(adj);

	/*Initialize all elements of matrix x to zero*/
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
		   x[i][j] = 0;

	/*All the powers of adj will be added to matrix x */
	for(p=1; p<=n; p++)
	{
		pow_matrix(p,adjp);
		printf("Adjacency matrix raised to power %d is - \n", p);
		display(adjp);
		for(i=0; i<n; i++)
		  for(j=0; j<n; j++)
			 x[i][j] = x[i][j]+adjp[i][j];
	}

	printf("The matrix x is :\n");
	display(x);

	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			if (x[i][j] == 0 )
	   			path[i][j] = 0;
			else
				path[i][j] = 1;

	printf("The path matrix is :\n");
	display(path);

}

void BFS_0()
{
void BFS_1()
{
#define MAX 100
#define initial 1
#define waiting 2
#define visited 3

int n;    /*Number of vertices in the graph*/
int adj[MAX][MAX]; /*Adjacency Matrix*/
int state[MAX]; /*can be initial, waiting or visited*/
int queue[MAX], front = -1,rear = -1;

int isEmpty_queue()
{
	if(front == -1 || front > rear)
		return 1;
	else
		return 0;
}/*End of isEmpty_queue()*/

void insert_queue(int vertex)
{
	if(rear == MAX-1)
		printf("Queue Overflow\n");
	else
	{
		if(front == -1)  /*If queue is initially empty */
			front = 0;
		rear = rear+1;
		queue[rear] = vertex ;
	}
}/*End of insert_queue()*/

int delete_queue()
{
	int del_item;
	if(front == -1 || front > rear)
	{
		printf("Queue Underflow\n");
		exit(1);
	}

	del_item = queue[front];
	front = front+1;
	return del_item;
}/*End of delete_queue() */


void BFS(int v)
{
	int i;

	insert_queue(v);
	state[v] = waiting;

	while(!isEmpty_queue())
	{
		v = delete_queue( );
		printf("%d ",v);
		state[v] = visited;

		for(i=0; i<n; i++)
		{
			/*Check for adjacent unvisited vertices */
			if(adj[v][i] == 1 && state[i] == initial)
			{
				insert_queue(i);
				state[i] = waiting;
			}
		}
	}
	printf("\n");
}/*End of BFS()*/

void BF_Traversal()
{
	int v;

	for(v=0; v<n; v++)
		state[v] = initial;

	printf("Enter starting vertex for Breadth First Search : ");
	scanf("%d", &v);
	BFS(v);
}/*End of BF_Traversal()*/

void create_graph()
{
	int i,max_edges,origin,destin;

	printf("Enter number of vertices : ");
	scanf("%d",&n);
	max_edges = n*(n-1);

	for(i=1; i<=max_edges; i++)
	{
		printf("Enter edge %d( -1 -1 to quit ) : ",i);
		scanf("%d %d",&origin,&destin);

		if((origin == -1) && (destin == -1))
			break;

		if(origin>=n || destin>=n || origin<0 || destin<0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
		{
			adj[origin][destin] = 1;
		}
	}/*End of for*/
}/*End of create_graph()*/

int ch;
do
{
    printf("\n Menu \n");
    printf("1.Create graph\n");
    printf("2.BFS Traversal\n");
    printf("3.Return to BFS\n");
    printf("4.Exit\n");

    printf("Enter Your choice\n");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
        create_graph();
        break;
    case 2:
        BF_Traversal();
        break;
    case 3:
        BFS_0();
        break;
    case 4:
        exit(1);
    }
}
while(1);
 }

void BFS_2()
{
#define initial 1
#define waiting 2
#define visited 3
int n;    /*Number of vertices in the graph*/
int adj[MAX][MAX]; /*Adjacency Matrix*/
int state[MAX]; /*can be initial, waiting or visited*/
int queue[MAX], front=-1,rear=-1;


void insert_queue(int vertex)
{
	if (rear == MAX-1)
		printf("Queue Overflow\n");
	else
	{
		if (front == -1)  /*If queue is initially empty */
			front = 0;
		rear = rear+1;
		queue[rear] = vertex ;
	}
}/*End of insert_queue()*/


int delete_queue()
{
	int del_item;
	if (front == -1 || front > rear)
	{
		printf("Queue Underflow\n");
		exit(1);
	}

	del_item = queue[front];
	front = front+1;
	return del_item;

}/*End of delete_queue() */


int isEmpty_queue()
{
	if(front == -1 || front > rear )
		return 1;
	else
		return 0;
}/*End of isEmpty_queue()*/


void BFS(int v)
{
	int i;

	insert_queue(v);
	state[v]=waiting;

	while( !isEmpty_queue() )
	{
		v = delete_queue( );
		printf("%d  ",v);
		state[v] = visited;
		for(i=0; i<n; i++)
		{
			/* Check for adjacent unvisited vertices */
			if( adj[v][i] == 1 && state[i] == initial)
			{
				insert_queue(i);
				state[i] = waiting;
			}
		}
	}
	printf("\n");
}/*End of BFS()*/

void BF_Traversal()
{
	int v;

	for(v=0; v<n; v++)
		state[v]=initial;

	printf("Enter starting vertex for Breadth First Search : ");
	scanf("%d", &v);
	BFS(v);
	for(v=0; v<n; v++)
		if(state[v] == initial)
			BFS(v);
}/*End of BF_Traversal()*/

void create_graph()
{
	int i,max_edges,origin,destin;

	printf("Enter number of vertices : ");
	scanf("%d",&n);
	max_edges = n*(n-1);

	for(i=1;i<=max_edges;i++)
	{
		printf("Enter edge %d( -1 -1 to quit ) : ",i);
		scanf("%d %d",&origin,&destin);

		if((origin == -1) && (destin == -1))
			break;

		if( origin >= n || destin >= n || origin<0 || destin<0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
		{
			adj[origin][destin]=1;
		}
	}/*End of for*/
}/*End of create_graph()*/
int ch;
do
{
    printf("\n Menu \n");
    printf("1.Create graph\n");
    printf("2.BFS Traversals\n");
    printf("3.Return to BFS\n");
    printf("4.Exit\n");

    printf("Enter Your Choice\n");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
        create_graph();
        break;
    case 2:
        BF_Traversal();
        break;
    case 3:
        BFS_0();
        break;
    case 4:
        exit(1);

    }
}
while(1);
}

void BFS_3()
{
#define MAX 100
#define infinity 9999
#define NIL -1

#define initial 1
#define waiting 2
#define visited 3
int queue[MAX], front = -1,rear = -1;

int n;    /*Number of vertices in the graph*/
int adj[MAX][MAX]; /*Adjacency Matrix*/
int state[MAX]; /*can be initial, waiting or visited*/
int distance[MAX];
int predecessor[MAX];

void insert_queue(int vertex)
{
	if(rear == MAX-1)
		printf("Queue Overflow\n");
	else
	{
		if(front == -1)  /*If queue is initially empty */
			front=0;
		rear=rear+1;
		queue[rear] = vertex ;
	}
}/*End of insert_queue()*/

int delete_queue()
{
	int del_item;
	if (front == -1 || front > rear)
	{
		printf("Queue Underflow\n");
		exit(1);
	}

	del_item = queue[front];
	front = front+1;
	return del_item;

}/*End of delete_queue() */

int isEmpty_queue()
{
	if(front == -1 || front > rear)
		return 1;
	else
		return 0;
}/*End of isEmpty_queue()*/

void BFS(int v)
{
	int i;

	insert_queue(v);

	state[v]=waiting;
	distance[v]=0;
	predecessor[v]=NIL;

	while( !isEmpty_queue() )
	{
		v = delete_queue( );
		printf("Vertex %d, distance %d, predecessor %d\n",v, distance[v], predecessor[v]);
		state[v] = visited;
		for(i=0; i<n; i++)
		{
			/* Check for adjacent unvisited vertices */
			if( adj[v][i] == 1 && state[i] == initial)
			{
				insert_queue(i);
				state[i]=waiting;
				predecessor[i] = v;
				distance[i] = distance[v]+1;
			}
		}
	}
}/*End of BFS()*/

void BF_Traversal()
{
	int v;

	for(v=0; v<n; v++)
	{
		state[v] = initial;
		predecessor[v] = NIL;
		distance[v] = infinity;
	}
	printf("Enter starting vertex for Breadth First Search : ");
	scanf("%d", &v);
	BFS(v);
	printf("\n");
}/*End of BF_Traversal()*/

void create_graph()
{
	int i,max_edges,origin,destin;

	printf("Enter number of vertices : ");
	scanf("%d",&n);
	max_edges = n*(n-1);

	for(i=1; i<=max_edges; i++)
	{
		printf("Enter edge %d( -1 -1 to quit ) : ",i);
		scanf("%d %d",&origin,&destin);

		if((origin == -1) && (destin == -1))
			break;

		if( origin >= n || destin >= n || origin<0 || destin<0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
		{
			adj[origin][destin] = 1;
		}
	}
}/*End of create_graph()*/

int u, v, i,count, path[MAX];

	create_graph();
	BF_Traversal();

	while(1)
	{
		printf("Enter destination vertex(-1 to quit) : ");
		scanf("%d",&v);
		if(v<-1 || v>n-1)
		{
			printf("Destination vertex does not exist\n");
			continue;
		}

		if(v == -1)
			break;
		count = 0;

		if(distance[v] == infinity)
		{
			printf("No path from start vertex to destination vertex\n");
			continue;
		}
		else
			printf("Shortest distance is : %d\n", distance[v]);

		/*Store the full path in array path*/
		while(v!=NIL)
		{
			count++;
			path[count]=v;
			u = predecessor[v];
			v = u;
		}

		printf("Shortest Path is : ");
		for(i=count; i>1; i--)
			printf("%d->",path[i]);
		printf("%d",path[i]);
		printf("\n");
	}
}

void BFS_4()
{
#define MAX 100

#define initial 1
#define waiting 2
#define visited 3

int n;    /*Number of vertices in the graph*/
int adj[MAX][MAX]; /*Adjacency Matrix*/
int state[MAX]; /*can be initial, waiting or visited*/
int queue[MAX], front = -1,rear = -1;

void insert_queue(int vertex)
{
	if(rear==MAX-1)
		printf("Queue Overflow\n");
	else
	{
		if(front==-1)  /*If queue is initially empty */
			front = 0;
		rear = rear+1;
		queue[rear] = vertex ;
	}
}/*End of insert_queue()*/

int isEmpty_queue()
{
	if(front == -1 || front > rear )
		return 1;
	else
		return 0;
}/*End of isEmpty_queue()*/

int delete_queue()
{
	int del_item;
	if (front == -1 || front > rear)
	{
		printf("Queue Underflow\n");
		exit(1);
	}

	del_item = queue[front];
	front = front+1;
	return del_item;
}/*End of delete_queue() */

void BFS(int v)
{
	int i;

	insert_queue(v);
	state[v] = waiting;

	while(!isEmpty_queue())
	{
		v = delete_queue();
		printf("Vertex %d visited\n",v);
		state[v] = visited;
		for(i=0; i<n; i++)
		{
			/* Check for adjacent unvisited vertices */
			if(adj[v][i] == 1 && state[i] == initial)
			{
				insert_queue(i);
				state[i] = waiting;
				printf("-----Tree edge - (%d,%d)\n", v, i);
			}
		}
	}
	printf("\n");
}/*End of BFS()*/

void BF_Traversal()
{
	int v;

	for(v=0;v<n;v++)
		state[v] = initial;

	printf("Enter starting vertex for Breadth First Search : ");
	scanf("%d", &v);
	BFS(v);
	for(v=0; v<n; v++)
		if( state[v] == initial)
			BFS(v);
}/*End of BF_Traversal()*/

void create_graph()
{
	int i,max_edges,origin,destin;

	printf("Enter number of vertices : ");
	scanf("%d",&n);
	max_edges = n*(n-1);

	for(i=1;i<=max_edges;i++)
	{
		printf("Enter edge %d( -1 -1 to quit ) : ",i);
		scanf("%d %d",&origin,&destin);

		if((origin == -1) && (destin == -1))
			break;
		if( origin >= n || destin >= n || origin<0 || destin<0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
		{
			adj[origin][destin] = 1;
		}
	}/*End of for*/
}/*End of create_graph()*/

int ch;
do
{
    printf("\n MENU \n");
    printf("1.Creation of Graph\n");
    printf("2.BFS Traversal\n");
    printf("3.Return to BFS\n");
    printf("4.Exit\n");

    printf("Enter Your choice\n");
    scanf("%d",&ch);

    switch(ch)
{
case 1:
    create_graph();
    break;
case 2:
    BF_Traversal();
    break;
case 3:
    BFS_0();
    break;
case 4:
    exit(1);
}
}
while(1);
}

void BFS_5()
{
#define initial 1
#define waiting 2
#define visited 3

int n;    /*Number of vertices in the graph*/
int adj[MAX][MAX]; /*Adjacency Matrix*/
int state[MAX]; /*can be initial, waiting or visited*/

int queue[MAX], front = -1,rear = -1;


void insert_queue(int vertex)
{
	if(rear == MAX-1)
		printf("Queue Overflow\n");
	else
	{
		if(front == -1)  /*If queue is initially empty */
			front = 0;
		rear = rear+1;
		queue[rear] = vertex ;
	}
}/*End of insert_queue()*/

int delete_queue()
{
	int del_item;
	if (front == -1 || front > rear)
	{
		printf("Queue Underflow\n");
		exit(1);
	}

	del_item = queue[front];
	front = front+1;
	return del_item;

}/*End of delete_queue() */

int isEmpty_queue()
{
	if(front == -1 || front > rear )
		return 1;
	else
		return 0;
}/*End of isEmpty_queue()*/

void BF_Search(int v)
{
	int i;

	insert_queue(v);
	state[v] = waiting;

	while( !isEmpty_queue() )
	{
		v = delete_queue( );
		printf("%d  ",v);
		state[v] = visited;
		for(i=0; i<n; i++)
		{
			/* Check for adjacent unvisited vertices */
			if(adj[v][i] == 1 && state[i] == initial)
			{
				insert_queue(i);
				state[i] = waiting;
			}
		}
	}
	printf("\n");
}/*End of BF_Search()*/

void BF_Traversal()
{
	int v;

	for(v=0; v<n; v++)
		state[v] = initial;

	printf("Enter starting vertex for Breadth First Search : ");
	scanf("%d", &v);
	BF_Search(v);
	for(v=0; v<n; v++)
		if( state[v] == initial)
			BF_Search(v);
}/*End of BF_Traversal()*/

void create_graph()
{
	int i,max_edges,origin,destin;

	printf("Enter number of vertices : ");
	scanf("%d",&n);
	max_edges = n*(n-1)/2;/*Undirected graph*/

	for(i=1; i<=max_edges; i++)
	{
		printf("Enter edge %d( -1 -1 to quit ) : ",i);
		scanf("%d %d",&origin,&destin);

		if((origin == -1) && (destin == -1))
			break;

		if( origin >= n || destin >= n || origin<0 || destin<0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
		{
			adj[origin][destin] = 1;
			adj[destin][origin] = 1;
		}
	}
}/*End of create_graph()*/
int ch;
do
{
    printf("\n Menu \n");
    printf("1.Create Graph\n");
    printf("2.BFS Traversal\n");
    printf("3.Return to BFS\n");
    printf("4.Exit\n");

    printf("Enter Your Choice\n");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
        create_graph();
        break;
    case 2:
        BF_Traversal();
        break;
    case 3:
        BFS_0();
        break;
    case 4:
        exit(1);

    }
}
while(1);
}

void BFS_6()
{
#define initial 1
#define waiting 2
#define visited 3
int n;    /*Number of vertices in the graph*/
int adj[MAX][MAX]; /*Adjacency Matrix*/
int state[MAX]; /*can be initial, waiting or visited*/
int queue[MAX], front = -1,rear = -1;

void insert_queue(int vertex)
{
	if(rear == MAX-1)
		printf("Queue Overflow\n");
	else
	{
		if(front == -1)  /*If queue is initially empty */
			front = 0;
		rear = rear+1;
		queue[rear] = vertex ;
	}
}/*End of insert_queue()*/

int delete_queue()
{
	int del_item;
	if (front == -1 || front > rear)
	{
		printf("Queue Underflow\n");
		exit(1);
	}

	del_item = queue[front];
	front = front+1;
	return del_item;

}/*End of delete_queue() */


int isEmpty_queue()
{
	if(front == -1 || front > rear )
		return 1;
	else
		return 0;
}/*End of isEmpty_queue()*/

void BFS(int v)
{
	int i;

	insert_queue(v);
	state[v] = waiting;

	while( !isEmpty_queue() )
	{
		v = delete_queue( );
		state[v] = visited;
		printf("%d ",v);

		for(i=0; i<=n-1; i++)
		{
			/* Check for adjacent unvisited vertices */
			if( adj[v][i] == 1 && state[i] == initial)
			{
				insert_queue(i);
				state[i] = waiting;
			}
		}
	}
	printf("\n");
}/*End of BFS()*/

void  BF_Traversal()
{
int v;
	int connected = 1;

	for(v=0; v<n; v++)
		state[v] = initial;

	BFS(0); /*start BFS from vertex 0*/

	for(v=0; v<n; v++)
	{
		if(state[v] == initial)
		{
			connected = 0;
			break;
		}
	}

	if(connected)
        printf("Graph is connected\n");
	else
        printf("Graph is not connected\n");
}/*End of BF_Traversal()*/

void create_graph()
{
	int i,max_edges,origin,destin;

	printf("Enter number of vertices : ");
	scanf("%d",&n);
	max_edges = n*(n-1)/2;

	for(i=1; i<=max_edges; i++)
	{
		printf("Enter edge %d( -1 -1 to quit ) : ",i);
		scanf("%d %d",&origin,&destin);

		if((origin == -1) && (destin == -1))
			break;

		if( origin >= n || destin >= n || origin<0 || destin<0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
		{
			adj[origin][destin] = 1;
			adj[destin][origin] = 1;
		}
	}/*End of for*/
}/*End of create_graph()*/

int ch;
do
{
    printf("\nMenu\n");
    printf("1>Create Graph\n");
    printf("2>BFS Traversal\n");
    printf("3>Return to BFS\n");
    printf("4>exit\n");

    printf("Enter Your Choice\n");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
        create_graph();
        break;
    case 2:
        BF_Traversal();
        break;
    case 3:
        BFS_0();
        break;
    case 4:
        exit(1);
    }
}
while(1);
}

void BFS_7()
{
#define initial 1
#define waiting 2
#define visited 3

int n;    /*Number of vertices in the graph*/
int adj[MAX][MAX]; /*Adjacency Matrix*/
int state[MAX]; /*can be initial, waiting or visited*/
int label[MAX]; /*Denotes the Component Number*/
int queue[MAX], front = -1,rear = -1;


void insert_queue(int vertex)
{
	if (rear == MAX-1)
		printf("Queue Overflow\n");
	else
	{
		if(front == -1)  /*If queue is initially empty */
			front = 0;
		rear = rear+1;
		queue[rear] = vertex ;
	}
}/*End of insert_queue()*/

int delete_queue()
{
	int del_item;
	if (front == -1 || front > rear)
	{
		printf("Queue Underflow\n");
		exit(1);
	}

	del_item = queue[front];
	front = front+1;
	return del_item;

}/*End of delete_queue() */


int isEmpty_queue()
{
	if(front == -1 || front > rear )
		return 1;
	else
		return 0;
}/*End of isEmpty_queue()*/

void BFS(int v, int component_Num)
{
	int i;

	insert_queue(v);
	state[v] = waiting;

	while(!isEmpty_queue())
	{
		v = delete_queue();
		state[v] = visited;
		label[v] = component_Num;
		printf("Vertex %d  Component = %d\n",v, label[v]);

		for(i=0; i<n; i++)
		{
			/* Check for adjacent unvisited vertices */
			if( adj[v][i] == 1 && state[i] == initial)
			{
				insert_queue(i);
				state[i] = waiting;
			}
		}
	}
	printf("\n");
}/*End of BFS()*/
void BF_Traversal()
{
	int v, components = 0;

	for(v=0;v<n;v++)
		state[v] = initial;

	components++;
    BFS(0, components); /*start BFS from vertex 0*/

	for(v=0; v<n; v++)
	{
		if(state[v] == initial)
		{
			components++;
			BFS(v, components);
		}
	}
	printf("Number of connected components = %d\n", components);

	if(components == 1)
		printf("Connected Graph\n");
	else
		printf("Not a Connected Graph\n");

}/*End of BF_Traversal()*/




void create_graph()
{
	int i,max_edges,origin,destin;

	printf("Enter number of vertices : ");
	scanf("%d",&n);
	max_edges = n*(n-1)/2; /*Undirected graph*/

	for(i=1;i<=max_edges;i++)
	{
		printf("Enter edge %d( -1 -1 to quit ) : ",i);
		scanf("%d %d",&origin,&destin);

		if((origin == -1) && (destin == -1))
			break;

		if( origin >= n || destin >= n || origin<0 || destin<0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
		{
			adj[origin][destin]=1;
			adj[destin][origin]=1;
		}
	}/*End of for*/
}/*End of create_graph()*/

int ch;
do
{
    printf("\n Menu \n");
    printf("1.Create Graph\n");
    printf("2.BFS Traversal\n");
    printf("3.Return to BFS\n");
    printf("4.exit\n");

    printf("Enter Your choice\n");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
        create_graph();
    case 2:
        BF_Traversal();
    case 3:
        BFS_0();
    case 4:
        exit(1);
    }
}
while(1);

}

int ch;
do
{
    printf("\n Menu \n");
    printf("1.Visiting only those vertices that are reachable from start vertex\n");
    printf("2.Visiting All The Nodes\n");
    printf("3.finding shortest distance and shortest path of any vertex from start vertex\n");
    printf("4.Showing All the Tree Edges\n");
    printf("5.for traversing an UNDIRECTED graph through BFS\n");
    printf("6.to find whether an undirected graph is connected or not\n");
    printf("7.To Find Connected Components in an Undirected Graph\n");
    printf("8.Return to graph\n");
    printf("9.Exit\n");

    printf("Enter your choice\n");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
        BFS_1();
        break;
    case 2:
        BFS_2();
        break;
    case 3:
        BFS_3();
        break;
    case 4:
        BFS_4();
        break;
    case 5:
        BFS_5();
        break;
    case 6:
        BFS_6();
        break;
    case 7:
        BFS_7();
        break;
    case 8:
        Graph();
        break;
    case 9:
        exit(1);
    default:
        printf("Wrong Choice\n");
    }
}
while(1);
}

void DFS_0()
{
void DFS_1()
{

#define initial 1
#define visited 2

int n;    /* Number of nodes in the graph */
int adj[MAX][MAX]; /*Adjacency Matrix*/
int state[MAX]; /*Can be initial or visited */
int stack[MAX];
int top = -1;

void push(int v)
{
	if(top == (MAX-1))
	{
		printf("Stack Overflow\n");
		return;
	}
	top=top+1;
	stack[top] = v;

}/*End of push()*/

int isEmpty_stack( )
{
  if(top == -1)
	  return 1;
  else
	  return 0;
}/*End if isEmpty_stack()*/
int pop()
{
	int v;
	if(top == -1)
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	else
	{
		v = stack[top];
		top=top-1;
		return v;
	}
}/*End of pop()*/

void DFS(int v)
{
	int i;
	push(v);
	while(!isEmpty_stack())
	{
		v = pop();
		if(state[v]==initial)
		{
			printf("%d ",v);
			state[v]=visited;
		}
		for(i=n-1; i>=0; i--)
		{
			if(adj[v][i]==1 && state[i]==initial)
				push(i);
		}
	}
}/*End of DFS( )*/

void DF_Traversal()
{
	int v;

	for(v=0; v<n; v++)
		state[v]=initial;

	printf("Enter starting node for Depth First Search : ");
	scanf("%d",&v);
	DFS(v);
	printf("\n");
}/*End of DF_Traversal( )*/

void create_graph()
{
	int i,max_edges,origin,destin;

	printf("Enter number of nodes : ");
	scanf("%d",&n);
	max_edges=n*(n-1);

	for(i=1;i<=max_edges;i++)
	{
		printf("Enter edge %d( -1 -1 to quit ) : ",i);
		scanf("%d %d",&origin,&destin);

		if( (origin == -1) && (destin == -1) )
			break;

		if( origin >= n || destin >= n || origin<0 || destin<0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
		{
			adj[origin][destin] = 1;
		}
	}
}

int ch;
do
{
    printf("\nMenu\n");
    printf("1.Create Graph\n");
    printf("2.DFS Traversal\n");
    printf("3.Return to DFS\n");
    printf("4.Exit\n");

    printf("Enter Your Choice\n");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
        create_graph();
        break;
    case 2:
        DF_Traversal();
        break;
    case 3:
        DFS_0();
        break;
    case 4:
        exit(1);
    }
}
while(1);
}

void DFS_2()
{

#define initial 1
#define visited 2
int n;    /*Number of vertices in the graph*/
int adj[MAX][MAX]; /*Adjacency Matrix*/
int state[MAX]; /*Can be initial or visited*/
int stack[MAX];
int top = -1;



void push(int v)
{
	if(top == (MAX-1))
	{
		printf("Stack Overflow\n");
		return;
	}
	top = top+1;
	stack[top] = v;
}/*End of push()*/

int pop()
{
	int v;
	if(top == -1)
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	else
	{
		v = stack[top];
		top = top-1;
		return v;
	}
}/*End of pop()*/


int isEmpty_stack( )
{
  if( top == -1)
	  return 1;
  else
	  return 0;
}/*End if isEmpty_stack()*/

void DFS(int v)
{
	int i;

	push(v);
	while(!isEmpty_stack())
	{
		v = pop();
		if(state[v]==initial)
		{
            printf("%d ",v);
            state[v] = visited;
		}
		for(i=n-1; i>=0; i--)
			if(adj[v][i]==1 && state[i]==initial)
				push(i);
	}
}/*End of DFS( )*/

void DF_Traversal()
{
	int v;

	for(v=0; v<n; v++)
		state[v] = initial;

	printf("Enter starting vertex for Depth First Search : ");
	scanf("%d",&v);
	DFS(v);
	for(v=0; v<n; v++)
	{
		if(state[v] == initial)
			DFS(v);
	}
	printf("\n");
}/*End of DF_Traversal( )*/



void create_graph()
{
	int i,max_edges,origin,destin;

	printf("Enter number of vertices : ");
	scanf("%d",&n);
	max_edges = n*(n-1);

	for(i=1;i<=max_edges;i++)
	{
		printf("Enter edge %d( -1 -1 to quit ) : ",i);
		scanf("%d %d",&origin,&destin);

		if((origin == -1) && (destin == -1))
			break;

		if(origin >= n || destin >= n || origin<0 || destin<0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
		{
			adj[origin][destin] = 1;
		}
	}
}/*End of create_graph*/
int ch;
do
{
    printf("\n Menu \n");
    printf("1.Create graph\n");
    printf("2.DFS Traversal\n");
    printf("3.Return to DFS\n");
    printf("4.Exit\n");

    printf("Enter Your Choice\n");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
        create_graph();
        break;
    case 2:
        DF_Traversal();
        break;
    case 3:
        DFS_0();
        break;
    case 4:
        exit(1);
    }
}
while(1);
}

void DFS_3()
{
#define NIL -1
#define initial 1
#define visited 2

int n;    /* Number of vertices in the graph */
int adj[MAX][MAX]; /*Adjacency Matrix*/
int predecessor[MAX];
int state[MAX]; /*Can be initial or visited */

int stack[MAX];
int top = -1;

void push(int v)
{
	if(top == (MAX-1))
	{
		printf("Stack Overflow\n");
		return;
	}
	top = top+1;
	stack[top] = v;

}/*End of push()*/

int pop()
{
	int v;
	if(top == -1)
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	else
	{
		v = stack[top];
		top = top-1;
		return v;
	}
}/*End of pop()*/

int isEmpty_stack()
{
  if(top == -1)
	  return 1;
  else
	  return 0;
}/*End if isEmpty_stack()*/

void DFS(int v)
{
	int i;
	push(v);
	while(!isEmpty_stack())
	{
		v = pop();
		if(state[v]==initial)
		{
            printf("%d ",v);
            state[v] = visited;
		}
		for(i=n-1; i>=0; i--)
		{
			if(adj[v][i]==1 && state[i]==initial)
			{
				push(i);
				predecessor[i] = v;
			}
        }
	}
}/*End of DFS( )*/
void DF_Traversal()
{
	int v;

	for(v=0; v<n; v++)
	{
		state[v] = initial;
		predecessor[v] = NIL;
	}

	printf("Enter starting vertex for Depth First Search : ");
	scanf("%d",&v);
	DFS(v);
	for(v=0; v<n; v++)
	{
		if(state[v] == initial)
			DFS(v);
	}
	printf("\n");
	for(v=0; v<n; v++)
         printf("Vertex %d, Predecessor %d\n", v,predecessor[v]);

	printf("Tree Edges : ");
	for(v=0; v<n; v++)
	{
		if(predecessor[v]!=-1)
            printf("Tree edge : %d->%d\n", predecessor[v], v);
	}
}/*End of DF_Traversal( )*/

void create_graph()
{
	int i,max_edges,origin,destin;

	printf("Enter number of vertices : ");
	scanf("%d",&n);
	max_edges = n*(n-1);

	for(i=1;i<=max_edges;i++)
	{
		printf("Enter edge %d( -1 -1 to quit ) : ",i);
		scanf("%d %d",&origin,&destin);

		if( (origin == -1) && (destin == -1) )
			break;

		if( origin >= n || destin >= n || origin<0 || destin<0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
		{
			adj[origin][destin] = 1;
		}
	}
}

int ch;
do
{
    printf("\n Menu \n");
    printf("1.Create Graph\n");
    printf("2.DFS Traversal\n");
    printf("3.Return to DFS\n");
    printf("4.Exit\n");

    printf("Enter Your Choice\n");
    scanf("%d",&ch);

switch(ch)
{
case 1:
create_graph();
break;
case 2:
DF_Traversal();
break;
case 3:
DFS_0();
break;
case 4:
exit(1);
}
}
while(1);
}

void DFS_4()
{

#define initial 1
#define visited 2

int n;    /*Number of vertices in the graph */
int adj[MAX][MAX]; /*Adjacency Matrix*/
int state[MAX]; /*Can be initial or visited */

int stack[MAX];
int top = -1;

void push(int v)
{
	if(top == (MAX-1))
	{
		printf("Stack Overflow\n");
		return;
	}
	top = top+1;
	stack[top] = v;

}/*End of push()*/


int pop()
{
	int v;
	if(top == -1)
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	else
	{
		v = stack[top];
		top = top-1;
		return v;
	}
}/*End of pop()*/





int isEmpty_stack( )
{
  if(top == -1)
	  return 1;
  else
	  return 0;
}/*End if isEmpty_stack()*/

void DFS(int v)
{
	int i;

	push(v);
	while(!isEmpty_stack())
	{
		v = pop();
		if(state[v]==initial)
		{
			printf("%d ",v);
			state[v] = visited;
		}
		for(i=n-1; i>=0; i--)
			if(adj[v][i]==1 && state[i]==initial)
				push(i);
	}
}/*End of DFS( )*/

void DF_Traversal()
{
	int v;

	for(v=0; v<n; v++)
		state[v] = initial;

	printf("Enter starting vertex for Depth First Search : ");
	scanf("%d",&v);
	DFS(v);
	for(v=0; v<n; v++)
	{
		if(state[v] == initial)
			DFS(v);
	}
	printf("\n");
}/*End of DF_Traversal( )*/

void create_graph()
{
	int i,max_edges,origin,destin;

	printf("Enter number of vertices : ");
	scanf("%d",&n);
	max_edges = n*(n-1)/2;

	for(i=1; i<=max_edges; i++)
	{
		printf("Enter edge %d(-1 -1 to quit) : ",i);
		scanf("%d %d",&origin,&destin);

		if( (origin==-1) && (destin==-1) )
			break;

		if( origin>=n || destin>=n || origin<0 || destin<0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
		{
			adj[origin][destin] = 1;
			adj[destin][origin] = 1;
		}
	}/*End of for*/
}/*End if create_graph( )*/

int ch;
do
{
    printf("\nMenu\n");
    printf("1.Create graph\n");
    printf("2.DFS Traversal\n");
    printf("3.Return To DFS\n");
    printf("4.Exit\n");

    printf("ENter Your CHoice\n");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:
            create_graph();
            break;
        case 2:
            DF_Traversal();
            break;
        case 3:
            DFS_0();
            break;
        case 4:
            exit(1);
    }
}
while(1);
}

int ch;
do
{
    printf("\nMenu\n");
    printf("1.visiting only vertices reachable from start vertex\n");
    printf("2.visiting all the vertices\n");
    printf("3.showing all tree edges and predecessors of all vertices\n");
    printf("4.traversing an UNDIRECTED graph through DFS, visiting all the vertices\n");
    printf("5.return to Graph\n");
    printf("6.exit\n");

    printf("Enter Your Choice\n");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:
        DFS_1();
        break;
    case 2:
        DFS_2();
        break;
    case 3:
        DFS_3();
        break;
    case 4:
        DFS_4();
        break;
    case 5:
        Graph();
        break;
    case 6:
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
printf("\n MENU \n");
printf("1.Creation of Adjacency Matrix\n");
printf("2.Directed graph using Adjacency matrix\n");
printf("3.Directed graph using Adjacency list\n");
printf("4.Creation of Path Matrix\n");
printf("5.Traversing through BFS\n");
printf("6.Traversing through DFS\n");
printf("7.return to main\n");
printf("8.exit\n");

printf("Enter your choice\n");
scanf("%d",&ch);

switch(ch)
{
case 1:
    Adjacency_Matrix();
    break;
case 2:
    Directed_Graph_Adjacency_Matrix();
    break;
case 3:
    Directed_graph_Adjacency_List();
    break;
case 4:
    path_matrix();
    break;
case 5:
    BFS_0();
    break;
case 6:
    DFS_0();
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
