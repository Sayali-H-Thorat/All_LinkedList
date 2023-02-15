/*
15-12-2022

Doubly Circular using CPP
*/

#include<iostream>
using namespace std;

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

class DoublyCL
{
	public:
		PNODE First;
		PNODE Last;
		
		DoublyCL();
		
		void InsertFirst(int no);
		void InsertLast(int no);
		void InsertAtPos(int no,int iPos);
		
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int iPos);
		
		void Display();
		int Count();

	
};

/*
Return_value Class_Name :: Function_Name
{
	//Code
}*/
DoublyCL :: DoublyCL()  //Default Constructor
{
	First = NULL;
	Last = NULL;
}
void DoublyCL :: InsertFirst(int no)
{
	PNODE newn = new NODE;
	
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;
	
	if((First == NULL) && (Last == NULL))   //if LL is empty
	{
		First=newn;
		Last=newn;
	}
	else  //LL contains 1 or more than one nodes
	{
		newn->next = First;
		(First)->prev = newn;
		First = newn;	
		
	}
	
	(First)->prev = Last;
	(Last)->next = First;
}
void DoublyCL :: InsertLast(int no)
{
	PNODE newn = new NODE;
	
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;
	
	if((First == NULL) && (Last == NULL))   //if LL is empty
	{
		First=newn;
		Last=newn;
	}
	else  //LL contains 1 or more than one nodes
	{
		(Last) ->next = newn;
		newn->prev = Last;
		Last = newn;
		
	}
	
	(First)->prev = Last;
	(Last)->next = First;	
}

void DoublyCL :: Display()
{
	PNODE temp = First;
	
	if(First == NULL && Last == NULL)  //if LL is empty
	{
		cout<<"Linked List is empty"<<"\n";
		return;
	}
	
	cout<<"Elements of linkedlist are:"<<"\n";
	do
	{
		cout<<"|"<<temp->data<<"|<=>";
		temp = temp->next;
	}while(temp != Last->next);
	cout<<"\n";
	
}

int DoublyCL :: Count()
{
	int iCnt = 0; 
	PNODE temp = First;
	if(First == NULL && Last == NULL)  //if LL is empty
	{
		
		return iCnt;
	}
	do
	{
		iCnt++;
		temp = temp->next;
	}while(temp != Last->next);
	
	return iCnt;
	
}

void DoublyCL :: DeleteFirst()
{
	if(First == NULL && Last == NULL) // LL empty
	{
		return;
	}
	else if(First == Last)  // Single node
	{
		free(First);
		First = NULL;
		Last = NULL;
		
	}
	else  //More than one node
	{
		First = (First)->next;
		delete((Last)->next);  //free((*First)->prev);
		
		(First)->prev = Last;  //maintain Circular nature
		(Last)->next = First;  //maintain Circular nature
	}
	
}
void DoublyCL :: DeleteLast()
{
	if(First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single node
    {
        free(First);
        First = NULL;
        Last= NULL;
    }
    else    // More than one node
    {
        Last = (Last) -> prev;
        delete((First)->prev);       // free((*Last)->next);

        (First)->prev = Last;
        (Last)->next = First;
    }
}

void DoublyCL :: InsertAtPos(int no, int iPos)
{
	int iNodeCnt = Count();
	PNODE newn = NULL;
	PNODE temp = NULL;
	int iCnt = 0;
	
	if((iPos < 1) || (iPos > iNodeCnt+1))
	{
		cout<<"Invalid Position"<<"\n";
		return;
	}
	if(iPos == 1)
	{
		InsertFirst(no);
	}
	else if(iPos == iNodeCnt+1)
	{
		InsertLast(no);
	}
	else
	{
		newn = new NODE;
		
		newn->data= no;
		newn->next = NULL;
		newn->prev = NULL;
		temp = First;
		
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
void DoublyCL :: DeleteAtPos(int iPos)
{
	int iNodeCnt = Count();
	
	PNODE temp = NULL;
	int iCnt = 0;
	
	if((iPos < 1) || (iPos > iNodeCnt))
	{
		cout<<"Invalid Position"<<"\n";
		return;
	}
	if(iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == iNodeCnt)
	{
		DeleteLast();
	}
	else
	{
		temp = First;
		
		for(iCnt = 1; iCnt <iPos-1; iCnt++)
		{
			temp = temp->next;
		}
		
		temp->next = temp->next->next;
		delete(temp->next->prev);
		temp->next->prev = temp;
		
	}
	
}

int main()
{
	int iRet = 0;
	PNODE Head = NULL ;
	PNODE Tail = NULL ;
	
	DoublyCL obj;
	obj.InsertFirst(51);
	obj.InsertFirst(21);
	obj.InsertFirst(11);
	
	
	obj.InsertLast(101);
	obj.InsertLast(111);
	obj.InsertLast(121);
	
	obj.Display();
	iRet = obj.Count();
	cout<<"Number of node are : "<< iRet<<"\n";
	
	obj.InsertAtPos(105,5);
	obj.Display();
	iRet = obj.Count();
	cout<<"Number of node are : "<< iRet<<"\n";
	
	obj.DeleteAtPos(5);
	obj.Display();
	iRet = obj.Count();
	cout<<"Number of node are : "<< iRet<<"\n";
	
	
	
	obj.DeleteFirst();
	obj.DeleteLast();
	obj.Display();
	iRet = obj.Count();
	cout<<"Number of node are : "<< iRet<<"\n";
	
	return 0;
}