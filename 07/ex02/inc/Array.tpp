#include<Array.hpp>

template <typename T>
Array<T>::Array()
{
	this->arr = new T[0];
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
	this->arr = Copy.clone();
}

template <typename T>
Array<T>&	Array<T>::operator=(class Array<T>& Copy)
{
	if (this->arr)
		delete this->arr;
	this->_size = Copy.size();
	this->arr = Copy.clone();
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	if (this->arr)
		delete this->arr;
}

template <typename T>
T&	Array<T>::operator[](int n)
{
	if (n < 0 || (unsigned int)n > this->_size)
		throw std::out_of_range("invalid range");
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
	T*	clone = new T(this->_size);
	for (size_t i = 0; i < this->_size; i++)
		clone[i] = arr[i];
	return (clone);
}
