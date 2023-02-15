/*
3-1-2023
Linkedlist using generic programming
*/
#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class SinglyLL
{
    public:
        struct node<T> * First;

        SinglyLL();
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
SinglyLL <T> :: SinglyLL()
{
    First = NULL;
}

template <class T>
void SinglyLL <T>:: InsertFirst(T no)
{
    struct node<T> * newn = new node<T>;  

    newn -> data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
}

template <class T>
void SinglyLL <T>:: InsertLast(T no)
{
    struct node<T> * newn = new node<T>;  

    newn -> data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        struct node<T> * temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}


template <class T>
void SinglyLL<T>:: InsertAtPos(T no, int ipos)
{
    int NodeCnt = 0, iCnt = 0;

    NodeCnt = Count();

    if((ipos < 1) || (ipos > NodeCnt+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == NodeCnt + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct node<T> * newn = new node<T>;  

        newn->data = no;
        newn->next = NULL;

        struct node<T> * temp = First;  
        for(int iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }

}

template <class T>
void SinglyLL<T> :: DeleteFirst()
{
    if(First == NULL)   // if(iCount == 0)
    {
        return;
    }
    else if(First -> next == NULL) // else if(iCount == 1)
    {
        delete First;
        First = NULL;
        
    }
    else
    {
        struct node <T>* temp = First;
        First = First -> next;
        delete temp;
     
    }
}

template <class T>
void SinglyLL <T>:: DeleteLast()
{    
    if(First == NULL)   // if(iCount == 0)
    {
        return;
    }
    else if(First -> next == NULL) // else if(iCount == 1)
    {
        delete First;
        First = NULL;
        
    }
    else
    {
        struct node <T> * temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
}

template <class T>
void SinglyLL <T>:: DeleteAtPos(int ipos)
{
    int NodeCnt = 0, iCnt = 0;

    NodeCnt = Count();

    if((ipos < 1) || (ipos > NodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == NodeCnt)
    {
        DeleteLast();
    }
    else
    {
		struct node <T>* temp1 = First;
		struct node <T>* temp2 = First;
		
		for(int iCnt = 1; iCnt < ipos - 1; iCnt++)
		{
			temp1 = temp1->next;
		}
		temp2 = temp1->next;
		
		temp1->next = temp2->next;
		delete temp2;		

    }
}


template <class T>
void SinglyLL<T> :: Display()
{
    struct node<T> * temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
    cout<<"\n";
}

template <class T>
int SinglyLL <T>:: Count()
{
    struct node<T> * temp = First;
    int iCnt = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp -> next;
    }
    return iCnt;
}

int main()
{
	int iRet = 0;
    SinglyLL <char> cobj;
	cobj.InsertFirst('b');
    cobj.InsertFirst('a');
	cobj.InsertLast('c');
    cobj.InsertLast('d');
    cobj.InsertAtPos('e',5);
    cobj.DeleteAtPos(5);
    cobj.Display();
    cobj.DeleteFirst();
    cobj.DeleteLast();
	cobj.Display();
	iRet = cobj.Count();
	cout<<"Number of character nodes are : "<<iRet<<"\n";
	
	SinglyLL <int> iobj;
	iobj.InsertFirst(21);
    iobj.InsertFirst(11);
	iobj.InsertLast(51);
    iobj.InsertLast(101);
    iobj.InsertAtPos(111,5);
    iobj.DeleteAtPos(5);
    iobj.Display();
    iobj.DeleteFirst();
    iobj.DeleteLast();
	iobj.Display();
	iRet = iobj.Count();
	cout<<"Number of Integer nodes are : "<<iRet<<"\n";
	
	SinglyLL <float> fobj;
	fobj.InsertFirst(21.10f);
    fobj.InsertFirst(11.10f);
	fobj.InsertFirst(21.15f);
    fobj.InsertFirst(11.50f);
    fobj.InsertAtPos(11.50f,5);
    fobj.DeleteAtPos(5);
    fobj.Display();
    fobj.DeleteFirst();
    fobj.DeleteLast();
	fobj.Display();
	iRet = fobj.Count();
	cout<<"Number of Float nodes are : "<<iRet<<"\n";

	SinglyLL <double> dobj;
	dobj.InsertFirst(21.20);
    dobj.InsertFirst(11.40);
	dobj.InsertLast(21.40);
    dobj.InsertLast(11.60);
    dobj.InsertAtPos(51.60,5);
    dobj.DeleteAtPos(5);
    dobj.Display();
    dobj.DeleteFirst();
    dobj.DeleteLast();
	dobj.Display();
    iRet = dobj.Count();
	cout<<"Number of Double nodes are : "<<iRet<<"\n";

    return 0;
}