#include "serialize.hpp"



Data::Data(int value)
{
	this->id = value;
}

int Data::getId(void) const{
	return (this->id);
}

uintptr_t serialize(Data* ptr)
{
	uintptr_t tmp = reinterpret_cast <uintptr_t>(ptr);
	return (tmp);
}

Data* deserialize(uintptr_t raw)
{
	Data *tmp = reinterpret_cast <Data*>(raw);
	return (tmp);
}

int main ()
{
	Data *test = new Data(12);
	uintptr_t tmp;
	Data *tmpPtr;

	std::cout << "originale ptr value: " << test << std::endl;
	tmp = serialize (test);
	std::cout << "uniptr_t value: " << tmp << std::endl;
	tmpPtr = deserialize (tmp);
	std::cout << "data: " << tmpPtr->getId() << std::endl;
}