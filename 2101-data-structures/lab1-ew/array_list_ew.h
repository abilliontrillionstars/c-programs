#ifndef ARRAYLIST_EW
#define ARRAYLIST_EW

#include <string>

namespace ssuds
{
	/**
	* a simple implementation of the common ArrayList class.
	**/
	class ArrayList
	{
	protected:
		/// <summary>
		/// number of ELEMENTS in the array of strings
		/// </summary>
		unsigned int iSize;
		/// <summary>
		/// the actual array where the strings are
		/// </summary>
		std::string* iData;
	public:
		
		/// <summary>
		/// standard no-method constructor
		/// </summary>
		ArrayList();
		/// <summary>
		/// destructor similar to constructor
		/// </summary>
		~ArrayList();

		/// <summary>
		/// adds an element at the end of the list
		/// </summary>
		void append(std::string s);
		/// <summary>
		/// a simple getter for iSize
		/// </summary>
		unsigned int size();


		/// <summary>
		/// adds an element an the pecified index.
		/// </summary>
		void insert(std::string s, int index);
		/// <summary>
		/// removes every element from the list
		/// </summary>
		void clear();
		/// <summary>
		/// returns the string at the passed index
		/// </summary>
		std::string get(unsigned int index);
		/// <summary>
		/// returns the index of the passed string, or -1 if the string doesnt exist in the list
		/// </summary>
		int find(std::string s);
		/// <summary>
		/// removes the element at the passed index 
		/// </summary>
		void remove(unsigned int index);
		/// <summary>
		/// removes every element identical to the passed one
		/// </summary>
		unsigned int removeAll(std::string s);
	};
}
#endif
