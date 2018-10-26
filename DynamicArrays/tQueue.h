#pragma once
#include "tVecor.h"

template <typename T>
class tQueue
{
	tVector<T> vec;                       // contains the data for a queue

public:
	tQueue();                             // default initializes the queue
	tQueue(size_t count, const T& value); // constructs a queue with the given number of elements 
										  // each element is initialized by copying the given value

	void push(const T& value);            // adds an element to the top of the Queue
	void pop();                           // drops the top-most element of the Queue

	T& front();               // returns the front-most element
	T& back();   
	const T& front() const;
	const T& back() const;

	size_t size() const;                  // returns current number of elements
	bool empty() const;
};

/*----------------------------------------------------------------*/
/*----------------------------------------------------------------*/

template<typename T>
inline tQueue<T>::tQueue()
{
	
}

template<typename T>
inline tQueue<T>::tQueue(size_t count, const T & value)
{
	for (size_t i = 0; i < count; i++)
	{
		vec.push_back(value);
	}
}

template<typename T>
inline void tQueue<T>::push(const T & value)
{
	vec.push_back(value);
}

template<typename T>
inline void tQueue<T>::pop()
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		vec[i] = vec[i + 1];
	}
	vec.pop_back();
}

template<typename T>
inline T & tQueue<T>::front()
{
	// TODO: insert return statement here
	return vec[0];
}

template<typename T>
inline T & tQueue<T>::back()
{
	// TODO: insert return statement here
	return vec[vec.size() - 1];
}

template<typename T>
inline const T & tQueue<T>::front() const
{
	// TODO: insert return statement here
	return vec[0];
}

template<typename T>
inline const T & tQueue<T>::back() const
{
	// TODO: insert return statement here
	return vec[vec.size() - 1];
}

template<typename T>
inline size_t tQueue<T>::size() const
{
	return vec.size();
}

template<typename T>
inline bool tQueue<T>::empty() const
{
	return vec.empty();
}
