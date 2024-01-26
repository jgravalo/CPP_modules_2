#include<Base.hpp>

Base::~Base()
{
}

Base	*generate(void)
{
	Base*	a = new A();
	return (a);
}

void	identify(Base* p)
{
	(void)p;
}

void	identify(Base& p)
{
	(void)p;
}