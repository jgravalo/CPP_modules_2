#include<Base.hpp>

Base::~Base()
{
}

Base	*generate(void)
{
	Base*	a;
	srand(time(NULL));
	int rg = rand();

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
	try
	{
		A& a = dynamic_cast< A& >( p );
		(void)a;
		std::cout << "Indentified by reference, is: A" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		B& a = dynamic_cast< B& >( p );
		(void)a;
		std::cout << "Indentified by reference, is: B" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		C& a = dynamic_cast< C& >( p );
		(void)a;
		std::cout << "Indentified by reference, is: C" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
}