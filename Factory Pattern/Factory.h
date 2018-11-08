#pragma once
#include <iostream>
#include "IBox.h"
#include "RedBox.h"
#include "BlueBox.h"
#include "IFactory.h"

class Factory : public IFactory
{
private:
	Factory() {}
	Factory(Factory const&);  // Prevents use
	void operator=(Factory const&); // Prevents use

public:
	static Factory& GetInstance();
	~Factory();

	IBox * Create(std::string type);
};