#include "NewerClass.h"
#include "OriginalClass.h"
NewerClass::NewerClass(OriginalClass a)
{
	bsMyVal = a.myVal;
}
NewerClass::NewerClass() {}
NewerClass::~NewerClass() {}