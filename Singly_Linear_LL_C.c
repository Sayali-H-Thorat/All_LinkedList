/*29-11-2022
InsertFirst(),Display(), Count(),InsertLast()along with this DeleteFirst() and DeleteLast() function created and completed here.
InsertAtPos() and DeleteAtPos() function is added here
*/
#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE First, int No)  //No complexity
{
	PNODE newn = (PNODE)malloc(sizeof(NODE));    //Step 1: Allocate memory
	
	newn->data = No;   // Initialisation
	newn->next = NULL; // Initialisation
	
	if(*First == NULL)   //If linkedlist is empty
	{
		*First = newn;
	}
	else   //If linked list contains atleast one node
	{
		newn->next = *First;
		*First = newn;		
	}
}

void InsertLast(PPNODE First, int No)   //N complexity
{
	PNODE newn = (PNODE)malloc(sizeof(NODE));    //Step 1: Allocate memory
	PNODE temp = *First;
	
	newn->data = No;   // Initialisation
	newn->next = NULL; // Initialisation
	
	if(*First == NULL)   //If linkedlist is empty
	{
		*First = newn;
	}
	else   //If linked list contains atleast one node
	{
		while(temp->next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = newn;
	}	
}

void Display(PNODE First)   //N complexity
{
	printf("Elements from linkedlist are : \n");
	
	while(First != NULL)
	{
		printf("| %d |->", First->data);
		First = First->next;
	}
	printf("NULL \n");	
}

int Count(PNODE First)   //N complexity
{
	int iCnt = 0;
	
	while(First != NULL)
	{
		iCnt++;
		First = First->next;
	}
	return iCnt;	
}

void DeleteFirst(PPNODE First)
{
	PNODE temp = *First;
	if(*First == NULL)  //Empty Linkedlist
	{
		return;		
	}
	else if((*First) -> next == NULL) //1 node in Linkedlist
	{
		free(*First);
		*First = NULL;
		
	}
	else //More than 1 node in Linkedlist
	{
		(*First) = (*First) -> next;
		free(temp);
		
	}
}
void DeleteLast(PPNODE First)
{
	PNODE temp = *First;
	if(*First == NULL)  //Empty Linkedlist
	{
		return;		
	}
	else if((*First) -> next == NULL) //1 node in Linkedlist
	{
		free(*First);
		*First = NULL;
		
	}
	else //More than 1 node in Linkedlist
	{
		while(temp-> next -> next != NULL)
		{
			temp = temp -> next;
		}
		free(temp->next);
		temp -> next = NULL;
		
	}
}
void InsertAtPos(PPNODE First,int No, int iPos)
{
	int NodeCnt =0, iCnt = 0;
	PNODE newn = NULL;
	PNODE temp = NULL;
	
	
	NodeCnt = Count(*First);
	
	if((iPos < 1) || (iPos > (NodeCnt+1)))
	{
		printf("Invalid Position\n");
		return;
	}
	
	if(iPos == 1)
	{
		InsertFirst(First,No);
		
	}
	else if(iPos == NodeCnt+1)
	{
		InsertLast(First, No);
	}
	else
	{
		newn = (PNODE)malloc(sizeof(NODE));
		
		newn -> data = No;
		newn -> next = NULL;
		
		temp = *First;
		
		for(iCnt = 1; iCnt < iPos-1; iCnt++)
		{
			temp = temp -> next;
		}
		newn->next = temp->next;
		temp->next = newn;
			
	}
	
}

void DeleteAtPos(PPNODE First, int iPos)
{
	PNODE temp1 = NULL;
	PNODE temp2 = NULL;
	int iCnt = 0, NodeCnt = 0;
	
	NodeCnt = Count(*First);
	
	if((iPos < 1)||(iPos > NodeCnt))
	{
		printf("Invalid Position\n");
		return;
	}
	
	if(iPos == 1)
	{
		DeleteFirst(First);
		
	}
	else if(iPos == NodeCnt)
	{
		DeleteLast(First);		
	}
	else
	{
		temp1 = *First;
		
		for(iCnt = 1; iCnt < iPos - 1; iCnt++)
		{
			temp1 = temp1->next;
		}
		temp2 = temp1->next;
		
		temp1->next = temp2->next;  //temp1->next = temp1->next->next;
		free(temp2);
	}
}

int main()
{
	//struct node * Head = NULL;
	PNODE Head = NULL;
	int iRet = 0;
	
	InsertFirst(&Head, 51);   //InserFirst(60,51);
	InsertFirst(&Head, 21);   //InserFirst(60,51);
	InsertFirst(&Head, 11);   //InserFirst(60,51);
	
	Display(Head);
	
	iRet = Count(Head);
	
	printf("Number of nodes are: %d\n", iRet);
	
	InsertLast(&Head,101);
	InsertLast(&Head,111);
	InsertLast(&Head,121);
	
	Display(Head);
	
	iRet = Count(Head);
	printf("Number of nodes are: %d\n", iRet);	
	
	InsertAtPos(&Head, 105, 5);
	Display(Head);
	
	DeleteAtPos(&Head,5);
	Display(Head);
		
	
	DeleteFirst(&Head);
	Display(Head);
	
	iRet = Count(Head);
	printf("Number of nodes are: %d\n", iRet);
	
	DeleteLast(&Head);
	Display(Head);
	
	iRet = Count(Head);
	printf("Number of nodes are: %d\n", iRet);
	
	
	return 0;
}