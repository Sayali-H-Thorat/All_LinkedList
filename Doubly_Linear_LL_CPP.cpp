#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
    struct node *prev;      // X
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class DoublyLL
{
    public:
        PNODE First;
        

        // Behaviours
        DoublyLL();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no ,int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();
        int Count();
};

/*
Return_Value Class_Name :: Function_Name(Parameters)
{

}
*/

DoublyLL :: DoublyLL()
{
    First = NULL;
    
}

void DoublyLL :: InsertFirst(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;      // X

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        (First)->prev = newn;  // X

        First = newn;
    }
}

void DoublyLL :: InsertLast(int no)
{
    PNODE newn = new NODE;
    PNODE temp = First;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;      // X

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;      // X
    }
}

void DoublyLL :: Display()
{
PNODE temp = First;
    cout<<"Elements of Linked list are:"<<"\n";


    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL "<<"\n";
}

int DoublyLL :: Count()
{
    int iCnt = 0;
PNODE temp = First;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }

    return iCnt;
}

void DoublyLL :: DeleteFirst()
{
	if(First == NULL)   //LL is empty
	{
		return;
		
	}
	else if((First->next) == NULL)  //LL contains 1 node
	{
		free(First);
		First = NULL;		
	}
	else  //LL contains more than 1 node
	{
		First = First->next;
		free(First->prev);
		First->prev = NULL;
		
	}
}

void DoublyLL :: DeleteLast()
{
	PNODE temp = First;
	
	if(First == NULL)   //LL is empty
	{
		return;
		
	}
	else if((First->next) == NULL)  //LL contains 1 node
	{
		delete(First);

		First = NULL;		
	}
	else  //LL contains more than 1 node
	{
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		
		delete(temp->next);
		temp->next = NULL;
		
	}
}

void DoublyLL :: InsertAtPos(int No, int iPos)
{
	int NodeCnt =0, iCnt = 0;
	// PNODE temp = NULL;
	
	
	NodeCnt = Count();
	
	if((iPos < 1) || (iPos > (NodeCnt+1)))
	{
		cout<<"Invalid Position"<<"\n";
		return;
	}
	
	if(iPos == 1)
	{
		InsertFirst(No);
		
	}
	else if(iPos == NodeCnt+1)
	{
		InsertLast(No);
	}
	else
	{
		PNODE newn = new NODE;
		
		newn -> data = No;
		newn -> next = NULL;
		newn->prev = NULL;   //X
		
		PNODE temp = First;
		
		for(iCnt = 1; iCnt < iPos-1; iCnt++)
		{
			temp = temp -> next;
		}
		newn->next = temp->next;
		temp->next->prev = newn;  //X
		
		temp->next = newn;
		newn->prev=temp;  //X
			
	}
	
}

void DoublyLL :: DeleteAtPos(int iPos)
{
	PNODE temp1 = NULL;
	PNODE temp2 = NULL;
	int iCnt = 0, NodeCnt = 0;
	
	NodeCnt = Count();
	
	if((iPos < 1)||(iPos > NodeCnt))
	{
		cout<<"Invalid Position"<<"\n";
		return;
	}
	
	if(iPos == 1)
	{
		DeleteFirst();
		
	}
	else if(iPos == NodeCnt)
	{
		DeleteLast();		
	}
	else
	{
		temp1 = First;
		
		for(iCnt = 1; iCnt < iPos - 1; iCnt++)
		{
			temp1 = temp1->next;
		}
		temp2 = temp1->next;
		
		
		temp1->next = temp2->next;  //temp1->next = temp1->next->next;
		temp2->next->prev = temp1;    //X
		delete(temp2);
	}
}

int main()
{
    DoublyLL obj;
    int iRet = 0;
    
    obj.InsertFirst(51);
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