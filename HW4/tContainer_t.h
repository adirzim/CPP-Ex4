#ifndef TContainer_t_H_ 
#define TContainer_t_H_

#include <vector>
#include <list>
#include <deque>

using namespace std;

//Template class which wraps any sequential STL container (vector, List, deque)
template <class T, class C>
class tContainer_t{

typedef typename C::iterator iter_t;

/******************************
 * Public Member deceleration*
 ******************************/

public:
	
	//CTOR & DTOR
	tContainer_t();													//default CTOR
	tContainer_t(tContainer_t& tC);									//Copy CTOR
	~tContainer_t();												//DTOR

	//Operator Implementations
	tContainer_t& operator=(const tContainer_t& tC);				//Assignment Operator
	T& operator[](int index)const;									//[] operator
	void operator+=(tContainer_t& tC);								//merge of 2 containers: arr1 += arr2, after the merge  
																	//arr1 will contain arr1 & arr2 content and arr2 will be empty
	//Public Methods
	bool IsEmpty() const;											//is the container empty?
	int NumberOfElements() const;									//number of elements in the container
	void Insert(T element);											//insert  a new element in the end of the container
	T* GetFirstElement() const;										//return the 1st element in the container
	T* GetLastElement() const;										//return the last element in the container
	T* FindElement(T element);										//find specific element by value (in case of failure return 0)
	//TODO: check what that mean predicate that has to be written by user
	T* RemoveElement(T element);									//Remove the first element with the same value (in case of failure return 0)
	void RemoveAll();												//remove all elements without deleting them

/******************************
 * Private Member deceleration*
 ******************************/

private:

	//Private Member
	C container;
	//TODO: add private members
};

#endif

/******************************
 * CTOR and DTOR Implementation*
 ******************************/

template <class T, class C>
tContainer_t<T, C>::tContainer_t()
{
	//TODO: implement
}

template <class T, class C>
tContainer_t<T, C>::tContainer_t( tContainer_t& tC )
{
	//TODO: implement
}

template <class T, class C>
tContainer_t<T, C>::~tContainer_t()
{
	//TODO: implement
}

/*****************************
 * Operators implementations *
 *****************************/

template <class T, class C>
tContainer_t& tContainer_t<T, C>::operator=( const tContainer_t& tC )
{
	//TODO: implement
	return NULL;
}

template <class T, class C>
T& tContainer_t<T, C>::operator[]( int index ) const
{
	//TODO: implement
	return NULL;
}

template <class T, class C>
void tContainer_t<T, C>::operator+=( tContainer_t& tC )
{
	//TODO: implement
	return NULL;
}

/*********************************
 * Public Methods implementation *
 *********************************/

template <class T, class C>
bool tContainer_t<T, C>::IsEmpty() const
{
	//TODO: implement
	return NULL;
}

template <class T, class C>
int tContainer_t<T, C>::NumberOfElements() const
{
	//TODO: implement
	return 0;
}

template <class T, class C>
void tContainer_t<T, C>::Insert( T element )
{
	//TODO: implement
}

template <class T, class C>
T* tContainer_t<T, C>::GetFirstElement() const
{
	//TODO: implement
	return NULL;
}

template <class T, class C>
T* tContainer_t<T, C>::GetLastElement() const
{
	//TODO: implement
	return NULL;
}

template <class T, class C>
T* tContainer_t<T, C>::FindElement( T element )
{
	//TODO: implement
	return NULL;
}

template <class T, class C>
T* tContainer_t<T, C>::RemoveElement( T element )
{
	//TODO: implement
	return NULL;
}

template <class T, class C>
void tContainer_t<T, C>::RemoveAll()
{
	//TODO: implement
}