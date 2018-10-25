#pragma once
#include "raylib.h"
#include "iostream"

template <typename T>
class tVector
{
	const static size_t GROWTH_FACTOR = 2;

	T *arr;                             // pointer to underlying array
	size_t arrSize;                     // stores the number of elements currently used
	size_t arrCapacity;                 // stores the capacity of the underlying array

public:
	tVector();                          // initializes the vector's default values
	~tVector();                         // destroys the underlying array

	T *data();                          // returns a pointer to the underlying array

	void reserve(size_t newCapacity);   // resizes the vector to at least this many elements

	void push_back(const T &value);     // adds an element to the end of the vector
	void pop_back();                    // drops the last element of the vector

	T &at(size_t index);                // returns the element at the given element

	size_t size() const;                // returns current number of elements
	size_t capacity() const;            // returns maximum number of elements we can store

	tVector(const tVector &vec);
	tVector& operator=(const tVector & vec);
	T& operator[] (size_t index);

	bool empty();						// Returns true if the vector contains no elements.
	void resize(size_t);				// Resizes the vector to contain the given number of elements.
	void shrink_to_fit();				// Resizes the vector's capacity to match its size.
	void clear();						// Empties the vector (all elements are destroyed in this process)
};


/*-------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------*/


template<typename T>
inline tVector<T>::tVector()
{
	arr = new T[5];
	arrCapacity = 5;
	arrSize = 0;
}

template<typename T>
inline tVector<T>::~tVector()
{
	delete[] arr;
}


template<typename T>
inline T * tVector<T>::data()
{
	return arr;
}

template<typename T>
inline void tVector<T>::reserve(size_t newCapacity)
{
	if (arrCapacity > newCapacity)
	{
		return;
	}
	T *temp = new T[newCapacity];
	for (size_t i = 0; i < arrSize; i++)
	{
		temp[i] = arr[i];
	}
	delete[] arr;

	arr = temp;
	arrCapacity = newCapacity;
}

template<typename T>
inline void tVector<T>::push_back(const T & value)
{
	if (arrSize >= arrCapacity)
	{
		reserve(arrCapacity * GROWTH_FACTOR);
	}

	arr[arrSize] = value;
	++arrSize;
}

template<typename T>
inline void tVector<T>::pop_back()
{
	arrSize--;
}

template<typename T>
inline T & tVector<T>::at(size_t index)
{
	// TODO: insert return statement here
	std::cout <<"Index: " << arr[index] << std::endl;

	return arr[index];
}

template<typename T>
inline size_t tVector<T>::size() const
{
	std::cout << "Size: " << arrSize << std::endl;

	return arrSize;
}

template<typename T>
inline size_t tVector<T>::capacity() const
{
	std::cout <<"Capacity: " << arrCapacity << std::endl;

	return arrCapacity;
}


// tVector<int> bottomlessFries(someFries);

template<typename T>
inline tVector<T>::tVector(const tVector & vec)
{
	arr = new T[vec.arrCapacity];

	// copy over all of the elements from the other one to yourself
	for (size_t i = 0; i < vec.arrSize; i++)
	{
		arr[i] = vec.arr[i];
	}
	arrCapacity = vec.arrCapacity;
	arrSize = vec.arrSize;
}

template<typename T>
inline tVector<T> & tVector<T>::operator=(const tVector & vec)
{
	// TODO: insert return statement here
	arr = new T[vec.arrCapacity];

	for (size_t i = 0; i < vec.arrSize; i++)
	{
		arr[i] = vec.arr[i];
	}
	arrCapacity = vec.arrCapacity;
	arrSize = vec.arrSize;
}

template<typename T>
inline T & tVector<T>::operator[](size_t index)
{
	// TODO: insert return statement here

	/*for (index = 0; index < arrSize; index++)
	{
		std::cout << "Index: " << arr[index] << std::endl;
	}*/
	return arr[index];
}

template<typename T>
inline bool tVector<T>::empty()
{
	if (arrSize == 0)
	{
		std::cout << "Empty!" << std::endl;
		return true;
	}
	std::cout << "Not empty!" << std::endl;
	return false;
}

template<typename T>
inline void tVector<T>::resize(size_t newSize)
{
	if (newSize < arrSize)
	{
		arrSize = newSize;
	}
	else
	{
		for (size_t i = arrSize; i < newSize; i++)
		{
			push_back(T());
		}
	}
}

template<typename T>
inline void tVector<T>::shrink_to_fit()
{
	if (arrCapacity = arrSize)
	{
		return;
	}
	T *temp = new T[arrSize];
	for (size_t i = 0; i < arrSize; i++)
	{
		temp[i] = arr[i];
	}
	delete[] arr;

	arr = temp;
	arrCapacity = arrSize;
}

template<typename T>
inline void tVector<T>::clear()
{
	arrSize = 0;
}

