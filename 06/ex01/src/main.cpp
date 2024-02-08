#include<Serializer.hpp>

int main()
{
	Data		u;
	Data		*p;
	uintptr_t	n;

	u.data = "hola que tal";
	std::cout << &u.data << std::endl;
	std::cout << u.data << std::endl;
	n = Serializer::serialize(&u);
	std::cout << std::hex << n << std::endl;
	p = Serializer::deserialize(n);
	std::cout << &p->data << std::endl;
	std::cout << p->data << std::endl;

	return 0;
}