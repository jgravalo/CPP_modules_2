#include<Array.hpp>

template <typename T>
Array<T>::Array()
{
	//arr = new T();
	this->arr = NULL;
	this->_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->arr = new T[n];
	this->_size = n;
}

template <typename T>
Array<T>::Array(class Array<T>& Copy)
{
	this->_size = Copy.size();
	//this->arr = new Array(Copy.arr);
	this->arr = Copy.clone();
}

template <typename T>
Array<T>&	Array<T>::operator=(class Array<T>& Copy)
{
	if (this->arr)
		delete this->arr;
	this->_size = Copy.size();
	//this->arr = new Array(Copy.arr);
	this->arr = Copy.clone();
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	if (this->arr)
		delete this->arr;
	//std::cout << "aqui" << std::endl;
}

template <typename T>
T&	Array<T>::operator[](int n)
{
	return (this->arr[n]);
}

template <typename T>
int	Array<T>::size()
{
	return (this->_size);
}

template <typename T>
T*	Array<T>::clone()
{
	T	*clone = new T(this->arr);
	return (clone);
}
