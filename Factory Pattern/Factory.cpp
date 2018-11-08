#include "Factory.h"

void Factory::operator=(Factory const &)
{
}

Factory & Factory::GetInstance()
{
	// TODO: insert return statement here
	static Factory* instance = new Factory;
	return *instance;
}

Factory::~Factory()
{
}

IBox* Factory::Create(std::string type)
{
	if (type == "Red")
		return new RedBox();

	if (type == "Blue")
		return new BlueBox();

	return NULL;
}