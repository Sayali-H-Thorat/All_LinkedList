/*
11-12-2022
singly Circular linkedlist using cpp

*/

#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class SinglyCL
{
	public:
		PNODE First;
		PNODE Last;
		
		SinglyCL();
		
		void InsertFirst(int no);
		void InsertLast(int no);
		void InsertAtPos(int no, int iPos);
		
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int iPos);
		
		void Display();
		int Count();
};
/*
	Return_Value Class_Name :: Function_Name()
	{
	
	}
*/

SinglyCL:: SinglyCL()
{
	First = NULL;
	Last = NULL;
}

void SinglyCL :: InsertFirst(int no)
{
	PNODE newn = new NODE;
	
    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))    // Empty LL
    {
       First = Last = newn;
        (Last)->next = First;
    }
    else    // LL contains atleast one node
    {
        newn->next = First;
        First = newn;
        (Last)->next = First;
    }
}

void SinglyCL :: InsertLast(int no)
{
	PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))    // Empty LL
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else    // LL contains atleast one node
    {
        (Last) -> next = newn;
        Last = newn;
        (Last)->next = First;
    }
}

void SinglyCL :: Display()
{
	PNODE temp = First;
	
    cout<<"Elements of Linked list are :"<<"\n";

    do
    {
        cout<<"|" <<temp->data<<"|->";
        temp = temp -> next;
    }while(temp != Last->next);
    cout<<"\n";
}

int SinglyCL :: Count()
{
	PNODE temp = First;
    int iCnt = 0;
    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last->next);
    return iCnt;
}

void SinglyCL :: DeleteFirst()
{
	PNODE temp = First;
	
	if((First == NULL) && (Last == NULL))  //Empty LL
	{
		return;
	}
	else if(First == Last)   //Single node in LL
	{
		// free(*First);
		delete(First);
		First = NULL;
		Last = NULL;
		
	}
	else                   // IF LL contains more than one node.
	{
		First = (First) -> next;
		// free(temp);
		delete(temp);
		(Last) -> next = First;
	}
}
void SinglyCL :: DeleteLast()
{
	PNODE temp = First;
	
	if((First == NULL) && (Last == NULL))  //Empty LL
	{
		return;
	}
	else if(First == Last)   //Single node in LL
	{
		// free(*First);
		delete(First);
		First = NULL;
		Last = NULL;
		
	}
	else                   // IF LL contains more than one node.
	{
		while((temp->next) != (Last))
		{
			temp = temp->next;
		}
		// free(temp -> next);   //free(*Last);
		delete(temp -> next);   //free(*Last);
		
		Last = temp;
		(Last)->next = First;
		
		
	}
}
void SinglyCL :: InsertAtPos(int no, int iPos)
{
	int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();
    PNODE newn = NULL;
    PNODE temp = First;

    if((iPos < 1) || (iPos > iNodeCnt + 1))
    {
        cout<<"Invalid position"<<"\n";
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
		PNODE newn = new NODE;
		
        newn->data = no;
        newn->next = NULL;

        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}
void SinglyCL :: DeleteAtPos(int iPos)
{
	int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();
    PNODE temp1 = First;
    PNODE temp2 = NULL;

    if((iPos < 1) || (iPos > iNodeCnt))
    {
        cout<<"Invalid position"<<"\n";
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
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp1 = temp1->next;
        }   
        temp2 = temp1 ->next;

        temp1->next = temp2->next;
        // free(temp2);
        delete(temp2);
    }
	
}

int main()
{
	SinglyCL obj;
	
    int iRet = 0;
    
    obj.InsertFirst( 51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    
    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
	
	obj.Display();
    iRet = obj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";
	
	obj.InsertAtPos(105,5);

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";
	
	obj.DeleteAtPos(5);
	
	obj.Display();
    iRet = obj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";
	
	obj.DeleteFirst();
	obj.DeleteLast();
	
	obj.Display();
    iRet = obj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    return 0;
}