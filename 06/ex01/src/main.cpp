#include<Serializer.hpp>

int main()
{
	Data		u;
	Data		*p;
	uintptr_t	n;

	u.data = "hola que tal";
	n = Serializer::serialize(&u);
	p = Serializer::deserialize(n);
	std::cout << p->data << std::endl;

	return 0;
}