#include<stdio.h>
#include<stdlib.h>
#include "dsa.h"
void Array()
{
void one_d_array()/*funcation to implement 1-d array*/
{
	int arr[5],i;
	for(i=0; i<5; i++)
	{
		printf("Enter the value for arr[%d] : ",i);
		scanf("%d", &arr[i]);
	}
	printf("The array elements are : \n");
	for(i=0; i<5; i++)
		printf("%d\t", arr[i]);
	printf("\n");
    }
void two_d_array()/*funcation to implement 2-darray*/
{
#define ROW 3
#define COL 4
        int mat[ROW][COL], i, j;
	printf("Enter the elements of the matrix(%dx%d) row-wise :\n", ROW, COL);
	for(i=0; i<ROW; i++ )
		for(j=0; j<COL; j++ )
			scanf("%d", &mat[i][j]);

	printf("The matrix that you have entered is :\n");
	for(i=0; i<ROW; i++)
	{
		for(j=0; j<COL; j++)
			printf("%5d", mat[i][j]);
		printf("\n");
	}
	printf("\n");
    }

  int ch,k;
  do
  {
      printf("\n Menu \n");
      printf("1: 1-d array\n");
      printf("2: 2-d array\n");
      printf("3: return to main\n");
      printf("4: exit\n");

      printf("enter your choice\n ");
      scanf("%d",&ch);

      switch(ch)
      {
      case 1:
        one_d_array();
        break;
      case 2:
        two_d_array();
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

