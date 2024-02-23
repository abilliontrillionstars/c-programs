

namespace ssuds
{
	/**
	* an implementation of the common LinkedList class.
	**/
	template <class T>
	class LinkedList
	{
	protected:
		class Node
		{
		public:
			T iData;
			Node* ahead;
			Node* behind;
		};

		/// <summary>points to the FIRST element in the list.</summary>
		Node* headButLikeNotInTheHTMLSenseBecauseThisIsntTheOOPSEClass;
		/// <summary>points to the LAST element in the list.</summary>
		Node* tail;
		/// <summary>number of ELEMENTS in the list</summary>
		unsigned int iSize;

	// [-<=>-]
	// CONSTRUCTORS/DESTRUCTORS
	// [-<=>-]
	public:
		/// <summary>no-method constructor, with the special : initializers</summary>
		LinkedList() : headButLikeNotInTheHTMLSenseBecauseThisIsntTheOOPSEClass(nullptr), tail(nullptr), iSize(0)
		{
			// empty, on purpose
		}

		/// <summary>no-method destructor</summary>
		~LinkedList()
		{

		}


	// [-<=>-]
	// METHODS
	// [-<=>-]
		/// <summary>standard size getter</summary>
		unsigned int size() const { return iSize; }

		/// <summary>adds an element to the end of the list</summary>
		void append(const T& new_val)
		{
			// make a new (disconnected) node
			Node* nnode = new Node;
			nnode->ahead = nullptr;
			nnode->behind = nullptr;
			nnode->iData = new_val;

			if (iSize == 0) // case empty list
			{
				headButLikeNotInTheHTMLSenseBecauseThisIsntTheOOPSEClass = nnode;
				tail = nnode;
			}

			else // case non-empty list
			{
				nnode->behind = tail;
				tail->ahead = nnode;  
				tail = nnode;		  
			}
			iSize++;
		}
		/// <summary>like append, but adds an element to the BEGINNING of the list</summary>
		void prepend(const T& new_val)
		{
			// make a new (disconnected) node
			Node* nnode = new Node;
			nnode->iData = new_val;

			if (iSize == 0) // case empty list
			{
				headButLikeNotInTheHTMLSenseBecauseThisIsntTheOOPSEClass = nnode;
				tail = nnode;
			}

			else // case non-empty list
			{
				nnode->ahead = headButLikeNotInTheHTMLSenseBecauseThisIsntTheOOPSEClass;
				headButLikeNotInTheHTMLSenseBecauseThisIsntTheOOPSEClass->behind = nnode;
				headButLikeNotInTheHTMLSenseBecauseThisIsntTheOOPSEClass = nnode;
			}
			iSize++;
		}


		/// <summary>inserts an element at the specified index</summary>
		void insert(unsigned int index, const T& val)
		{
			if (index > iSize)
				throw std::out_of_range("bad insert() index");
			else if (index == iSize)
				append(val);
			else if (!index)
				prepend(val);
			else
			{
				Node* nodeBefore = &this[index - 1];

				// ... Make a new node (like append)
				Node* nnode = new Node;
				nnode->iData = val;

				nnode->behind = nodeBefore;		  // a.
				nnode->ahead = nodeBefore->ahead; // d.
				nodeBefore->ahead->behind = nnode;// c.
				nodeBefore->ahead = nnode;		  // b.
			}
			iSize++;
		}

		void remove(unsigned int index)
		{
			
		}


	// [-<=>-]
	// OPERATOR OVERRIDES
	// [-<=>-]
		T& operator[](int index) const
		{
			if (index < iSize)
			{
				Node* result = headButLikeNotInTheHTMLSenseBecauseThisIsntTheOOPSEClass;
				for (int i = 0; i < index; i++)
					result = result->ahead;
				return result->iData;
			}
			else
				throw std::out_of_range("index given for get() is out of range");
		}


		friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list)
		{
			os << "[";
			for (int i = 0; i < list.size(); i++)
			{
				os << list[i];
				if (i < list.size() - 1)
					os << ", ";
			}
			os << "]";
			return os;
		}

	};
}