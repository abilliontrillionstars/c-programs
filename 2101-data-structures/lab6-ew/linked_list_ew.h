
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
			/// <summary>the node's value</summary>
			T iData;
			/// <summary>points to the nodes ahead and behind this one</summary>
			Node* ahead, behind;
		};
	public:
		class LinkedListIterator
		{
		protected:
			/// <summary>reaches to this iterator's list</summary>
			LinkedList& longArmOfTheLaw;
			/// <summary>represents the iterator's 'index' to its list</summary>
			unsigned int iOffset;
			/// <summary>points to the currently targeted node</summary>
			Node* iNode;
		public:
			/// <summary>standard consturctor (now takes a node pointer!)</summary>
			LinkedList::LinkedListIterator(Node* initNode, LinkedList& parent, unsigned int aOffset) : iNode(initNode), longArmOfTheLaw(parent), iOffset(aOffset) {}

			/// <summary>getter for the iterator's index</summary>
			unsigned int position() { return iOffset; }
			/// <summary>returns the data this iterator currently points to</summary>
			T& operator*() { return iNode; }
			/// <summary>increment operator</summary>
			void operator++()
			{
				iOffset++;
				iNode = iNode->ahead;
			}
			void operator++(int usused)
			{
				iOffset++;
				iNode = iNode->ahead;
			}

			/// <summary>equates this iterator to another by comparing</summary>
			int operator==(const LinkedListIterator& other) const
			{
				return longArmOfTheLaw == other.longArmOfTheLaw
					&& iOffset == other.iOffset;
			}
			/// <summary>knotted call of the == operator</summary>
			int operator!=(const LinkedListIterator& other) const { return !(this == other); }
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
		LinkedList() : headButLikeNotInTheHTMLSenseBecauseThisIsntTheOOPSEClass(nullptr), tail(nullptr), iSize(0) {}
		/// <summary>no-method destructor</summary>
		~LinkedList() { clear(); }


		// [-<=>-]
		// METHODS
		// [-<=>-]
		/// <summary>standard size getter</summary>
		unsigned int size() const { return iSize; }

		LinkedListIterator& begin() { return LinkedListIterator(this->headButLikeNotInTheHTMLSenseBecauseThisIsntTheOOPSEClass, this, 0); }
		LinkedListIterator& end() { return LinkedListIterator(this->tail, this, iSize); }

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

		/// <summary>deletes all the nodes in the list</summary>
		void clear()
		{
			Node* target = headButLikeNotInTheHTMLSenseBecauseThisIsntTheOOPSEClass;
			for (int i = 0; i < iSize - 1; i++)
			{
				target = target->ahead;
				delete target->behind;
			}
			delete target;

			headButLikeNotInTheHTMLSenseBecauseThisIsntTheOOPSEClass = nullptr;
			tail = nullptr;
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