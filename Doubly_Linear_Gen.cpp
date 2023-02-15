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
class DoublyLL
{
    public:
        struct node<T> * First;

        DoublyLL();
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
DoublyLL <T> :: DoublyLL()
{
    First = NULL;
}

template <class T>
void DoublyLL <T>:: InsertFirst(T no)
{
   struct node<T> *newn = new node<T>;

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

template <class T>
void DoublyLL <T>:: InsertLast(T no)
{
    struct node <T> *newn = new node<T>;
    struct node <T> *temp = First;

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

template <class T>
void DoublyLL <T>:: Display()
{
    struct node <T> * temp= First;
    cout<<"Elements of Linked list are:"<<"\n";


    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL "<<"\n";
}

template <class T>
void DoublyLL <T>:: InsertAtPos(T No, int iPos)
{
	int NodeCnt =0, iCnt = 0;
		
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
		struct node <T> *newn = new node<T>;
		
		newn -> data = No;
		newn -> next = NULL;
		newn->prev = NULL;   //X
		
		struct node <T> *temp = First;
		
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

template <class T>
void DoublyLL <T>:: DeleteFirst()
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

template <class T>
void DoublyLL <T>:: DeleteLast()
{
	struct node <T> *temp = First;
	
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

template <class T>
void DoublyLL <T>:: DeleteAtPos(int iPos)
{
	struct node <T> *temp1 = NULL;
	struct node <T> *temp2 = NULL;
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



template <class T>
int DoublyLL <T> :: Count()
{
    int iCnt = 0;
    struct node <T> *temp = First;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }

    return iCnt;
}



int main()
{
	int iRet = 0;
    DoublyLL <char> cobj;
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
	
	DoublyLL <int> iobj;
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
	
	DoublyLL <float> fobj;
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

	DoublyLL <double> dobj;
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
