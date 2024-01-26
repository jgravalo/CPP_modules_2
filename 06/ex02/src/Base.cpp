#include<Base.hpp>

Base::~Base()
{
}

Base	*generate(void)
{
	Base*	a;
	int rg = rand();
	//std::cout << rg << " % 3 = "<< rg % 3 << std::endl;

	switch (rg % 3)
	{
		case 0:
			a = new A();
			break;
		case 1:
			a = new B();
			break;
		case 2:
			a = new C();
			break;
		default:
			a = NULL;
			break;
	}
	return (a);
}

void	identify(Base* p)
{
	if ( dynamic_cast< A *>( p ) != NULL )
		std::cout << "Indentified by pointer, is: A" << std::endl;
	else if ( dynamic_cast< B *>( p ) != NULL )
		std::cout << "Indentified by pointer, is: B" << std::endl;
	else if ( dynamic_cast< C *>( p ) != NULL )
		std::cout << "Indentified by pointer, is: C" << std::endl;
}

void	identify(Base& p)
{
	if ( dynamic_cast< A *>(&p ) != NULL )
		std::cout << "Indentified by pointer, is: A" << std::endl;
	else if ( dynamic_cast< B *>( &p ) != NULL )
		std::cout << "Indentified by pointer, is: B" << std::endl;
	else if ( dynamic_cast< C *>( &p ) != NULL )
		std::cout << "Indentified by pointer, is: C" << std::endl;
}