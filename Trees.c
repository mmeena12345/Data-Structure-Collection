#include<stdio.h>
#include<stdlib.h>
#include"dsa.h"
#define MAX_VAL 9999   /*All values in heap should be less than this value*/
#define M 5	/*order of B tree*/
#define MAX (M-1)	/*Maximum number of permissible keys in a node*/
#if M%2==0
#define CEIL_Mdiv2 (M/2)
#else
#define CEIL_Mdiv2 ((M+1)/2)
#endif

#define MIN (CEIL_Mdiv2-1)	/*Minimum number of permissible keys in a node except root*/


void Tree()
{
void BST() /* Recursive Operation in Binary Search Tree */
{
struct node
{
	struct node *lchild;
	int info;
	struct node *rchild;
};
struct node *Min(struct node *ptr)
{
	if(ptr==NULL)
		return NULL;
	else if(ptr->lchild==NULL)
        return ptr;
	else
		return Min(ptr->lchild);
}/*End of min()*/

struct node *Max(struct node *ptr)
{
	if(ptr==NULL)
		return NULL;
	else if(ptr->rchild==NULL)
        return ptr;
	else
		return Max(ptr->rchild);
}/*End of max()*/

struct node *search(struct node *ptr, int skey)
{
	if(ptr==NULL)
	{
		printf("key not found\n");
		return NULL;
	}
	else if(skey < ptr->info)/*search in left subtree*/
		return search(ptr->lchild, skey);
	else if(skey > ptr->info)/*search in right subtree*/
		return search(ptr->rchild, skey);
	else /*skey found*/
		return ptr;
}/*End of search()*/

struct node *insert(struct node *ptr, int ikey )
{
	if(ptr==NULL)
	{
		ptr = (struct node *) malloc(sizeof(struct node));
		ptr->info = ikey;
		ptr->lchild = NULL;
		ptr->rchild = NULL;
	}
	else if(ikey < ptr->info)	/*Insertion in left subtree*/
		ptr->lchild = insert(ptr->lchild, ikey);
	else if(ikey > ptr->info)	/*Insertion in right subtree */
		ptr->rchild = insert(ptr->rchild, ikey);
	else
		printf("Duplicate key\n");
	return ptr;
}/*End of insert( )*/

struct node *del(struct node *ptr, int dkey)
{
	struct node *tmp, *succ;

	if( ptr == NULL)
	{
		printf("dkey not found\n");
		return(ptr);
	}
	if( dkey < ptr->info )/*delete from left subtree*/
		ptr->lchild = del(ptr->lchild, dkey);
	else if( dkey > ptr->info )/*delete from right subtree*/
		ptr->rchild = del(ptr->rchild, dkey);
	else
	{
		/*key to be deleted is found*/
		if( ptr->lchild!=NULL  &&  ptr->rchild!=NULL )  /*2 children*/
		{
			succ=ptr->rchild;
			while(succ->lchild)
				succ=succ->lchild;
			ptr->info=succ->info;
			ptr->rchild = del(ptr->rchild, succ->info);
		}
		else
		{
			tmp = ptr;
			if( ptr->lchild != NULL ) /*only left child*/
				ptr = ptr->lchild;
			else if( ptr->rchild != NULL) /*only right child*/
				ptr = ptr->rchild;
			else	/* no child */
				ptr = NULL;
			free(tmp);
		}
	}
	return ptr;
}/*End of del( )*/

void preorder(struct node *ptr)
{
	if(ptr == NULL )	/*Base Case*/
		return;
	printf("%d  ",ptr->info);
	preorder(ptr->lchild);
	preorder(ptr->rchild);
}/*End of preorder( )*/

void inorder(struct node *ptr)
{
	if(ptr == NULL )/*Base Case*/
		return;
	inorder(ptr->lchild);
	printf("%d  ",ptr->info);
	inorder(ptr->rchild);
}/*End of inorder( )*/

void postorder(struct node *ptr)
{
	if(ptr == NULL )/*Base Case*/
		return;
	postorder(ptr->lchild);
	postorder(ptr->rchild);
	printf("%d  ",ptr->info);

}/*End of postorder( )*/

int height(struct node *ptr)
{
	int h_left, h_right;

	if (ptr == NULL) /*Base Case*/
		return 0;

	h_left =  height(ptr->lchild);
	h_right = height(ptr->rchild);

	if (h_left > h_right)
		return 1 + h_left;
	else
		return 1 + h_right;
}/*End of height()*/

struct node *root=NULL,*ptr;
	int choice,k;

	while(1)
	{
		printf("\n Menu \n");
		printf("1.Search\n");
		printf("2.Insert\n");
		printf("3.Delete\n");
		printf("4.Preorder Traversal\n");
		printf("5.Inorder Traversal\n");
		printf("6.Postorder Traversal\n");
		printf("7.Height of tree\n");
		printf("8.Find minimum and maximum\n");
		printf("9.Return to Tree\n");
		printf("10.Quit\n");

		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1:
			printf("Enter the key to be searched : ");
			scanf("%d",&k);
			ptr = search(root, k);
			if(ptr!=NULL)
				printf("Key found\n");
			break;
		case 2:
			printf("Enter the key to be inserted : ");
			scanf("%d",&k);
			root = insert(root, k);
			break;
		case 3:
			printf("Enter the key to be deleted : ");
			scanf("%d",&k);
			root = del(root,k);
			break;
		 case 4:
			preorder(root);
			break;
		 case 5:
			inorder(root);
			break;
		 case 6:
			postorder(root);
			break;
		 case 7:
			 printf("Height of tree is %d\n", height(root));
			 break;
		 case 8:
			ptr = Min(root);
			if(ptr!=NULL)
				printf("Minimum key is %d\n", ptr->info );
			ptr = Max(root);
			if(ptr!=NULL)
				printf("Maximum key is %d\n", ptr->info );
			break;
         case 9:
            Tree();
            break;
		 case 10:
			exit(1);
		 default:
			printf("Wrong choice\n");
		}/*End of switch */
	}/*End of while */

}

void Threaded_BST()
{
    typedef enum {false,true} boolean;

    struct node
{
	struct node *left;
	boolean lthread;
	int info;
	boolean rthread;
	struct node *right;
};

struct node *in_succ(struct node *ptr)
{
	if(ptr->rthread==true)
		return ptr->right;
	else
	{
		ptr=ptr->right;
		while(ptr->lthread==false)
			ptr=ptr->left;
		return ptr;
	}
}/*End of in_succ( )*/

struct node *in_pred(struct node *ptr)
{
	if(ptr->lthread==true)
		return ptr->left;
	else
	{
		ptr=ptr->left;
		while(ptr->rthread==false)
			ptr=ptr->right;
		return ptr;
	}
}/*End of in_pred( )*/

struct node *insert(struct node *root, int ikey)
{
	struct node *tmp,*par,*ptr;

	int found=0;

	ptr = root;
	par = NULL;

	while( ptr!=NULL )
	{
		if( ikey == ptr->info)
		{
			found =1;
			break;
		}
		par = ptr;
		if(ikey < ptr->info)
		{
			if(ptr->lthread == false)
				ptr = ptr->left;
			else
				break;
		}
		else
		{
			if(ptr->rthread == false)
				ptr = ptr->right;
			else
				break;
		}
	}

	if(found)
		printf("Duplicate key");
	else
	{

		tmp=(struct node *)malloc(sizeof(struct node));
		tmp->info=ikey;
		tmp->lthread = true;
		tmp->rthread = true;
		if(par==NULL)
		{
			root=tmp;
			tmp->left=NULL;
			tmp->right=NULL;
		}
		else if( ikey < par->info )
		{
			tmp->left=par->left;
			tmp->right=par;
			par->lthread=false;
			par->left=tmp;
		}
		else
		{
			tmp->left=par;
			tmp->right=par->right;
			par->rthread=false;
			par->right=tmp;
		}
	}
	return root;
}/*End of insert( )*/

struct node *case_a(struct node *root, struct node *par,struct node *ptr )
{
	if(par==NULL) /*root node to be deleted*/
		root=NULL;
	else if(ptr==par->left)
	{
		par->lthread=true;
		par->left=ptr->left;
	}
	else
	{
		par->rthread=true;
		par->right=ptr->right;
	}
	free(ptr);
	return root;
}/*End of case_a( )*/

struct node *case_b(struct node *root,struct node *par,struct node *ptr)
{
	struct node *child,*s,*p;

	/*Initialize child*/
	if(ptr->lthread==false) /*node to be deleted has left child */
		child=ptr->left;
	else                /*node to be deleted has right child */
		child=ptr->right;


	if(par==NULL )   /*node to be deleted is root node*/
		root=child;
	else if( ptr==par->left) /*node is left child of its parent*/
		par->left=child;
	else                     /*node is right child of its parent*/
		par->right=child;

	s=in_succ(ptr);
	p=in_pred(ptr);

	if(ptr->lthread==false) /*if ptr has left subtree */
			p->right=s;
	else
	{
		if(ptr->rthread==false) /*if ptr has right subtree*/
			s->left=p;
	}

	free(ptr);
	return root;
}/*End of case_b( )*/

struct node *case_c(struct node *root, struct node *par,struct node *ptr)
{
	struct node *succ,*parsucc;

	/*Find inorder successor and its parent*/
	parsucc = ptr;
	succ = ptr->right;
	while(succ->left!=NULL)
	{
		parsucc = succ;
		succ = succ->left;
	}

	ptr->info = succ->info;

	if(succ->lthread==true && succ->rthread==true)
		root = case_a(root, parsucc,succ);
	else
		root = case_b(root, parsucc,succ);
	return root;
}/*End of case_c( )*/
struct node *del(struct node *root, int dkey)
{
	struct node *par,*ptr;

	int found=0;

	ptr = root;
	par = NULL;

	while( ptr!=NULL)
	{
		if( dkey == ptr->info)
		{
			found =1;
			break;
		}
		par = ptr;
		if(dkey < ptr->info)
		{
			if(ptr->lthread == false)
				ptr = ptr->left;
			else
				break;
		}
		else
		{
			if(ptr->rthread == false)
				ptr = ptr->right;
			else
				break;
		}
	}

	if(found==0)
		printf("dkey not present in tree");
	else if(ptr->lthread==false && ptr->rthread==false)/*2 children*/
		root = case_c(root,par,ptr);
	else if(ptr->lthread==false )/*only left child*/
        root = case_b(root, par,ptr);
	else if(ptr->rthread==false)/*only right child*/
        root = case_b(root, par,ptr);
	else /*no child*/
		root = case_a(root,par,ptr);
	return root;
}/*End of del( )*/




void inorder( struct node *root)
{
	struct node *ptr;
	if(root == NULL )
	{
		printf("Tree is empty");
		return;
	}

	ptr=root;
	/*Find the leftmost node */
	while(ptr->lthread==false)
		ptr=ptr->left;

	while( ptr!=NULL )
	{
		printf("%d ",ptr->info);
		ptr=in_succ(ptr);
	}
}/*End of inorder( )*/

void preorder(struct node *root )
{
	struct node *ptr;
	if(root==NULL)
	{
		printf("Tree is empty");
		return;
	}
	ptr=root;

	while(ptr!=NULL)
	{
		printf("%d ",ptr->info);
		if(ptr->lthread==false)
			ptr=ptr->left;
		else if(ptr->rthread==false)
			ptr=ptr->right;
		else
		{
			while(ptr!=NULL && ptr->rthread==true)
				ptr=ptr->right;
			if(ptr!=NULL)
				ptr=ptr->right;
		}
	}
}/*End of preorder( )*/

int choice,num;
	struct node *root=NULL;

	while(1)
	{
		printf("\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Inorder Traversal\n");
		printf("4.Preorder Traversal\n");
		printf("5.Return to Tree\n");
		printf("6.Quit\n");

		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			printf("Enter the number to be inserted : ");
			scanf("%d",&num);
			root = insert(root,num);
			break;
		 case 2:
			printf("Enter the number to be deleted : ");
			scanf("%d",&num);
			root = del(root,num);
			break;
		 case 3:
			inorder(root);
			break;
		 case 4:
			preorder(root);
			break;
         case 5:
            Tree();
            break;
		 case 6:
			 exit(1);
		 default:
			printf("Wrong choice\n");
		}/*End of switch */
	}/*End of while */
}

void AVL_Tree()
{
#define FALSE 0
#define TRUE 1

struct node
{
	struct  node *lchild;
	int info;
	struct  node *rchild;
	int balance;
};

struct node *RotateRight(struct node *pptr)
{
	struct node *aptr;
	aptr = pptr->lchild;	/*A is left child of P */
	pptr->lchild = aptr->rchild; /*Right child of A becomes left child of P*/
	aptr->rchild = pptr;			/*P becomes right child of A*/
	return aptr; /*A is the new root of the subtree initially rooted at P*/
}/*End of RotateRight( )*/


struct node *RotateLeft(struct node *pptr)
{
	struct node *aptr;
	aptr = pptr->rchild;	/*A is right child of P*/
	pptr->rchild = aptr->lchild; /*Left child of A becomes right child of P */
	aptr->lchild = pptr;  /*P becomes left child of A*/
	return aptr;  /*A is the new root of the subtree initially rooted at P*/
}/*End of RotateLeft( )*/

struct node *insert_LeftBalance(struct node *pptr)
{
	struct node *aptr, *bptr;

	aptr = pptr->lchild;
	if(aptr->balance == 1)  /* Case L_C1 : Insertion in AL */
	{
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateRight(pptr);
	}
	else		/* Case L_C2 : Insertion in AR */
	{
		bptr = aptr->rchild;
		switch(bptr->balance)
		{
		case -1:			/* Case L_C2a : Insertion in BR */
			pptr->balance = 0;
			aptr->balance = 1;
			break;
		case 1:					/* Case L_C2b : Insertion in BL */
			pptr->balance = -1;
			aptr->balance = 0;
			break;
		case 0:					/* Case L_C2c : B is the newly inserted node */
			pptr->balance = 0;
			aptr->balance = 0;
		}
		bptr->balance = 0;
		pptr->lchild = RotateLeft(aptr);
		pptr = RotateRight(pptr);
	}
	return pptr;
}/*End of insert_LeftBalance( )*/

struct node *insert_RightBalance(struct node *pptr)
{
	struct node *aptr, *bptr;

	aptr = pptr->rchild;
	if(aptr->balance == -1) /* Case R_C1 : Insertion in AR */
	{
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateLeft(pptr);
	}
	else		/* Case R_C2 : Insertion in AL */
	{
		bptr = aptr->lchild;
		switch(bptr->balance)
		{
		case -1:	/* Case R_C2a : Insertion in BR */
			pptr->balance = 1;
			aptr->balance = 0;
			break;
		case 1:		/* Case R_C2b : Insertion in BL */
			pptr->balance = 0;
			aptr->balance = -1;
			break;
		case 0:		/* Case R_C2c : B is the newly inserted node */
			pptr->balance = 0;
			aptr->balance = 0;
		}
		bptr->balance = 0;
		pptr->rchild = RotateRight(aptr);
		pptr = RotateLeft(pptr);
	}
	return pptr;
}/*End of insert_RightBalance( )*/

struct node *del_RightBalance(struct node *pptr,int *pshorter)
{
	struct node *aptr, *bptr;

	aptr = pptr->rchild;
	if (aptr->balance == 0)	/* Case L_C1 */
	{
		pptr->balance = -1;
		aptr->balance = 1;
		*pshorter = FALSE;
		pptr = RotateLeft(pptr);
	}
	else if(aptr->balance == -1 )	/* Case L_C2 */
	{
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateLeft(pptr);
	}
	else							/* Case L_C3 */
	{
		bptr = aptr->lchild;
		switch(bptr->balance)
		{
			case 0:					/* Case L_C3a */
				pptr->balance = 0;
				aptr->balance = 0;
				break;
			case 1:					/* Case L_C3b */
				pptr->balance = 0;
				aptr->balance = -1;
				break;
			case -1:				/* Case L_C3c */
				pptr->balance = 1;
				aptr->balance = 0;
		}
		bptr->balance = 0;
		pptr->rchild = RotateRight(aptr);
		pptr = RotateLeft(pptr);
	}
	return pptr;
}/*End of del_RightBalance( )*/

struct node *del_left_check(struct node *pptr, int *pshorter)
{
	switch(pptr->balance)
	{
		case 0: /* Case L_A : was balanced */
			pptr->balance = -1;	/* now right heavy */
			*pshorter = FALSE;
			break;
		case 1: /* Case L_B : was left heavy */
			pptr->balance = 0;	/* now balanced */
			break;
		case -1: /* Case L_C : was right heavy */
			pptr = del_RightBalance(pptr, pshorter); /*Right Balancing*/
	}
	return pptr;
}/*End of del_left_check( )*/

struct node *del_LeftBalance(struct node *pptr,int *pshorter)
{
	struct node *aptr, *bptr;
	aptr = pptr->lchild;
	if( aptr->balance == 0)  /* Case R_C1 */
	{
		pptr->balance = 1;
		aptr->balance = -1;
		*pshorter = FALSE;
		pptr = RotateRight(pptr);
	}
	else if(aptr->balance == 1 ) /* Case R_C2 */
	{
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateRight(pptr);
	}
	else						/* Case R_C3 */
	{
		bptr = aptr->rchild;
		switch(bptr->balance)
		{
			case 0:					/* Case R_C3a */
				pptr->balance = 0;
				aptr->balance = 0;
				break;
			case 1:					/* Case R_C3b */
				pptr->balance = -1;
				aptr->balance = 0;
				break;
			case -1:			/* Case R_C3c */
				pptr->balance = 0;
				aptr->balance = 1;
		}
		bptr->balance = 0;
		pptr->lchild = RotateLeft(aptr);
		pptr = RotateRight(pptr);
	}
	return pptr;
}/*End of del_LeftBalance( )*/

struct node *del_right_check(struct node *pptr, int *pshorter)
{
	switch(pptr->balance)
	{
		case 0:		/* Case R_A : was balanced */
			pptr->balance = 1;	/* now left heavy */
			*pshorter = FALSE;
			break;
		case -1: /* Case R_B : was right heavy */
			pptr->balance = 0;	/* now balanced */
			break;
		case 1: /* Case R_C : was left heavy */
			pptr = del_LeftBalance(pptr, pshorter );  /*Left Balancing*/
	}
	return pptr;
}/*End of del_right_check( )*/

struct node *insert_left_check(struct node *pptr, int *ptaller )
{
	switch(pptr->balance)
	{
	 case 0: /* Case L_A : was balanced */
		pptr->balance = 1;	/* now left heavy */
		break;
	 case -1: /* Case L_B: was right heavy */
		pptr->balance = 0;	/* now balanced */
		*ptaller = FALSE;
			break;
	 case 1: /* Case L_C: was left heavy */
		pptr = insert_LeftBalance(pptr);	/* Left Balancing */
		*ptaller = FALSE;
	}
	return pptr;
}/*End of insert_left_check( )*/

struct node *insert_right_check(struct node *pptr, int *ptaller )
{
	switch(pptr->balance)
	{
	 case 0: /* Case R_A : was balanced */
		pptr->balance = -1;	/* now right heavy */
		break;
	 case 1: /* Case R_B : was left heavy */
		pptr->balance = 0;	/* now balanced */
		*ptaller = FALSE;
		break;
	 case -1: /* Case R_C: Right heavy */
		pptr = insert_RightBalance(pptr);	/* Right Balancing */
		*ptaller = FALSE;
	}
	return pptr;
}/*End of insert_right_check( )*/

struct node *insert(struct node *pptr, int ikey)
{
	static int taller;
	if(pptr==NULL)	/*Base case*/
	{
		pptr = (struct node *) malloc(sizeof(struct node));
		pptr->info = ikey;
		pptr->lchild = NULL;
		pptr->rchild = NULL;
		pptr->balance = 0;
		taller = TRUE;
	}
	else if(ikey < pptr->info)	/*Insertion in left subtree*/
	{
		pptr->lchild = insert(pptr->lchild, ikey);
		if(taller==TRUE)
			pptr = insert_left_check( pptr, &taller );
	}
	else if(ikey > pptr->info)	/*Insertion in right subtree */
	{
		pptr->rchild = insert(pptr->rchild, ikey);
		if(taller==TRUE)
			pptr = insert_right_check(pptr, &taller);
	}
	else  /*Base Case*/
	{
		printf("Duplicate key\n");
		taller = FALSE;
	}
	return pptr;
}/*End of insert( )*/

struct node *del(struct node *pptr, int dkey)
{
	struct node *tmp, *succ;
	static int shorter;

	if( pptr == NULL) /*Base Case*/
	{
		printf("Key not present \n");
		shorter = FALSE;
		return(pptr);
	}
	if( dkey < pptr->info )
	{
		pptr->lchild = del(pptr->lchild, dkey);
		if(shorter == TRUE)
			pptr = del_left_check(pptr, &shorter);
	}
	else if( dkey > pptr->info )
	{
		pptr->rchild = del(pptr->rchild, dkey);
		if(shorter==TRUE)
			pptr = del_right_check(pptr, &shorter);
	}
	else /* dkey == pptr->info, Base Case*/
	{
		/*pptr has 2 children*/
		if( pptr->lchild!=NULL  &&  pptr->rchild!=NULL )
		{
			succ = pptr->rchild;
			while(succ->lchild)
				succ = succ->lchild;
			pptr->info = succ->info;
			pptr->rchild = del(pptr->rchild, succ->info);
			if( shorter == TRUE )
				pptr = del_right_check(pptr, &shorter);
		}
		else
		{
			tmp = pptr;
			if( pptr->lchild != NULL ) /*only left child*/
				pptr = pptr->lchild;
			else if( pptr->rchild != NULL) /*only right child*/
				pptr = pptr->rchild;
			else	/* no children */
				pptr = NULL;
			free(tmp);
			shorter = TRUE;
		}
	}
	return pptr;
}/*End of del( )*/

void inorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->lchild);
		printf("%d  ",ptr->info);
		inorder(ptr->rchild);
	}
}/*End of inorder()*/

    int choice,key;
	struct node *root = NULL;

	while(1)
	{
		printf("\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Inorder Traversal\n");
		printf("4.Return to Tree\n");
		printf("5.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			printf("Enter the key to be inserted : ");
			scanf("%d",&key);
			root = insert(root,key);
			break;
		 case 2:
			printf("Enter the key to be deleted : ");
			scanf("%d",&key);
			root = del(root,key);
			break;
		 case 3:
			inorder(root);
			break;
         case 4:
            Tree();
            break;
		 case 5:
			exit(1);
		 default:
			printf("Wrong choice\n");
		}/*End of switch */
	}/*End of while */
}

void Red_Black_Tree()
{
    struct node
{
	enum {black, red} color;
	int info;
	struct  node *lchild;
	struct  node *rchild;
	struct  node *parent;
};
struct node*sentinel,*root;
sentinel = (struct node *) malloc(sizeof(struct node));
	sentinel->info = -1;
	sentinel->color = black;
	root = sentinel;

int find(int item,struct node **loc)
{
	struct node *ptr;

	if(root==sentinel)/*Tree is empty*/
	{
		*loc=sentinel;
		return 0;
	}

	if(item==root->info)/*Item is at root*/
	{
		*loc=root;
		return 1;
	}

	/*Initialize ptr*/
	if(item < root->info)
		ptr=root->lchild;
	else
		ptr=root->rchild;

	while(ptr!=sentinel)
	{
		if(item == ptr->info)
		{
			*loc=ptr;
			return 1;
		}
		if(item < ptr->info)
			ptr=ptr->lchild;
		else
			ptr=ptr->rchild;
	 }//End of while
	 *loc=sentinel;		/*Item not found*/
	 return 0;
}/*End of find()*/

void RotateLeft(struct node *pptr)
{
	struct node *aptr;

	aptr = pptr->rchild;	/*aptr is right child of pptr*/
	pptr->rchild= aptr->lchild;

	if(aptr->lchild !=sentinel)
        aptr->lchild->parent = pptr;

	aptr->parent = pptr->parent;

	if(pptr->parent == sentinel )
		root = aptr;
	else if( pptr == pptr->parent->lchild )
		pptr->parent->lchild = aptr;
	else
		pptr->parent->rchild = aptr;
    aptr->lchild = pptr;
	pptr->parent = aptr;
}/*End of RoatateLeft( )*/

void RotateRight(struct node *pptr)
{
	struct node *aptr;

	aptr = pptr->lchild;
	pptr->lchild= aptr->rchild;

	if(aptr->rchild !=sentinel )
        aptr->rchild->parent = pptr;

	aptr->parent = pptr->parent;

	if(pptr->parent == sentinel )
		root = aptr;
	else if( pptr == pptr->parent->rchild )
		pptr->parent->rchild = aptr;
	else
		pptr->parent->lchild = aptr;

	aptr->rchild = pptr;
	pptr->parent = aptr;
}/*End of RotateRight( )*/

void insert_balance(struct node *nptr )
{
	struct node *uncle, *par, *grandPar;

	while( nptr->parent->color == red )
	{
		par = nptr->parent;
		grandPar = par->parent;

		if( par == grandPar->lchild )
		{
			uncle = grandPar->rchild;

			if(uncle->color == red )	/* Case L_1 */
			{
				par->color = black;
				uncle->color = black;
				grandPar->color =red;
				nptr = grandPar;
			}
			else	/* Uncle is black */
			{
				if( nptr == par->rchild) /* Case L_2a */
				{
					RotateLeft(par);
					nptr = par;
					par = nptr->parent;
				}
				par->color = black;	 /* Case L_2b */
				grandPar->color = red;
				RotateRight(grandPar);
			}
		}
		else
		{
			if(par == grandPar->rchild )
			{
				uncle = grandPar->lchild;

				if(uncle->color == red )  /* Case R_1 */
				{
					par->color = black;
					uncle->color = black;
					grandPar->color =red;
					nptr = grandPar;
				}
				else	/*uncle is black */
				{
					if( nptr == par->lchild)   /* Case R_2a */
					{
						RotateRight(par);
						nptr = par;
						par = nptr->parent;
					}
					par->color = black;    /* Case R_2b */
					grandPar->color = red;
					RotateLeft(grandPar);
				}
			}
		}
	}
	root->color = black;
}/*End of insert_balance()*/

void insert (int ikey )
{
	struct node *tmp, *ptr, *par;

	par = sentinel;
	ptr = root;

	while( ptr != sentinel )
	{
		par = ptr;
		if( ikey < ptr->info )
			ptr = ptr->lchild;
		else if( ikey > ptr->info )
			ptr = ptr->rchild;
		else
		{
			printf("Duplicate\n");
			return;
		}
	}
	tmp = (struct node *) malloc(sizeof(struct node));
	tmp->info = ikey;
	tmp->lchild = sentinel;
	tmp->rchild = sentinel;
	tmp->color = red;
	tmp->parent = par;

	if(par==sentinel)
		root = tmp;
	else if(tmp ->info < par->info )
		par->lchild = tmp;
	else
		par->rchild = tmp;

	insert_balance(tmp);
}/*End of insert( )*/

struct node *succ(struct node *loc)
{
	struct node *ptr=loc->rchild;
	while(ptr->lchild!=sentinel)
	{
		ptr=ptr->lchild;
	}
	return ptr;
}/*End of succ()*/

void display(struct node *ptr,int level)
{
	int i;
	if ( ptr!=sentinel )
	{
		display(ptr->rchild, level+1);
		printf("\n");
		for(i=0; i<level; i++)
			printf("    ");
		printf("%d", ptr->info);
		if(ptr->color==red)
			printf("^");/*sign ^ for RED*/
		else
			printf("*");
		display(ptr->lchild, level+1);
	}
}/*End of display()*/

void del_balance(struct node *nptr)
{
	struct node *sib;

	while( nptr!=root )
	{
 	  if( nptr == nptr->parent->lchild )
	  {
		sib = nptr->parent->rchild;
		if( sib->color == red )/* Case L_1 */
		{
			sib->color = black;
			nptr->parent->color = red;
			RotateLeft(nptr->parent);
			sib = nptr->parent->rchild; /*new sibling*/
		}
		if(sib->lchild->color==black && sib->rchild->color==black)
		{
			sib->color=red;

			if(nptr->parent->color == red )/*Case L_2a*/
			{
				nptr->parent->color = black;
				return;
			}
			else
			    nptr=nptr->parent;	/* Case L_2b */
		}
		else
		{
			if(sib->rchild->color==black)  /*Case L_3a*/
			{
				sib->lchild->color=black;
				sib->color=red;
				RotateRight(sib);
				sib = nptr->parent->rchild;
			}
			sib->color = nptr->parent->color;  /*Case L_3b*/
			nptr->parent->color = black;
			sib->rchild->color = black;
			RotateLeft(nptr->parent);
			return;
		}
	  }
	  else
	  {
		sib = nptr->parent->lchild;
		if( sib->color == red )/* Case R_1 */
		{
			sib->color =black;
			nptr->parent->color = red;
			RotateRight(nptr->parent);
			sib = nptr->parent->lchild;
		}

		if( sib->rchild->color==black && sib->lchild->color==black)
		{
			sib->color=red;
			if(nptr->parent->color == red )/*Case R_2a*/
			{
				nptr->parent->color = black;
				return;
			}
			else
				nptr=nptr->parent; /*Case R_2b */
		}
        else
		{
			if(sib->lchild->color==black)  /*Case R_3a*/
			{
				sib->rchild->color=black;
				sib->color=red;
				RotateLeft(sib);
				display(root,0);
				sib = nptr->parent->lchild;
			}

			sib->color = nptr->parent->color;/*case R_3b*/
			nptr->parent->color = black;
			sib->lchild->color = black;
			RotateRight(nptr->parent);
			return;
		}
	  }
	}/*End of while*/
}/*End of del_balance*/

void del(int item)
{
	struct node *child,*ptr,*successor;

	if( ! find(item, &ptr) )
	{
		printf("item not present \n");
		return;
	}

	if(ptr->lchild != sentinel || ptr->rchild != sentinel )
	{
		successor = succ(ptr);
		ptr->info = successor->info;
		ptr=successor;
	}

	if( ptr->lchild !=sentinel )
		child = ptr->lchild;
	else
		child = ptr->rchild;

	child->parent = ptr->parent;

	if(ptr->parent == sentinel)
		root=child;
	else if( ptr == ptr->parent->lchild )
		ptr->parent->lchild = child;
	else
		ptr->parent->rchild = child;

	if( child == root )
		child->color = black;
    else if( ptr->color == black )/*black node*/
	{
		if( child != sentinel ) /*one child which is red*/
            child->color = black;
		else	/*no child*/
			del_balance(child);
	}

}/*End of del()*/

void inorder(struct node *ptr)
{
	if(ptr!=sentinel)
	{
		inorder(ptr->lchild);
		printf("%d  ",ptr->info);
		inorder(ptr->rchild);
	}
}/*End of inorder()*/

int choice,num;
  while(1)
	{
		printf("\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Inorder Traversal\n");
		printf("4.Display\n");
		printf("5.Return to Tree\n");
		printf("6.Quit\n");

		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			printf("Enter the number to be inserted : ");
			scanf("%d",&num);
			insert(num);
			break;
		 case 2:
			printf("Enter the number to be deleted : ");
			scanf("%d",&num);
			del(num);
			break;
		 case 3:
			inorder(root);
			break;
		 case 4:
			display(root,0);
			break;
         case 5:
            Tree();
            break;
		 case 6:
			exit(1);
		 default:
			printf("Wrong choice\n");
		}/*End of switch */
	}/*End of while */
}

void Heap()
{

    void restoreDown(int arr[], int i, int hsize )
{
	int lchild=2*i, rchild=lchild+1;

	int num=arr[i];

	while( rchild <= hsize )
	{
		if( num>=arr[lchild] && num>=arr[rchild] )
		{
			arr[i] = num;
			return;
		}
		else if(arr[lchild] > arr[rchild])
		{
			arr[i] = arr[lchild];
			i = lchild;
		}
		else
		{
			arr[i] = arr[rchild];
			i = rchild;
		}
		lchild = 2 * i;
		rchild = lchild + 1;
	}
	/*If number of nodes is even*/
	if(lchild == hsize && num < arr[lchild] )
	{
		arr[i]=arr[lchild];
		i = lchild;
	}
	arr[i]=num;
}/*End of restoreDown()*/

    void restoreUp(int arr[], int i)
{
	int k = arr[i];
	int par = i/2;

	/* while( par>=1 && arr[par] < num  )*/  /*if MAX_VAL not in arr[0]*/
	while( arr[par] < k  )
	{
		arr[i]=arr[par];
		i = par;
		par = i/2;
	}
	arr[i] = k;
}/*End of restoreUp()*/

    void insert(int num, int arr[], int *p_hsize )
{
	(*p_hsize)++;  /*Increase the heap size by 1*/
	arr[*p_hsize]=num;
	restoreUp(arr, *p_hsize);
}/*End of insert( )*/

int del_root(int arr[], int *p_hsize)
{
	int max = arr[1]; /* Save the element present at the root*/
	arr[1] = arr[*p_hsize];/* Place the last element in the root */
	(*p_hsize)--;  /* Decrease the heap size by 1 */
	restoreDown(arr,1,*p_hsize);
	return max;
}/*End of del_root()*/

void display(int arr[],int hsize)
{
	int i;
	if(hsize==0)
	{
		printf("Heap is empty\n");
		return;
	}
	for(i=1;i<=hsize;i++)
		printf("%d ",arr[i]);
	printf("\n");

	printf("Number of elements = %d\n",hsize);
}/*End of display( )*/

/*Top down approach*/
void buildHeap(int arr[], int size )
{
	int i;
	for(i=2; i<=size; i++)
		restoreUp(arr,i);
}/*End of buildHeap()*/

/*Bottom up approach*/
/* void buildHeap(int arr[], int size )
{
	int i;
	for(i=size/2; i>=1; i--)
		restoreDown(arr,i,size);
}*/

int arr[100]; /*array used to represent heap*/
	int hsize=0;  /*Number of nodes in the heap*/
	int i,choice,num;

	arr[0]= MAX_VAL;

	while(1)
	{
		printf("1.Insert\n");
		printf("2.Delete root\n");
		printf("3.Display\n");
		printf("4.Build Heap\n");
		printf("5.Return to tree\n");
		printf("6.Exit\n");

		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		 case 1:
			printf("Enter the number to be inserted : ");
			scanf("%d",&num);
			insert(num,arr,&hsize);
			break;
		 case 2:
			if(hsize==0)
				printf("Heap is empty \n");
			else
			{
				num = del_root(arr,&hsize);
				printf("Maximum element is %d\n", num);
			}
			break;
		 case 3:
			display(arr,hsize);
			break;
 		 case 4:
			printf("Enter size of the array ");
			scanf("%d",&hsize);
			printf("Enter array : ");
			for(i=1;i<=hsize;i++)
				scanf("%d",&arr[i]);
			buildHeap(arr,hsize);
			break;
         case 5:
            Tree();
            break;
		 case 6:
			exit(1);
		 default:
			printf("Wrong choice\n");
		}/*End of switch */
	}/*End of while */
}

void B_Tree()
{

   struct node
{
	int count;
	int key[MAX+1];
	struct node *child[MAX+1];
};
struct node *root = NULL, *ptr;

int search_node(int skey, struct node *p, int *pn)
{
	if( skey < p->key[1] )
	{
		*pn = 0;
		return 0;
	}
	*pn = p->count;
	while( ( skey < p->key[*pn] ) && *pn>1 )
		(*pn)--;
	if( skey == p->key[*pn] )
		return 1;
	else
		return 0;
}/*End of search_node()*/

 struct node *Search(int skey, struct node *p, int *pn)
{
	if( p == NULL )  /* Base Case 1 : if key not found */
		return NULL;
	else if( search_node(skey, p, pn ) )	/* Base Case 2 : if key found in node p  */
		return p;
	else         /*Recursive case : Search in node p->child[*pn] */
		return Search( skey, p->child[*pn], pn);
}/*End of Search()*/

void insertByShift( int k, struct node *krchild, struct node *p, int n)
{
	int i;

	for( i = p->count; i > n; i-- )
	{
		p->key[i+1] = p->key[i];
		p->child[i+1] = p->child[i];
	}
	p->key[n+1] = k;
	p->child[n+1] = krchild;
	p->count++;
}/*End of insertByShift()*/

void split(int k, struct node *krchild, struct node *p, int n, int *upkey, struct node **newnode)
{
	int i,j;
	int lastkey;
	struct node *lastchild;
	int d = CEIL_Mdiv2;

	if( n == MAX )
	{
		lastkey = k;
		lastchild = krchild;
	}
	else
	{
		lastkey = p->key[MAX];
		lastchild = p->child[MAX];
		for( i = p->count-1; i > n; i-- )
		{
			p->key[i+1] = p->key[i];
			p->child[i+1] = p->child[i];
		}
		p->key[i+1] = k;
		p->child[i+1] = krchild;
	}
	*newnode = (struct node *)malloc(sizeof(struct node) );
	*upkey = p->key[d];

	for( i=1, j=d+1; j<=MAX; i++,j++ )
	{
		(*newnode)->key[i] = p->key[j];
		(*newnode)->child[i] = p->child[j];
	}

	(*newnode)->child[0] = p->child[d];
	p->count = d-1;/*Number of keys in the left splitted node*/
	(*newnode)->count = M - d;  /*Number of keys in the right splitted node*/
	(*newnode)->key[M-d] = lastkey;
	(*newnode)->child[M-d] = lastchild;
}/*End of split()*/
int rec_ins(int ikey, struct node *p, int *pk, struct node **pkrchild)
{
	int n;
	int flag;

	if( p == NULL )  /* Base case 1 */
	{
		*pk = ikey;
		*pkrchild = NULL;
		return 1;
	}

	if( search_node( ikey, p, &n) ) /* Base Case 2 */
	{
		printf("Duplicate keys are not allowed\n");
		return 0;
	}

	flag = rec_ins( ikey, p->child[n], pk, pkrchild );
	if( flag )
	{
		if( p->count < MAX )
		{
			insertByShift(*pk, *pkrchild, p, n);
			return 0;
		}
		else
		{
			split(*pk, *pkrchild, p, n, pk, pkrchild );
			return 1;  /*median key to be inserted*/
		}
	}
	return 0;
}/*End of rec_ins()*/

struct node *Insert(int ikey, struct node *proot)
{
	int k, taller;
	struct node *krchild, *temp;

	taller = rec_ins(ikey, proot, &k, &krchild);

	if( taller )  /* tree grown in height, new root is created*/
	{
		temp = (struct node *)malloc( sizeof(struct node) );
		temp->count = 1;
		temp->child[0] = proot;
		temp->key[1] = k;
		temp->child[1] = krchild;
		proot = temp;
	}
	return proot;
}/*End of Insert()*/

void delByShift( struct node *p, int n)
{
	int i;
	for( i = n+1; i <= p->count; i++ )
	{
		p->key[i-1] = p->key[i];
		p->child[i-1] = p->child[i];
	}
	p->count--;
}/*End of delByShift()*/

int copy_succkey(struct node *p, int n)
{
	struct node *ptr;
	ptr = p->child[n]; /*point to the right subtree*/

	while( ptr->child[0]!=NULL )   /*move down till leaf node arrives*/
		ptr = ptr->child[0];

	p->key[n] = ptr->key[1];
	return ptr->key[1];
}/*End of copy_succkey()*/

void borrowLeft(struct node *p, int n)
{
	int i;
	struct node *u;		/* underflow node*/
	struct node *ls;	/* left sibling of node u */

	u = p->child[n];
	ls = p->child[n-1];

	/*Shift all the keys and pointers in underflow node u one position right*/
	for(i = u->count; i>0; i--)
	{
		u->key[i+1] = u->key[i];
		u->child[i+1] = u->child[i];
	}
	u->child[1] = u->child[0];

	/* Move the separator key from parent node p to underflow node u */
	u->key[1] = p->key[n];
	u->count++;

	/* Move the rightmost key of node ls to the parent node p */
	p->key[n] = ls->key[ls->count];

	/*Rightmost child of ls becomes leftmost child of node u */
	u->child[0] = ls->child[ls->count];

	ls->count--;
}/*End of borrowLeft()*/

void borrowRight(struct node *p,int n)
{
	int i;
	struct node *u;		/* underflow node */
	struct node *rs;	/* right sibling of node u */

	u = p->child[n];
	rs = p->child[n+1];

	/* Move the separator key from the parent node p to the underflow node u */
	u->count++;
	u->key[u->count] = p->key[n+1];

	/* Leftmost child of node rs becomes the rightmost child of node u */
	u->child[u->count] = rs->child[0];

	/*Move the leftmost key from node rs to parent node p */
	p->key[n+1] = rs->key[1];
	rs->count--;

	/*Shift all the keys and pointers of node rs one position left*/
	rs->child[0] = rs->child[1];
	for(i=1; i<=rs->count; i++)
	{
		rs->key[i] = rs->key[i+1];
		rs->child[i] = rs->child[i+1];
	}
}/*End of borrowRight()*/

void combine(struct node *p, int m)
{
	int i;
	struct node *x;
	struct node *y;

	x = p->child[m];
	y = p->child[m-1];
	/* Move the key from the parent node p to node y */
	y->count++;
	y->key[y->count] = p->key[m];
	/*Shift the keys and pointers in p one position left to fill the gap */
	for(i=m; i<p->count; i++)
	{
		p->key[i] = p->key[i+1];
		p->child[i] = p->child[i+1];
	}
	p->count--;

	/*Leftmost child of x becomes rightmost child of y */
	y->child[y->count] = x->child[0];
	/*Insert all the keys and pointers of node x at the end of node y */
	for( i = 1; i<=x->count; i++)
	{
		y->count++;
		y->key[y->count] = x->key[i];
		y->child[y->count] = x->child[i];
	}
	free(x);
}/*End of combine()*/

void restore(struct node *p, int n)
{
	if( n!=0  &&  p->child[n-1]->count > MIN )
		borrowLeft(p, n);
	else if( n!=p->count && p->child[n+1]->count > MIN )
		borrowRight(p, n);
	else
	{
		if(n==0)  /*if underflow node is leftmost node*/
			combine(p, n+1);	/*combine with right sibling*/
		else
			combine(p, n);		/*combine with left sibling*/
	}
}/*End of restore()*/

void rec_del(int dkey, struct node *p)
{
	int n, flag, succkey;
	if( p == NULL )/*reached leaf node ,key does not exist*/
		printf("Value %d not found\n", dkey);
	else
	{
		flag = search_node(dkey, p, &n);
		if( flag )/*found in current node p */
		{
				if( p->child[n]==NULL )/*node p is a leaf node */
					delByShift( p, n);
				else /*node p is a non leaf node */
				{
					succkey = copy_succkey( p, n );
					rec_del(succkey, p->child[n]);
				}
		}
		else	/*not found in current node p */
				rec_del(dkey, p->child[n]);

		if( p->child[n] != NULL )/*if p is not a leaf node*/
		{
			if( p->child[n]->count < MIN ) /*check underflow in p->child[n]*/
				restore( p, n);
		}
	}
}/*End of rec_del()*/

struct node *Delete(int dkey, struct node *root)
{
	struct node *temp;
	rec_del( dkey, root);

	if( root!=NULL && root->count == 0 )/*If tree becomes shorter, root is changed*/
	{
		temp = root;
		root = root->child[0];
		free(temp);
	}
	return root;
}/*End of Delete()*/

void display(struct node *ptr, int blanks)
{
	if(ptr)
	{
		int i;
		for(i=1; i<=blanks; i++)
			printf(" ");
		for(i=1; i<=ptr->count; i++)
			printf("%d ",ptr->key[i]);
		printf("\n");
		for(i=0; i<=ptr->count; i++)
			display(ptr->child[i], blanks+10);
	}
}/*End of display()*/

void inorder(struct node *ptr)
{
	int i;
	if(ptr!=NULL )
	{
		for(i=0; i<ptr->count; i++)
		{
			inorder(ptr->child[i]);
			printf("%d\t",ptr->key[i+1] );
		}
		inorder(ptr->child[i]);
	}
}/*End of inorder()*/

int key,choice,n;
	while(1)
	{
		printf("1.Search\n2.Insert\n3.Delete\n");
		printf("4.Display\n5.Inorder traversal\n6.Return to Tree\n 7.Quit\n");

		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the key to be searched : ");
				scanf("%d",&key);
				if( (ptr=Search(key, root, &n)) == NULL )
					printf("Key not present\n");
				else
					printf("Node %p, Position %d\n",ptr,n);
				break;
			case 2:
				printf("Enter the key to be inserted : ");
				scanf("%d",&key);
				root = Insert(key, root);
				break;
			case 3:
				printf("Enter the key to be deleted : ");
				scanf("%d",&key);
				root = Delete(key, root);
				break;
			case 4:
				printf("Btree is :\n\n");
				display( root, 0 );
				printf("\n\n");
				break;
			case 5:
				inorder(root);
				printf("\n\n");
				break;
            case 6:
                Tree();
                break;
			case 7:
				exit(1);
			default:
				printf("Wrong choice\n");
				break;
		}/*End of switch*/
	}/*End of while*/
}

int ch;
do
{
    printf("\n Menu: \n");
    printf("1.Binary Search Tree \n");
    printf("2.Threaded Binary Search Tree\n");
    printf("3.AVL Tree \n");
    printf("4.Red Black Tree\n");
    printf("5.Heap Tree\n");
    printf("6.B Tree\n");
    printf("7.Return to main\n");
    printf("8.Exit\n");

    printf("Enter your choice \n");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
        BST();
        break;
    case 2:
        Threaded_BST();
        break;
    case 3:
        AVL_Tree();
        break;
    case 4:
        Red_Black_Tree();
        break;
    case 5:
        Heap();
        break;
    case 6:
        B_Tree();
        break;
    case 7:
        main();
        break;
    case 8:
        exit(1);
    default:
        printf("wrong choice \n");
    }
}
while(1);
}
