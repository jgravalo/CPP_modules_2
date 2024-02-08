#include<Serializer.hpp>

Serializer::Serializer()
{
}

Serializer::Serializer(class Serializer& Copy)
{
	(void)Copy;
}

Serializer&	Serializer::operator=(class Serializer& Copy)
{
	(void)Copy;
	return (*this);
}

Serializer::~Serializer()
{
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	uintptr_t n = reinterpret_cast<uintptr_t>(ptr);
	return (n);
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	Data*	d;
	d = reinterpret_cast<Data *>(raw);
	return (d);
}
