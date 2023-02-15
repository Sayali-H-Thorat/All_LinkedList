/*
7-2-2023
Linkedlist in java
SinglyLL Completed here
*/
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
class SinglyLL
{
	private Node Head;  //change is here
	private int Count;  //change is here
	
	public SinglyLL()
	{
		Head = null;
		Count = 0;
	}
	protected void finalize()
	{
		//Memory free
	}
	
	public void InsertFirst(int No)
	{
		// Node newn = new Node();
		// newn.Data=No;
		// newn.Next = null;
		Node newn = new Node(No);
		
		if(this.Head == null)
		{
			this.Head = newn;
		}
		else
		{
			newn.Next = this.Head;
			this.Head = newn;
			
		}
		this.Count++;
	}
	
	public void Display()
	{
		Node temp = this.Head;
		
		System.out.println("Elements of LinkedList are :");
		
		while(temp != null)
		{
			System.out.print("| "+temp.Data+" |->");
			temp = temp.Next;
			
		}
		System.out.println("NULL");
	}
	
	public int CountNodes()
	{
		return this.Count;
	}
	
	public void InsertLast(int No)
	{
		Node newn = new Node(No);
		
		if(this.Head == null)
		{
			this.Head = newn;
		}
		else
		{
			Node temp = Head;
			
			while(temp.Next != null)
			{
				temp = temp.Next;
			}
			temp.Next = newn;
			
		}
		this.Count++;
		
	}
	
	public void DeleteFirst()
	{
		if(this.Count == 0)  
		{
			return;
		}
		else if(this.Count == 1)
		{
			this.Head = null;
			
		}
		else
		{
			Head = Head.Next;			
		}
		this.Count--;
	}
	
	public void DeleteLast()
	{
		if(this.Count == 0)  
		{
			return;
		}
		else if(this.Count == 1)
		{
			this.Head = null;			
		}
		else
		{
			Node temp = this.Head;
			
			while(temp.Next.Next != null)
			{
				temp = temp.Next;				
			}
			temp.Next = null;
		}
		this.Count--;
	}
	
	public void InsertAtPos(int No,int iPos)
	{
		
		
		if((iPos<1) || (iPos >(Count +1)))
		{
			System.out.println("Invalid Position");
			return;
		}
		
		if(iPos == 1)
		{
			InsertFirst(No);
		}
		else if(iPos == Count +1)
		{
			InsertLast(No);
		}
		else
		{
			Node newn = new Node(No);
			Node temp = Head;
			
			for(int i = 1; i< iPos -1; i++)
			{
				temp = temp.Next;
			}
			newn.Next = temp.Next;
			temp.Next = newn;
			Count++;			
		}
	}
	public void DeleteAtPos(int iPos)
	{
		if((iPos<1) || (iPos >Count))
		{
			System.out.println("Invalid Position");
			return;
		}
		
		if(iPos == 1)
		{
			DeleteFirst();
		}
		else if(iPos == Count)
		{
			DeleteLast();
		}
		else
		{
			Node temp = Head;
			
			for(int i = 1; i< iPos -1; i++)
			{
				temp = temp.Next;
			}
			temp.Next = temp.Next.Next;
			Count--;	
			
		}
	}

}

class Singly_Linear_LL
{
	public static void main(String arg[])
	{
		SinglyLL obj = new SinglyLL();
		System.out.println("----------------Singly Linear LinkedList in java----------------");
		obj.InsertFirst(51);
		obj.InsertFirst(21);
		obj.InsertFirst(11);
		obj.Display();
		int iRet = obj.CountNodes();
		System.out.println("Number of nodes in the linkedlist after insertFirst is: "+iRet);
        System.out.println("-------------------------------------------------------------------");

		obj.InsertLast(101);
		obj.InsertLast(111);
		obj.InsertLast(121);
		obj.InsertLast(151);
		obj.Display();
		iRet = obj.CountNodes();
		System.out.println("Number of nodes in the linkedlist after insertLast is: "+iRet);
        System.out.println("-------------------------------------------------------------------");

		obj.InsertAtPos(55,4);
		obj.Display();
		iRet = obj.CountNodes();
		System.out.println("Number of nodes after inserting element at position in linkedlist are: "+iRet);
        System.out.println("-------------------------------------------------------------------");

		obj.DeleteAtPos(4);
		obj.Display();
		iRet = obj.CountNodes();
		System.out.println("Number of nodes after deleting element at position in linkedlist are: "+iRet);
        System.out.println("-------------------------------------------------------------------");
		
		obj.DeleteFirst();
		obj.Display();
		iRet = obj.CountNodes();
		System.out.println("Number of nodes in the linkedlist after deleting first element is: "+iRet);
        System.out.println("-------------------------------------------------------------------");

		obj.DeleteLast();
		obj.Display();
		iRet = obj.CountNodes();
		System.out.println("Number of nodes in the linkedlist after deleting first element is: "+iRet);
        System.out.println("-------------------------------------------------------------------");
		
	}
}