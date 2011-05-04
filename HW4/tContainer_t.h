//
//tContainer_t.h
//
// Assumption that were post in the virtual TAU forum:
// ***************************************************
// 1. the += operator only parameters will be container that wrap the same STL type and primitive type
// 2. the user always provide the same type of T and T* in the tContainer_t decleration
// 3. only the assign functionality of the [] operator should be implemented
// 4. index for assign [] can't be bigger than size.
//
#ifndef TContainer_t_H_ 
#define TContainer_t_H_

#include <vector>
#include <list>
#include <deque>
#include <typeinfo>
#include <algorithm>
#include <iostream>

using namespace std;


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
	tContainer_t<T,C>& operator=(const tContainer_t<T,C>& tC);		//Assignment Operator
	T*& operator[](unsigned index);									//[] Assign operator
    void operator+=(tContainer_t<T,C>& tC);							//merge of 2 containers: arr1 += arr2, after the merge  
																	//arr1 will contain arr1 & arr2 content and arr2 will be empty

    template<class T, class C>
    friend  ostream& operator<<(ostream &os, tContainer_t<T,C> &t);

	//Public Methods
	bool IsEmpty() const;											//is the container empty?
	int NumberOfElements() const;									//number of elements in the container
	void Insert(T* element);											//insert  a new element in the end of the container
	T* GetFirstElement() const;										//return the 1st element in the container
	T* GetLastElement() const;										//return the last element in the container
	T* FindElement(const T& element);										//find specific element by value (in case of failure return 0)
	T* RemoveElement(const T& element);									//Remove the first element with the same value (in case of failure return 0)
	void RemoveAll();												//remove all elements without deleting them

/******************************
 * Private Member deceleration*
 ******************************/

private:

	//Private Member
	C container;

};


/*********************************************
 * Equal predicate for find_if() STL function*
 *********************************************/

template<class T>
class tContainer_equal_t{

public:

    explicit tContainer_equal_t<T>(const T &obj): _obj (obj) { }

    bool operator()(const T* obj) const{
        return _obj == *obj;
    }

private:
    const T& _obj;
};

/******************************
 * CTOR and DTOR Implementation*
 ******************************/

template <class T, class C>
tContainer_t<T, C>::tContainer_t(){}


template <class T, class C>
tContainer_t<T, C>::tContainer_t( tContainer_t<T,C>& tC )
{
	container.insert(container.begin(), tC.container.begin(), tC.container.end());    
}

template <class T, class C>
tContainer_t<T, C>::~tContainer_t() { }

/*****************************
 * Operators implementations *
 *****************************/

template <class T, class C>
tContainer_t<T,C>& tContainer_t<T, C>::operator=( const tContainer_t<T,C>& tC )
{
	if(*this != tC){
				
        this->RemoveAll();
        container.insert(container.begin(), tC.container.begin(), tC.container.end());        

	}
	return *this;
}

//Note: Assign functionality implementation only
template <class T, class C>
T*& tContainer_t<T, C>::operator[]( unsigned index )
{
    T** tNULL = NULL;

    //if index out of bounds return 0
    if (index >= container.size()){
        return *tNULL;
    }

    iter_t it = container.begin();
    
    for (unsigned i = 0; i < index; i++, it++){}
    
    return *it;
          
}

template <class T, class C>
void tContainer_t<T, C>::operator+=( tContainer_t<T,C>& tC )
{
    
    container.insert(container.end(), tC.container.begin(), tC.container.end());

    tC.container.clear();
}

template<class T, class C>
ostream& operator<< (ostream &os, tContainer_t<T, C> &t){
    
    for (C::const_iterator it = t.container.begin(); it != t.container.end(); it++){
        os << **it << ' ';
    }

    os << '\n';
    return os;
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
T* tContainer_t<T, C>::FindElement(const T& element )
{
	iter_t it = find_if(container.begin(), container.end(), tContainer_equal_t<T>( element ) );

	if (it == container.end()){
		return 0;
	}

	return *it; 
}

template <class T, class C>
T* tContainer_t<T, C>::RemoveElement(const T& element )
{
    iter_t it = find_if(container.begin(), container.end(), tContainer_equal_t<T>(element));

	if (it != container.end())
	{
		T* result = *it;
		
        container.erase(it);

		return result;
	}

	return 0;
}

template <class T, class C>
void tContainer_t<T, C>::RemoveAll()
{
	container.clear();
}

#endif
