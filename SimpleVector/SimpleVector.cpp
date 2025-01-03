#include "SimpleVector.h"
#include <algorithm>


using namespace std;


template<typename T>
void SimpleVector<T>::resize(int newCapacity)
{
	if (newCapacity > currentCapacity)
	{
		T* newData = new T[newCapacity];

		for (int i = 0; i < currentCapacity; i++)
		{

			newData[i] = data[i];

		}
		delete[] data;
		data = newData;
		currentCapacity = newCapacity;
	}
}


template<typename T>
SimpleVector<T>::SimpleVector() 
	: data(new T[10])
	, currentSize(0)
	, currentCapacity(10)
{

}


template<typename T>
SimpleVector<T>::SimpleVector(int Capacity)
	: data(new T[Capacity])
	, currentSize(0)
	, currentCapacity(Capacity)
{

}


template<typename T>
SimpleVector<T>::SimpleVector(const SimpleVector& other)
	: data(nullptr)
	, currentSize(other.currentSize)
	, currentCapacity(other.currentCapacity)
{

	data = new T[currentCapacity];

	for (int i = 0; i < currentSize; i++)
	{
		data[i] = other.data[i];
	}
	
}


template<typename T>
void SimpleVector<T>::push_back(const T& value)
{

	if (currentSize >= currentCapacity)
	{

		resize(currentCapacity + 5);

	}

	data[currentSize++] = value;
}

template<typename T>
void SimpleVector<T>::pop_back()
{
	if (currentSize > 0)
	{
		currentSize--;
	}
}

template<typename T>
int SimpleVector<T>::size()
{
	return currentSize;
}

template<typename T>
int SimpleVector<T>::capacity()
{
	return currentCapacity;
}

template<typename T>
void SimpleVector<T>::sortData()
{
	std::sort(data, data + currentSize);
}

template<typename T>
T& SimpleVector<T>::operator[](int index)
{
	return data[index];
}


template<typename T>
SimpleVector<T>::~SimpleVector()
{
	delete[] data;
}