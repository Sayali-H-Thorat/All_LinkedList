import java.util.*;

class Node
{
	public int Data;
	public Node Next;
	public Node Prev;
	
	public Node(int No)
	{
		this.Data = No;
		this.Next = null;
        this.Prev = null;
	}
}

class DoublyCL
{
    private Node First;  //change is here
    private Node Last;  //change is here
	
	public DoublyCL()
	{
		First = null;
		Last = null;
	}
	protected void finalize()
	{
		//Memory free
	}

    public void InsertFirst(int No)
    {
        Node newn = new Node(No);
	
	    if((First == null) && (Last == null))   //if LL is empty
	    {
		    First=newn;
		    Last=newn;
	    }
	    else  //LL contains 1 or more than one nodes
	    {
		    newn.Next = First;
		    First.Prev = newn;
		    First = newn;		
	    }
	
	    First.Prev = Last;
	    Last.Next = First;
    }

    public void InsertLast(int No)
    {
        Node newn = new Node(No);
	
	    if((First == null) && (Last == null))   //if LL is empty
	    {
		    First=newn;
		    Last=newn;
	    }
	    else  //LL contains 1 or more than one nodes
	    {
		    Last.Next = newn;
		    newn.Prev = Last;
		    Last = newn;		
	    }
	
	    First.Prev = Last;
	    Last.Next = First;
    }

    public void InsertAtPos(int No,int iPos)
    {
        int iNodeCnt = Count();
	    int iCnt = 0;
	
	    if((iPos < 1) || (iPos > iNodeCnt+1))
	    {
		    System.out.println("Invalid Position");
		    return;
	    }
	    if(iPos == 1)
	    {
		    InsertFirst(No);
	    }
	    else if(iPos == iNodeCnt+1)
	    {
		    InsertLast(No);
	    }
	    else
	    {
		    Node newn = new Node(No);
		    Node temp = First;
		
		    for(iCnt = 1; iCnt <iPos-1; iCnt++)
		    {
			    temp = temp.Next;
		    }
		
		    newn.Next = temp.Next;
		    temp.Next.Prev = newn;
		
		    temp.Next = newn;
		    newn.Prev = temp;
	    }
    }

    public void DeleteFirst()
    {
        if(First == null && Last == null) // LL empty
	    {
		    return;
	    }
	    else if(First == Last)  // Single node
	    {
		    First = null;
		    Last = null;		
	    }
	    else  //More than one node
	    {
		    First = First.Next;
		    Last.Next=null;  //free((*First)->prev);
		
		    First.Prev = Last;  //maintain Circular nature
		    Last.Next = First;  //maintain Circular nature
	    }
    }

    public void DeleteLast()
    {
        if(First == null && Last == null) // Empty LL
        {
            return;
        }
        else if(First == Last)    // Single node
        {
            First = null;
            Last= null;
        }
        else    // More than one node
        {
            Last = Last.Prev;
            First.Prev=null;       // free((*Last)->next);

            First.Prev = Last;
            Last.Next = First;
        }

    }

    public void DeleteAtPos(int iPos)
    {
        int iNodeCnt = Count();
	    int iCnt = 0;
	
	    if((iPos < 1) || (iPos > iNodeCnt))
	    {
		    System.out.println("Invalid Position");
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
		    Node temp = First;
		
		    for(iCnt = 1; iCnt <iPos-1; iCnt++)
		    {
			    temp = temp.Next;
		    }
		
		    temp.Next = temp.Next.Next;
		    temp.Next.Prev=null;
		    temp.Next.Prev = temp;
		
	    }
    }

    public void Display()
    {
        Node temp = First;
	
	    if(First == null && Last == null)  //if LL is empty
	    {
		    System.out.println("Linked List is empty");
		    return;
	    }
	
	    System.out.println("Elements of linkedlist are:");
	    do
	    {
		    System.out.print("| "+temp.Data+" |->");
		    temp = temp.Next;
	    }while(temp != Last.Next);

	    System.out.println("NULL");
    }

    public int Count()
    {
        int iCnt = 0; 
	    Node temp = First;
	    if((First == null) && (Last == null))  //if LL is empty
	    {		
		    return iCnt;
	    }
	    do
	    {
		    iCnt++;
		    temp = temp.Next;
	    }while(temp != Last.Next);
	
	    return iCnt;
	
    }
}

class Doubly_Circular_LL
{
    public static void main(String arg[])
    {
        DoublyCL obj = new DoublyCL();
        System.out.println("----------------Doubly Circular LinkedList in java----------------");
		obj.InsertFirst(51);
		obj.InsertFirst(21);
		obj.InsertFirst(11);
        obj.Display();
        int iRet = obj.Count();
        System.out.println("Number of nodes in the linkedlist after InsertFirst is: "+iRet);
        System.out.println("-------------------------------------------------------------------");

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);
		obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes in the linkedlist after InsertLast is: "+iRet);
        System.out.println("-------------------------------------------------------------------");

        obj.InsertAtPos(105,5);
        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes after inserting element at position in linkedlist are: "+iRet);
        System.out.println("-------------------------------------------------------------------");

        obj.DeleteAtPos(5);
        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes after deleting element at position in linkedlist are: "+iRet);
        System.out.println("-------------------------------------------------------------------");


        obj.DeleteFirst();
        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes in the linkedlist after deleting first element is: "+iRet);
        System.out.println("-------------------------------------------------------------------");

        obj.DeleteLast();
        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes in the linkedlist after deleting first element is: "+iRet);
        System.out.println("-------------------------------------------------------------------");






    }
}