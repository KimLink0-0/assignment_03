#pragma once

template <typename T>
class SimpleVector 
{

private :

	T* data; 
	
	int currentSize; // ������ �Է·�
	int currentCapacity; // �뷮

	void resize(int newCapacity);

public :

	SimpleVector();

	SimpleVector(int Capacity);

	SimpleVector(const SimpleVector& other);

	~SimpleVector();


	
	void push_back(const T& value);

	void pop_back();

	int size();

	int capacity();

	void sortData();

	T& operator[](int index);


};

