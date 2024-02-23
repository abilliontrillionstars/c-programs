#include "array_list_ew.h"
#include <iostream>


int main()
{
	ssuds::ArrayList spells;
	spells.append("fireball");
	spells.append("geas");
	std::cout << spells.size() << "\n";	// 2	
	spells.insert("globe of invulnerability", 1);
	std::cout << spells.size() << "\n";	// 3	
	spells.append(spells.get(spells.find("fireball"))); // method chaining
	spells.append("command");
	spells.append("create or destroy water");
	std::cout << spells.size() << "\n";	// 6	
	spells.insert("fireball", 4); // I don't care how big the array is, I add fireball!

	std::cout << spells.find("command") << "\n"; // 5

	// without the 3 fireballs, your spell list is only 4 spells long.
	std::cout << "without the " < spells.removeAll("fireball") << " fireballs, your spell list is only " << spells.size() << " spells long.";
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
