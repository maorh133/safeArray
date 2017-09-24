#pragma once
#include <stdlib.h>
#include <exception>

#define INDEX_OUT_OF_RANGE "index out of range"

template<class T>
class safeArray
{
public:
	safeArray(int);
	~safeArray();
	T& operator[](int) const;

	int getLength() const;
	T& operator++ ();     // prefix ++: no parameter, returns a reference
	T  operator++ (int);  // postfix ++: dummy parameter, returns a value
private:
	T* first;
	int length;
};

template<class T>
safeArray<T>::safeArray(int length) :length(length)
{
	first = new T[length];
	this->length = length;
}

template<class T>
safeArray<T>::~safeArray()
{
	delete first;
}

template<class T>
T& safeArray<T>::operator[](int i)const
{
	if (i < 0 || i >= length) throw INDEX_OUT_OF_RANGE;
	return *(first + i);
}

template<class T>
int safeArray<T>::getLength()const
{
	return length;
}

template<class T>
T& safeArray<T>::operator++()
{
	return *(first +1);
}

template<class T>
T safeArray<T>::operator++(int a)
{
	return *(first +1);
}


