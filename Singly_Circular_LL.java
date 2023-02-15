import java.util.*;

class Node
{
	public int Data;
	public Node Next;
	
	public Node(int No)
	{
		this.Data = No;
		this.Next = null;
	}
}

class SinglyCL
{
    private Node First;  //change is here
    private Node Last;  //change is here
	
	public SinglyCL()
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
		
		if((this.First == null) && (this.Last == null))
		{
			this.First =this.Last = newn;
			Last.Next = newn;
		}
		else
		{
			newn.Next = First;
            First = newn;
            Last.Next = First;
			
		}
    }

    public void InsertLast(int No)
    {
        Node newn = new Node(No);

        if((First == null) && (Last == null))    // Empty LL
        {
            First = Last = newn;
            Last.Next = First;
        }
        else    // LL contains atleast one node
        {
            Last.Next = newn;
            Last = newn;
            Last.Next = First;
        }

    }

    public void InsertAtPos(int No, int iPos)
    {
        int iNodeCnt = 0, iCnt = 0;
        iNodeCnt = Count();
        Node temp = First;

        if((iPos < 1) || (iPos > iNodeCnt + 1))
        {
            System.out.println("Invalid position");
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
		
            for(iCnt = 1; iCnt < iPos-1; iCnt++)
            {
                temp = temp.Next;
            }

            newn.Next = temp.Next;
            temp.Next = newn;
        }
    }

    public void DeleteFirst()
    {
        Node temp = First;
	
	    if((First == null) && (Last == null))  //Empty LL
	    {
		    return;
	    }
	    else if(First == Last)   //Single node in LL
	    {
		
		    First = null;
		    Last = null;
		
	    }
	    else                   // IF LL contains more than one node.
	    {
		    First = First.Next;
		    temp = null;
		    Last.Next = First;
	    }
    }

    public void DeleteLast()
    {
        Node temp = First;
	
	    if((First == null) && (Last == null))  //Empty LL
	    {
		    return;
	    }
	    else if(First == Last)   //Single node in LL
	    {
		   
		    First = null;
		    Last = null;		
	    }
	    else                   // IF LL contains more than one node.
	    {
		    while((temp.Next) != (Last))
		    {
			    temp = temp.Next;
		    }
            temp.Next=null;   //free(*Last);
		
		    Last = temp;
		    Last.Next = First;
        }
    }

    public void DeleteAtPos(int iPos)
    {
        int iNodeCnt = 0, iCnt = 0;
        iNodeCnt = Count();

        if((iPos < 1) || (iPos > iNodeCnt + 1))
        {
            System.out.println("Invalid position");
            return;
        }

        if(iPos == 1)
        {
            DeleteFirst();
        }
        else if(iPos == iNodeCnt+1)
        {
            DeleteLast();
        }
        else
        {
            Node temp = First;
			
			for(int i = 1; i< iPos -1; i++)
			{
				temp = temp.Next;
			}
			temp.Next = temp.Next.Next;

        }

    }

    public void Display()
	{
		Node temp = this.First;
		
		System.out.println("Elements of LinkedList are :");
		
        do
        {
            System.out.print("| "+temp.Data+" |->");
            temp = temp.Next;
        }while(temp != Last.Next);

		System.out.println("NULL");
	}

    public int Count()
    {
        Node temp = this.First;
        int iCnt = 0;
        do
        {
            iCnt++;
            temp = temp.Next;
        }while(temp != Last.Next);

        return iCnt;
    }


}

class Singly_Circular_LL
{
    public static void main(String arg[])
    {
        SinglyCL obj = new SinglyCL();
        System.out.println("----------------Singly Circular LinkedList in java----------------");
		obj.InsertFirst(51);
		obj.InsertFirst(21);
		obj.InsertFirst(11);
        obj.Display();
        int iRet = obj.Count();
        System.out.println("Number of nodes in the linkedlist after insertFirst is: "+iRet);
        System.out.println("-------------------------------------------------------------------");

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);
		obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes in the linkedlist after insertLast is: "+iRet);
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
