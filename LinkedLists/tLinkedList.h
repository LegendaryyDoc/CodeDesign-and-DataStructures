#pragma once
#include "raylib.h"
#include <iostream>

template<typename T>
class tForwardList
{
	struct Node
	{
		T data;                     // data for the element stored
		Node * next;                // pointer to node following this node
	};

	Node * head;                    // pointer to head of linked list

public:
	tForwardList();                 // default constructor
	~tForwardList();                // destructor

	void push_front(const T& val);  // adds element to front (i.e. head)
	void pop_front();               // removes element from front

	T& front();                     // returns the element at the head
	const T& front() const;         // returns the element at the head (const)

	void remove(const T& val);      // removes all elements equal to the given value

	bool empty() const;             // Returns true if there are no elements
	void clear();                   // Destroys every single node in the linked list
	void resize(size_t newSize);    // Resizes the linked list to contain the given number of elements
									// New elements are default-initialized
};

/*----------------------------------------------------------*/
/*----------------------------------------------------------*/

template<typename T>
inline tForwardList<T>::tForwardList()
{
	head = NULL;
}

template<typename T>
inline tForwardList<T>::~tForwardList()
{

}

template<typename T>
inline void tForwardList<T>::push_front(const T & val)
{
	Node *temp = new Node;

	temp->next = head;
	temp->data = val;

	head = temp;
}

template<typename T>
inline void tForwardList<T>::pop_front()
{
	Node *temp = new Node;

	if (head == NULL)
	{
		return;
	}

	temp = head->next;
	delete head;

	head = temp;
}

template<typename T>
inline T & tForwardList<T>::front()
{
	// TODO: insert return statement here
	return head->data;
}

template<typename T>
inline const T & tForwardList<T>::front() const
{
	// TODO: insert return statement here
	return head;
}

template<typename T>
inline void tForwardList<T>::remove(const T & val)
{
	// to do 
	Node * prev = nullptr;
	Node *current = head;

	while (current != nullptr)
	{
		if (current->next->data == val)
		{	
			prev = head; // first [* - -]

			head = head->next; // second [- * -] & one being deleted
			temp = head->next; // third [- - *]
			delete head; // delete second

			prev->next = temp; // one after first = third
			head = prev; // head is equal to first one again 
		}
	}
}

template<typename T>
inline bool tForwardList<T>::empty() const
{
	if (head == NULL)
	{
		return true;
	}
	return false;
}

template<typename T>
inline void tForwardList<T>::clear()
{
	Node *temp = new Node;

	if (head != NULL)
	{
		if (head == NULL)
		{
			return;
		}

		temp = head->next;
		delete head;

		head = temp;
	}
}

template<typename T>
inline void tForwardList<T>::resize(size_t newSize)
{
	Node *temp = new Node;

	for (size_t i = 0; i < newSize; i++)
	{
		temp->next = head;
		temp->data = 0;

		head = temp;
	}
}
