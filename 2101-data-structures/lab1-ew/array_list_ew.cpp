#include "array_list_ew.h"
#include <stdexcept>

ssuds::ArrayList::ArrayList()
{
	// Set your attributes to starting values
	iSize = 0;
	iData = new std::string[0];
}

ssuds::ArrayList::~ArrayList() { delete[] iData; }

void ssuds::ArrayList::append(std::string s)
{
	// 1. The array is currently empty
	if (!iSize)
	{
		//	   Make the array to be of size 1
		iData = new std::string[1];
		//     Put the value s and put it in the only spot in the array
		iData[0] = s;
		//     Set mSize to 1
		iSize = 1;
	}
	// 2. The array has stuff in it
	else
	{
		//     Make a new temporary array that's 1 bigger than our current array
		std::string* temp = new std::string[iSize + 1];
		//     Copy all old elements to the new array
		for (int i = 0; i < iSize; i++)
			temp[i] = iData[i];
		//     Make the last element in the bigger array be s
		temp[iSize] = s;
		//     Free up the old (smaller) array
		delete[] iData;
		//     Assign the larger array to mData
		iData = temp;
		//     Increment iSize
		iSize++;
	}
	
}

unsigned int ssuds::ArrayList::size()  { return iSize; }

void ssuds::ArrayList::insert(std::string s, int index)
{
	// like last time, make a new temporary array that's 1 bigger than our current array
	std::string* temp = new std::string[++iSize];

	if (index == -1)
	{
		append(s);
		return;
	}
	else if (!(index <= iSize && index >= 0))
		throw std::out_of_range("index given for insert() is out of range");
	// copy the array around the passed index
	for (int i = 0; i < iSize; i++)
	{
		if (i < index)
			temp[i] = iData[i];
		else if (i == index)
			temp[i] = s;
		else if (1 > index)
			temp[i] = iData[i - 1];
	}
	// continue and update the array
	delete[] iData;
	iData = temp;
	// note the lack of iSize++; as we increased the size at the start
}


void ssuds::ArrayList::clear()
{
	delete[] iData;
	iSize = 0;
	iData = new std::string[0];
}


std::string ssuds::ArrayList::get(unsigned int index)
{
	if (index < iSize)
		return iData[index];
	else
		throw std::out_of_range("index given for get() is out of range");
}


int ssuds::ArrayList::find(std::string s)
{
	for (int i = 0; i < iSize; i++)
		if (iData[i] == s)
			return i;
	return -1;
}


void ssuds::ArrayList::remove(unsigned int index)
{
	// basically just insert(), reversed
	std::string* temp = new std::string[--iSize];

	if (!(index <= iSize && index >= 0))
		throw std::out_of_range("index given for insert() is out of range");
	// copy the array around the passed index
	for (int i = 0; i < iSize; i++)
	{
		if (i < index)
			temp[i] = iData[i];
		else if (1 > index)
			temp[i - 1] = iData[i];
	}
	// continue and update the array
	delete[] iData;
	iData = temp;
}

unsigned int ssuds::ArrayList::removeAll(std::string s)
{
	int numRemoved = 0;
	if (find(s) != -1)
	{
		remove(find(s));
		numRemoved++;
		removeAll(s);
	}
	return numRemoved;
}



