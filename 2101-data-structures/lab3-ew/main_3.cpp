// lab2-ew.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "array_list_ew_3.h"
#include "foo_ew.h"
#include <iostream>

int main()
{
	ssuds::ArrayList<float> floatList;
	floatList.append(1.1f);
	floatList.append(2.2f);
	floatList.append(3.3f);

	std::cout << floatList << "\n";						// [1.1, 2.2, 3.3]
	std::cout << floatList[2] + floatList[1] << "\n";	// 5.5

	ssuds::ArrayList<testing::Foo> fooList;
	std::cout << "base capactity: " << fooList.capacity() << "\n"; // 5
	fooList.append(testing::Foo("First!", 5));
	fooList.append(testing::Foo());
	fooList.append(testing::Foo());
	fooList.append(testing::Foo());
	testing::Foo fifth = testing::Foo("Last!", 1);
	fooList.append(fifth);
	fifth.setName("kruhhhh.");
	std::cout << "new capacity: " << fooList.capacity() << fooList << "\n"; // 10 after reaching 5 elements
	fooList.remove(2);
	std::cout << "reduced capacity: " << fooList.capacity() << fooList << "\n"; // 10
	fooList.remove(1);
	std::cout << "reduced capacity: " << fooList.capacity() << fooList << "\n"; // 5

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
