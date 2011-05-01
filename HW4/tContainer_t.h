#ifndef TContainer_t_H_ 
#define TContainer_t_H_

#include <vector>
#include <list>
#include <deque>
#include <typeinfo>
#include <algorithm>

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
	tContainer_t(tContainer_t<T,C>& tC);							//Copy CTOR
	~tContainer_t();												//DTOR

	//Operator Implementations
	tContainer_t<T,C>& operator=(const tContainer_t<T,C>& tC);				//Assignment Operator
	
    //TODO: Assign & Get operator!
    T* operator[](int index)const;									//[] operator
    
	void operator+=(tContainer_t& tC);								//merge of 2 containers: arr1 += arr2, after the merge  
																	//arr1 will contain arr1 & arr2 content and arr2 will be empty
	//Public Methods
	bool IsEmpty() const;											//is the container empty?
	int NumberOfElements() const;									//number of elements in the container
	void Insert(T* element);											//insert  a new element in the end of the container
	T* GetFirstElement() const;										//return the 1st element in the container
	T* GetLastElement() const;										//return the last element in the container
	T* FindElement(T* element);										//find specific element by value (in case of failure return 0)
	T* RemoveElement(T* element);									//Remove the first element with the same value (in case of failure return 0)
	void RemoveAll();												//remove all elements without deleting them

/******************************
 * Private Member deceleration*
 ******************************/

private:

	//Private Member
	C container;
	iter_t c_iterator;
	T* SearchedElement;

	//private Methods
	void findFirst( T* element );									//return iterator of the first equivalent element otherwise return container.end()
	bool areEqual(T* val);											//predicate to use in find_if

};

#endif

/******************************
 * CTOR and DTOR Implementation*
 ******************************/

template <class T, class C>
tContainer_t<T, C>::tContainer_t()
{
	//TODO: is there anything to do here
}

template <class T, class C>
tContainer_t<T, C>::tContainer_t( tContainer_t<T,C>& tC )
{
	int i;
	//TODO: implement
	this->RemoveAll();
	for (i = 0 ; i < tC.NumberOfElements() ; i++)
	{
		Insert(tC[i]);
	}
}

template <class T, class C>
tContainer_t<T, C>::~tContainer_t()
{
	//TODO: is there anything to do here
}

/*****************************
 * Operators implementations *
 *****************************/

template <class T, class C>
tContainer_t<T,C>& tContainer_t<T, C>::operator=( const tContainer_t<T,C>& tC )
{
	if(this != &tC){
		int i;
		this->RemoveAll();
		for (i = 0 ; i < tC.NumberOfElements() ; i++)
		{
			Insert(tC[i]);
		}
	}
	return *this;
}

template <class T, class C>
T* tContainer_t<T, C>::operator[]( int index ) const
{
	//case container is list
	if (typeid(container)==typeid(list<T*>))
	{
		//TODO: implement
		return *c_iterator;
	} 
	return container[index];
}

template <class T, class C>
void tContainer_t<T, C>::operator+=( tContainer_t& tC )
{
	while(!tC.IsEmpty()){
		T* otherElement = tC.GetFirstElement();
		Insert(otherElement);
		tC.RemoveElement(otherElement);
	}
}

/*********************************
 * Public Methods implementation *
 *********************************/

template <class T, class C>
bool tContainer_t<T, C>::IsEmpty() const
{
	return container.empty();
}

template <class T, class C>
int tContainer_t<T, C>::NumberOfElements() const
{
	return container.size();
}

template <class T, class C>
void tContainer_t<T, C>::Insert( T* element )
{
	container.push_back(element);
}

template <class T, class C>
T* tContainer_t<T, C>::GetFirstElement() const
{
	return container.front();
}

template <class T, class C>
T* tContainer_t<T, C>::GetLastElement() const
{
	return container.back();
}

template <class T, class C>
T* tContainer_t<T, C>::FindElement( T* element )
{
	findFirst(element);
	if (c_iterator!= container.end())
	{
		return *c_iterator;
	}
	return 0;
}

template <class T, class C>
T* tContainer_t<T, C>::RemoveElement( T* element )
{
	findFirst(element);
	if (c_iterator!= container.end())
	{
		T* result = *c_iterator;
		container.erase(c_iterator);
		return result;
	}

	return 0;
}

template <class T, class C>
void tContainer_t<T, C>::RemoveAll()
{
	container.clear();
}

/**********************************
 * Private Methods implementation *
 **********************************/

template <class T, class C>
void tContainer_t<T, C>::findFirst( T* element )
{

//	SearchedElement = element;
//	c_iterator = find_if(container.begin(), container.end(), &tContainer_t<T, C>::areEqual);
}

template <class T, class C>
bool tContainer_t<T, C>::areEqual( T* val )
{
	return SearchedElement == val;
}
