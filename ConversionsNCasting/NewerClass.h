#pragma once

class OriginalClass;

class NewerClass
{
public:
	int bsMyVal = 0;
	NewerClass(OriginalClass a);
	NewerClass();
	~NewerClass();
};