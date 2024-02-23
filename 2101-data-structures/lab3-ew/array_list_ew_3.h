#ifndef ARRAYLIST_EW_3
#define ARRAYLIST_EW_3

#include <iostream>

namespace ssuds
{
	/**
	* a simple implementation of the common ArrayList class.
	**/
	template <class T>
	class ArrayList
	{
	protected:
		/// <summary>number of ELEMENTS in the array</summary>
		unsigned int iSize;
		/// <summary>number of ELEMENTS the array can hold</summary>
		unsigned int iCapacity;
		const static unsigned int defaultCapacity = 5;
		/// <summary>the actual array where the things are</summary>
		T* iData;

	public:
		class ArrayListIterator
		{
		protected:
			ArrayList& longArmOfTheLaw; //not sure if I'm actually going to use this but I wanted to write a funny variable name
			unsigned int iOffset;
		public:
			ArrayList::ArrayListIterator(ArrayList& target) { longArmOfTheLaw = target; iOffset = 0; }

			T& operator*() { return longArmOfTheLaw.get(iOffset); }
			void operator++() { iOffset++; }
			int operator==(const ArrayListIterator& other) { return *this == *other; }
			int operator!=(const ArrayListIterator& other) { return !(this == other); }
		};


		/// <summary>standard no-method constructor</summary>
		ArrayList() 
		{
			iSize = 0;
			iCapacity = defaultCapacity; 
			iData = new T[iCapacity];
		}

		/// <summary>no-method COPY constructor</summary>
		ArrayList(const ArrayList& other) : iCapacity(other.iCapacity), iSize(other.iSize)
		{
			iData = new T[iCapacity];
			for (int i = 0; i < other.size(); i++)
				iData[i] = other[i];
		}
		/// <summary>destructor similar to constructor</summary>
		~ArrayList() { delete[] iData; }


	// [-<=>-]
	// METHODS
	// [-<=>-]

		// ITERATOR METHODS
		ArrayListIterator& begin() { return ArrayListIterator(this, 0); }
		ArrayListIterator& end() { return ArrayListIterator(this, this->size()); }

		/// <summary>adds an element at the end of the list</summary>
		void append(const T& element)
		{
			if (iSize == iCapacity)
				iCapacity = iCapacity * 2;

			T* temp = new T[iCapacity];
			for (unsigned int i = 0; i < iSize; i++)
				temp[i] = iData[i];
			delete[] iData;
			iData = temp;

			iData[iSize] = element;
			iSize++;
		}
		/// <summary>a simple getter for iSize</summary>
		unsigned int size() const  { return iSize; }
		/// <summary>getter for iCapacity similarly to size()</summary>
		unsigned int capacity() const  { return iCapacity; }

		/// <summary>adds an element an the pecified index.</summary>
		void insert(const T& element, int index)
		{
			if (index == -1)
			{
				append(element);
				return;
			}
			else if (!(index <= iSize && index >= 0))
				throw std::out_of_range("index given for insert() is out of range");

			if (iSize == (iCapacity - 1))
			{
				iCapacity = iCapacity * 2;
				T* temp = new T[iCapacity];
				for (int i = 0; i < iSize; i++)
					temp[i] = iData[i];
				delete[] iData;
				iData = temp;
			}

			T* temp = new T[iCapacity];
			for (int i = 0; i < iSize; i++)
			{
				if (i < index)
					temp[i] = iData[i];
				else if (i == index)
					temp[i] = element;
				else if (1 > index)
					temp[i] = iData[i - 1];
			}
			delete[] iData;
			iData = temp;
		}
		/// <summary>removes every element from the list</summary>
		void clear()
		{
			delete[] iData;
			iSize = 0;
			iData = new std::string[0];
		}

		/// <summary>returns the index of the passed string, or -1 if the string doesnt exist in the list</summary>
		int find(T element)
		{
			for (int i = 0; i < iSize; i++)
				if (iData[i] == element)
					return i;
			return -1;
		}

		/// <summary>removes the element at the passed index </summary>
		void remove(unsigned int index)
		{
			if (iCapacity > defaultCapacity && iSize < (iCapacity / 2))
				iCapacity /= 2;
			T* temp = new T[iCapacity];

			if (!(index <= iSize && index >= 0))
				throw std::out_of_range("index given for insert() is out of range");
			for (unsigned int i = 0; i < iSize; i++)
			{
				if (i < index)
					temp[i] = iData[i];
				else if (1 > index)
					temp[i - 1] = iData[i];
			}
			delete[] iData;
			iData = temp;
			iSize--;
		}

		/// <summary>removes every element identical to the passed one</summary>
		/// <returns>the number of elements removed</returns>
		unsigned int removeAll(T element)
		{
			int numRemoved = 0;
			if (find(element) != -1)
			{
				remove(find(element));
				numRemoved += removeAll(element);
			}
			return numRemoved;
		}
		

	// [-<=>-]
	// OPERATOR OVERLOADS
	// [-<=>-]

		/// <summary>returns the string at the passed index</summary>
		T& operator[](int index) const
		{
			if (index < iSize)
				return iData[index];
			else
				throw std::out_of_range("index given for get() is out of range");
		}

		ArrayList<T>& operator= (const ArrayList<T>& other)
		{
			clear();
			iData = new T[other.iCapacity];
			for (int i = 0; i < other.iSize; i++)
				iData[i] = other[i];
			iCapacity = other.iCapacity;
			iSize = other.iSize;
			return *this;
		}

		friend std::ostream& operator<<(std::ostream& os, const ArrayList<T>& al)
		{
			os << "[";
			for (unsigned int i = 0; i < al.size(); i++)
			{
				os << al[i];
				if (i < al.size() - 1)
					os << ", ";
			}
			os << "]";
			return os;
		}
	};
}
#endif
