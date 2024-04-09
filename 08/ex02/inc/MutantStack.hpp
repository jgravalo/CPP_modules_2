#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include<iostream>
#include<stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(class MutantStack<T>& Copy);
		MutantStack&	operator=(class MutantStack<T>& Copy);
		~MutantStack();
		
		typedef typename std::stack< T >::container_type::iterator	iterator;

		iterator	begin();
		iterator	end();
};

#include<MutantStack.tpp>

#endif
