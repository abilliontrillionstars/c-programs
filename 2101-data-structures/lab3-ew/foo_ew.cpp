#include "foo_ew.h"
#include <string>
#include <iostream>

testing::Foo::Foo()
{
	iName = "";
	iAmount = 0;
}

testing::Foo::Foo(std::string aName, int aAmount)
{
	iName = aName;
	iAmount = aAmount;
}

std::string testing::Foo::getName() const  { return iName; }
int testing::Foo::getAmount() const  { return iAmount; }

void testing::Foo::setName(std::string aName)  { iName = aName; }
void testing::Foo::setAmount(int aAmount) { iAmount = aAmount; }

std::ostream& testing::operator<<(std::ostream& os, const Foo& f)
{
	os << "<FOO:" << f.getAmount() << ":" << f.getName() << ">";
	return os;
}
