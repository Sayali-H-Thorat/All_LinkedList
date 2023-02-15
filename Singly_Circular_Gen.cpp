#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class SinglyCL
{
    public:
        struct node<T> * First;
        struct node<T> * Last;

        SinglyCL();
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
SinglyCL <T> :: SinglyCL()
{
    First = NULL;
    Last = NULL;
}

template <class T>
void SinglyCL <T>:: InsertFirst(T no)
{
	struct node<T> * newn = new node<T>;  
	
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

template <class T>
void SinglyCL <T>:: InsertLast(T no)
{
	struct node<T> * newn = new node<T>;  
	
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

template <class T>
void SinglyCL <T>:: InsertAtPos(T no, int iPos)
{
	int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();
    struct node<T> * newn = new node<T>;
    struct node<T> * temp = First;

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
		struct node<T> * newn = new node<T>;
		
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

template <class T>
void SinglyCL <T>:: DeleteFirst()
{
	struct node<T> * temp = First;
	
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

template <class T>
void SinglyCL <T> :: DeleteLast()
{
	struct node<T> * temp = First;
	
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


template <class T>
void SinglyCL<T> :: DeleteAtPos(int iPos)
{
	int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();
    struct node<T> * temp1 =First;
  struct node<T> * temp2 = new node<T>;  

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




template <class T>
void SinglyCL <T> :: Display()
{
	struct node<T> * temp = First;  
	
    cout<<"Elements of Linked list are :"<<"\n";

    do
    {
        cout<<temp->data<<" ";
        temp = temp -> next;
    }while(temp != Last->next);
    cout<<"\n";
}

template <class T>
int SinglyCL <T>:: Count()
{
	struct node<T> * temp = First;
    int iCnt = 0;
    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last->next);
    return iCnt;
}


int main()
{
	int iRet = 0;
    SinglyCL <char> cobj;
	cobj.InsertFirst('b');
    cobj.InsertFirst('a');
	cobj.InsertLast('c');
    cobj.InsertLast('d');
    cobj.InsertAtPos('e',5);
    cobj.DeleteFirst();
    cobj.DeleteLast();
    cobj.DeleteAtPos(5);
	cobj.Display();
	iRet = cobj.Count();
	cout<<"Number of character nodes are : "<<iRet<<"\n";
	
	SinglyCL <int> iobj;
	iobj.InsertFirst(21);
    iobj.InsertFirst(11);
	iobj.InsertLast(51);
    iobj.InsertLast(101);
    iobj.InsertAtPos(111,5);
    iobj.DeleteFirst();
    iobj.DeleteLast();
    iobj.DeleteAtPos(5);
	iobj.Display();
	iRet = iobj.Count();
	// cout<<"Number of Integer nodes are : "<<iRet<<"\n";
	
	SinglyCL <float> fobj;
	fobj.InsertFirst(21.10f);
    fobj.InsertFirst(11.10f);
	fobj.InsertLast(21.15f);
    fobj.InsertLast(11.50f);
    fobj.InsertAtPos(11.50f,5);
    fobj.DeleteFirst();
    fobj.DeleteLast();
    fobj.DeleteAtPos(3);
	fobj.Display();
	iRet = fobj.Count();
	cout<<"Number of Float nodes are : "<<iRet<<"\n";

	SinglyCL <double> dobj;
	dobj.InsertFirst(21.20);
    dobj.InsertFirst(11.40);
	dobj.InsertLast(21.40);
    dobj.InsertLast(11.60);
    dobj.InsertAtPos(51.60,5);
    dobj.DeleteFirst();
    dobj.DeleteLast();
    dobj.DeleteAtPos(2);
	dobj.Display();
    iRet = dobj.Count();
	cout<<"Number of Double nodes are : "<<iRet<<"\n";

    return 0;
}
