#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};

template <class T>
class DoublyCL
{
    public:
        struct node<T> * First;
        struct node<T> * Last;

        DoublyCL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no,int ipos);
        void DeleteFirst();
        void DeleteLast();   
        void DeleteAtPos(int ipos);     
        void Display();
        int Count();
};

template <class T>
DoublyCL <T> :: DoublyCL()
{
    First = NULL;
    Last = NULL;
}

template <class T>
void DoublyCL <T>:: InsertFirst(T no)
{
	struct node <T> *newn = new node<T>;
	
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

template <class T>
void DoublyCL <T>:: InsertLast(T no)
{
	struct node <T> *newn = new node <T>;
	
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

template <class T>
void DoublyCL <T>:: InsertAtPos(T no, int iPos)
{
	int iNodeCnt = Count();
	struct node <T> *newn = NULL;
	struct node <T> *temp = NULL;
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
		newn = new node <T>;
		
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

template <class T> 
void DoublyCL <T> :: DeleteFirst()
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

template <class T>
void DoublyCL <T>:: DeleteLast()
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

template <class T>
void DoublyCL <T>:: DeleteAtPos(int iPos)
{
	int iNodeCnt = Count();
	
	struct node <T> *temp = NULL;
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


template <class T>
void DoublyCL <T>:: Display()
{
	struct node <T> *temp = First;
	
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


template <class T>
int DoublyCL <T>:: Count()
{
	int iCnt = 0; 
	struct node <T> *temp = First;
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

int main()
{
	int iRet = 0;
    DoublyCL <char> cobj;
	cobj.InsertFirst('b');
    cobj.InsertFirst('a');
	cobj.InsertLast('c');
    cobj.InsertLast('d');
    cobj.InsertAtPos('e',5);
    cobj.Display();
    cobj.DeleteAtPos(5);
	cobj.Display();
    cobj.DeleteFirst();
    cobj.DeleteLast();
	cobj.Display();
	iRet = cobj.Count();
	cout<<"Number of character nodes are : "<<iRet<<"\n";
	
	DoublyCL <int> iobj;
	iobj.InsertFirst(21);
    iobj.InsertFirst(11);
	iobj.InsertLast(51);
    iobj.InsertLast(101);
    iobj.InsertAtPos(111,5);
    iobj.Display();
    iobj.DeleteAtPos(5);
	iobj.Display();
    iobj.DeleteFirst();
    iobj.DeleteLast();
	iobj.Display();
	iRet = iobj.Count();
	cout<<"Number of Integer nodes are : "<<iRet<<"\n";
	
	DoublyCL <float> fobj;
	fobj.InsertFirst(21.10f);
    fobj.InsertFirst(11.10f);
	fobj.InsertLast(21.15f);
    fobj.InsertLast(11.50f);
    fobj.InsertAtPos(11.50f,5);
    fobj.Display();
    fobj.DeleteAtPos(3);
	fobj.Display();
    fobj.DeleteFirst();
    fobj.DeleteLast();
	fobj.Display();
	iRet = fobj.Count();
	cout<<"Number of Float nodes are : "<<iRet<<"\n";

	DoublyCL <double> dobj;
	dobj.InsertFirst(21.20);
    dobj.InsertFirst(11.40);
	dobj.InsertLast(21.40);
    dobj.InsertLast(11.60);
    dobj.InsertAtPos(51.60,5);
    dobj.Display();
    dobj.DeleteAtPos(2);
	dobj.Display();
    dobj.DeleteFirst();
    dobj.DeleteLast();
	dobj.Display();
    iRet = dobj.Count();
	cout<<"Number of Double nodes are : "<<iRet<<"\n";

    return 0;
}


