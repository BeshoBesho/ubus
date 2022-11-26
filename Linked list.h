#pragma once
#ifndef _LINKEDLIST
#define _LINKEDLIST
#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
private:
	Node<T>* Head;	//Pointer to the head of the list
	Node<T>* Tail;
	//You can add tail pointer too (depending on your problem)
	int length=0;
public:


	LinkedList()
	{
		Head = nullptr;
		Tail = nullptr;
	}

	//List is being desturcted ==> delete all items in the list
	~LinkedList()
	{
		DeleteAll();
	}

	/*
	* Function: PrintList.
	* prints the values of all nodes in a linked list.
	*/
	void PrintList()	const
	{
		cout << "\nprinting list contents:\n\n";
		Node<T>* p = Head;

		while (p)
		{
			cout << "[ " << p->getItem() << " ]";
			cout << "--->";
			p = p->getNext();
		}
		cout << "*\n";
	}

	/*
	* Function: InsertBeg.
	* Creates a new node and adds it to the beginning of a linked list.
	*
	* Parameters:
	*	- data : The value to be stored in the new node.
	*/
	void InsertBeg(const T& data)
	{
		Node<T>* R = new Node<T>(data);
		if (length == 0)
		{
			R->setNext(Head);
			Head = Tail = R;
			length++;
		}
		else
		{
			R->setNext(Head);
			Head = R;
			length++;
		}
	}

	/*
	* Function: DeleteAll.
	* Deletes all nodes of the list.
	*/
	void DeleteAll()
	{
		Node<T>* P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
	}

	////////////////     Requirements   ///////////////////
	//
	// Implement the following member functions


	void InsertEnd( T data)
	{
		Node<T>* R = new Node<T>(data);
		if (length == 0)
		{
			R->setNext(Head);
			Head = Tail = R;
			length++;
		}
		else
		{
			R->setNext(nullptr);
			Tail->setNext(R);
			Tail = R;
			length++;
		}
	}
	

	bool Find(T key)
	{
		Node<T>* temp;
		int c = 0;
		temp = Head;
		for (int i = 0; i < length; i++)
		{
			if (key == temp->getItem())
			{
				c++;
				break;
			}
			else
			{
				temp= temp->getNext();
			}
		}
		return (c != 0);
	}
	//searches for a given value in the list, returns true if found; false otherwise.

	int CountOccurance(T value)
	{
		Node<T>* temp;
		int c = 0;
		temp=Head;
		for (int i = 0; i < length; i++)
		{
			if (value == temp->getItem())
				c++;
			temp = temp->getNext();
		}
		return c;
	}
	

	void DeleteFirst()
	{
		Node<T>* temp = Head;
		Node<T>* temp2 = Head->getNext();

		delete temp;
		Head = temp2;
		length--;
	}


	void DeleteLast()
	{
		Node<T>* temp=Head;
		Node<T>* temp2 = Head->getNext();
		while (temp2!=Tail)
		{
			temp = temp->getNext();
			temp2 = temp2->getNext();
		}
		delete temp2;
		temp->setNext(nullptr);
		Tail = temp;
		length--;

	}
	//Deletes the last node in the list

	bool DeleteNode(T value)
	{
		Node<T>* temp = Head;
		Node<T>* temp2 = Head->getNext();
		if (length == 0)
		{
			cout << "cannot delete";
		}
		else if (length == 1)
		{
			delete temp;
			length--;
		}
		else if (value == Head->getItem())
		{
			DeleteFirst();
		}
		else if (value == Tail->getItem())
		{
			DeleteLast();
		}
		else
		{
			while (temp2 != nullptr)
			{
				if (value==temp2->getItem())
				{
					temp->setNext(temp2->getNext());
					delete temp2;
					length--;
					break;
				}

				temp = temp->getNext();
				temp2 = temp2->getNext();
			}


		}
		return(temp2 != nullptr);

	}

	bool DeleteNodes(T value)
	{
		Node<T>* fromfirst = Head;
		Node<T>* temp = Head;
		Node<T>* temp2 = Head->getNext();
		int c = length;
		int d = length;
		if (length == 0)
		{
			cout << "cannot delete";
		}
		if (length == 1)
		{
			delete temp;
			length--;
		}
		else
		{
			while (fromfirst != nullptr)
			{
				if (value == Head->getItem())
					DeleteFirst();
				fromfirst = fromfirst->getNext();
			}
			for (int i = 0; i < length-1; i++)
			{
				Node<T>* cur = Head;
				for (int i = 0; i < c-1; i++)
					cur = cur->getNext();
				if (value == cur->getItem())
				{
					DeleteLast();
					c--;
				}
			}
			while (temp2 != nullptr)
			{
				Node<T>* replace;
				if (value == temp2->getItem())
				{
					temp->setNext(temp2->getNext());
					replace = temp2;
					temp2 = temp2->getNext();
					delete replace;
					length--;
				}

				else
				{
					temp2 = temp2->getNext();
					temp = temp->getNext();
				}
			}
		}
		return (length!=d);
	}



	void Reverse()
	{
		Node<T>* prev = nullptr;
		Node<T>* cur = Head;
		Node<T>* tonext = Head->getNext();
		while (cur != nullptr)
		{
			tonext = cur->getNext();
			cur->setNext(prev);
			prev = cur;
			cur = tonext;	
		}
		Head = prev;
	}

	//void Merge(LinkedList<T> L)
	//{
	//	Tail->setNext(L.gethead());
	//	Tail = L.gettail();
	//	Tail->setNext(nullptr);
	//}

	T* gethead() const
	{
		return Head;
	}
	T* gettail() const
	{
		return Tail;
	} 

};

#endif	