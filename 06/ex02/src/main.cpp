#include<Base.hpp>

void	test()
{
	Base *a = generate();

	identify(a);
	identify(*a);
}

int main()
{
	test();
	return 0;
}