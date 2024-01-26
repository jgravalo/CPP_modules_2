#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include<iostream>

typedef struct Data
{
	std::string	data;
}	Data;

class Serializer
{
	private:
		/* data */
	public:
		Serializer();
		Serializer(class Serializer& Copy);
		Serializer&		operator=(class Serializer& Copy);
		~Serializer();
		static uintptr_t		serialize(Data* ptr);
		static Data*			deserialize(uintptr_t raw);
		virtual void	f() = 0;
};

#endif

