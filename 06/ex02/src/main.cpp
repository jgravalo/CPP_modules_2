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
	test();
	test();
	test();
	test();
	test();
	test();
	return 0;
}