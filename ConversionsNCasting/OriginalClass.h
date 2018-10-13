#pragma once

class NewerClass;

class OriginalClass
{
public:
	int myVal = 10;
	OriginalClass(NewerClass a);
	OriginalClass();
	~OriginalClass();
};