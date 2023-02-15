/*
15-12-2022

Doubly Circular C
Functions declaration
InsertAtPos()
DeleteAtPos()
*/

#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)  
struct node
{
	int data;
	struct node * next;
	struct node * prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE First, PPNODE Last, int no)
{
	PNODE newn = (PNODE)malloc(sizeof(NODE));
	
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;
	
	if((*First == NULL) && (*Last == NULL))   //if LL is empty
	{
		*First=newn;
		*Last=newn;
	}
	else  //LL contains 1 or more than one nodes
	{
		newn->next = *First;
		(*First)->prev = newn;
		*First = newn;	
		
	}
	
	(*First)->prev = *Last;
	(*Last)->next = *First;
	
	

	
}
void InsertLast(PPNODE First, PPNODE Last, int no)
{
	PNODE newn = (PNODE)malloc(sizeof(NODE));
	
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;
	
	if((*First == NULL) && (*Last == NULL))   //if LL is empty
	{
		*First=newn;
		*Last=newn;
	}
	else  //LL contains 1 or more than one nodes
	{
		(*Last) ->next = newn;
		newn->prev = *Last;
		*Last = newn;
		
	}
	
	(*First)->prev = *Last;
	(*Last)->next = *First;	
}

void Display(PNODE First , PNODE Last)
{
	if(First == NULL && Last == NULL)  //if LL is empty
	{
		printf("Linked List is empty\n");
		return;
	}
	
	printf("Elements of linkedlist are:\n");
	do
	{
		printf("| %d |<=>", First->data);
		First = First->next;
	}while(First != Last->next);
	printf("\n");
	
	
	
}

int Count(PNODE First , PNODE Last)
{
	int iCnt = 0; 
	if(First == NULL && Last == NULL)  //if LL is empty
	{
		
		return iCnt;
	}
	do
	{
		iCnt++;
		First = First->next;
	}while(First != Last->next);
	
	return iCnt;
	
}

void DeleteFirst(PPNODE First, PPNODE Last)
{
	if(*First == NULL && *Last == NULL) // LL empty
	{
		return;
	}
	else if(*First == *Last)  // Single node
	{
		free(*First);
		*First = NULL;
		*Last = NULL;
		
	}
	else  //More than one node
	{
		*First = (*First)->next;
		free((*Last)->next);  //free((*First)->prev);
		
		(*First)->prev = *Last;  //maintain Circular nature
		(*Last)->next = *First;  //maintain Circular nature
	}
	
}
void DeleteLast(PPNODE First, PPNODE Last)
{
	if(*First == NULL && *Last == NULL) // Empty LL
    {
        return;
    }
    else if(*First == *Last)    // Single node
    {
        free(*First);
        *First = NULL;
        *Last= NULL;
    }
    else    // More than one node
    {
        *Last = (*Last) -> prev;
        free((*First)->prev);       // free((*Last)->next);

        (*First)->prev = *Last;
        (*Last)->next = *First;
    }
}

void InsertAtPos(PPNODE First,PPNODE Last, int no, int iPos)
{
	int iNodeCnt = Count(*First,*Last);
	PNODE newn = NULL;
	PNODE temp = NULL;
	int iCnt = 0;
	
	if((iPos < 1) || (iPos > iNodeCnt+1))
	{
		printf("Invalid Position\n");
		return;
	}
	if(iPos == 1)
	{
		InsertFirst(First,Last,no);
	}
	else if(iPos == iNodeCnt+1)
	{
		InsertLast(First,Last,no);
	}
	else
	{
		newn = (PNODE)malloc(sizeof(NODE));
		
		newn->data= no;
		newn->next = NULL;
		newn->prev = NULL;
		temp = *First;
		
		for(iCnt = 1; iCnt <iPos-1; iCnt++)
		{
			temp = temp->next;
		}
		
		newn->next = temp->next;
		temp->next->prev = newn;
		
		temp->next = newn;
		newn->prev = temp;
	}
	
}
void DeleteAtPos(PPNODE First,PPNODE Last,int iPos)
{
	int iNodeCnt = Count(*First,*Last);
	
	PNODE temp = NULL;
	int iCnt = 0;
	
	if((iPos < 1) || (iPos > iNodeCnt))
	{
		printf("Invalid Position\n");
		return;
	}
	if(iPos == 1)
	{
		DeleteFirst(First,Last);
	}
	else if(iPos == iNodeCnt)
	{
		DeleteLast(First,Last);
	}
	else
	{
		temp = *First;
		
		for(iCnt = 1; iCnt <iPos-1; iCnt++)
		{
			temp = temp->next;
		}
		
		temp->next = temp->next->next;
		free(temp->next->prev);
		temp->next->prev = temp;
		
	}
	
}

int main()
{
	int iRet = 0;
	PNODE Head = NULL ;
	PNODE Tail = NULL ;
	
	
	InsertFirst(&Head,&Tail,51);
	InsertFirst(&Head,&Tail,21);
	InsertFirst(&Head,&Tail,11);
	
	
	InsertLast(&Head,&Tail,101);
	InsertLast(&Head,&Tail,111);
	InsertLast(&Head,&Tail,121);
	
	Display(Head,Tail);
	iRet = Count(Head, Tail);
	printf("Number of node are : %d\n", iRet);
	
	InsertAtPos(&Head,&Tail,105,5);
	Display(Head,Tail);
	iRet = Count(Head, Tail);
	printf("Number of node are : %d\n", iRet);
	
	DeleteAtPos(&Head,&Tail,5);
	Display(Head,Tail);
	iRet = Count(Head, Tail);
	printf("Number of node are : %d\n", iRet);
	
	
	
	DeleteFirst(&Head, &Tail);
	DeleteLast(&Head, &Tail);
	Display(Head,Tail);
	iRet = Count(Head, Tail);
	printf("Number of node are : %d\n", iRet);
	
	return 0;
}