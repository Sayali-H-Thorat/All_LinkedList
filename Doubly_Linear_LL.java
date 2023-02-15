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

class DoublyLL
{
    private Node First;  //change is here
	
	public DoublyLL()
	{
		First = null;
	}
	protected void finalize()
	{
		//Memory free
	}

    public void InsertFirst(int No)
    {
        Node newn = new Node(No);
        if(First == null)
        {
            First = newn;
        }
        else
        {
            newn.Next = First;
            First.Prev = newn;

            First = newn;
        }

    }

    public void InsertLast(int No)
    {
        Node newn = new Node(No);
        Node temp = First;


        if(First == null)
        {
            First = newn;
        }
        else
        {
            while(temp.Next != null)
            {
                temp = temp.Next;
            }
            temp.Next = newn;
            newn.Prev = temp;  
        }
    }

    public void InsertAtPos(int No, int iPos)
    {
        int NodeCnt =0, iCnt = 0;

	
	    NodeCnt = Count();
	
	    if((iPos < 1) || (iPos > (NodeCnt+1)))
	    {
		    System.out.println("Invalid Position");
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
		    Node newn = new Node(No);

		    Node temp = First;
		
		    for(iCnt = 1; iCnt < iPos-1; iCnt++)
		    {
			    temp = temp.Next;
		    }
		    newn.Next = temp.Next;
		    temp.Next.Prev = newn;  //X
		
		    temp.Next = newn;
		    newn.Prev=temp;
        }
    }

    public void DeleteFirst()
    {
        if(First == null)   //LL is empty
	    {
		    return;		
	    }
	    else if((First.Next) == null)  //LL contains 1 node
	    {
            First = null;
	    }
	    else  //LL contains more than 1 node
	    {
		    First = First.Next;
		    First.Prev = null;
		
	    }
    }

    public void DeleteLast()
    {
        Node temp = First;
	
	    if(First == null)   //LL is empty
	    {
		    return;
		
	    }
	    else if((First.Next) == null)  //LL contains 1 node
	    {
		    First = null;		
	    }
	    else  //LL contains more than 1 node
	    {
		    while(temp.Next.Next != null)
		    {
			    temp = temp.Next;
		    }
		    temp.Next = null;
		
	    }
    }

    public void DeleteAtPos(int iPos)
    {
        Node temp1 = null;
	    Node temp2 = null;
	    int iCnt = 0, NodeCnt = 0;
	
	    NodeCnt = Count();
	
	    if((iPos < 1)||(iPos > NodeCnt))
	    {
		    System.out.println("Invalid Position");
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
			    temp1 = temp1.Next;
		    }
		    temp2 = temp1.Next;
		
		
		    temp1.Next = temp2.Next;  //temp1->next = temp1->next->next;
		    temp2.Next.Prev = temp1;    //X
		
	    }
    }

    public void Display()
	{
		Node temp = this.First;
		
		System.out.println("Elements of LinkedList are :");
		
        while(temp != null)
        {
            System.out.print("| "+temp.Data+" |->");
            temp = temp.Next;
        }

		System.out.println("NULL");
	}

    public int Count()
    {
        Node temp = this.First;
        int iCnt = 0;

        while(temp != null)
        {
            iCnt++;
            temp = temp.Next;
        }

        return iCnt;
    }

}

class Doubly_Linear_LL
{
    public static void main(String arg[])
    {
        DoublyLL obj = new DoublyLL();
        System.out.println("----------------Doubly Linear LinkedList in java----------------");
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