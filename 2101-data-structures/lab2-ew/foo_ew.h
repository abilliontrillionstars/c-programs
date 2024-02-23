#include <string>
#ifndef FOO_EW_H
#define FOO_EW_H

namespace testing
{
	class Foo
	{
	protected:
		std::string iName;
		int iAmount;
	public:
		Foo(std::string aName, int aAmount);
		Foo();
		std::string getName() const;
		int getAmount() const;

		void setName(std::string aName);
		void setAmount(int aAmount);
		friend std::ostream& operator<<(std::ostream& os, const Foo& foo);

	};
}

#endif
