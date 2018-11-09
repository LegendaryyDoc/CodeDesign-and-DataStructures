#pragma once
#include <vector>
#include "SimpleSprite.h"

template<typename T>
class tObjectPool
{
public:
	Vector2<SimpleSprite*> vec;

	tObjectPool();                       // default initializes the object pool
	tObjectPool(size_t initialCapacity); // initializes the pool to have a set number of objects
	~tObjectPool();                      // destroys all objects

	T* free;                            // pointers to objects that can be reused
	T* used;                            // pointers to objects that are currently in use
	size_t freeCount;                   // number of objects that are free to use
	size_t usedCount;                   // number of objects that are in use

	T* retrieve();                      // returns a pointer to an object that will be used (returns null if none available)
	void recycle(T* obj);               // accepts a pointer that can be used in the future

	size_t capacity();                  // returns the total number of objects that this pool can provide
};

template<typename T>
inline tObjectPool<T>::tObjectPool()
{
	vec.capacity() = 10;
}

template<typename T>
inline tObjectPool<T>::tObjectPool(size_t initialCapacity)
{
	vec.capacity() = initialCapacity;
}

template<typename T>
inline tObjectPool<T>::~tObjectPool()
{

}

template<typename T>
inline T * tObjectPool<T>::retrieve()
{
	return &free;
}

template<typename T>
inline void tObjectPool<T>::recycle(T * obj)
{
}

template<typename T>
inline size_t tObjectPool<T>::capacity()
{
	return size_t();
}
