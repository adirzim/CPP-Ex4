#ifndef TContainer_t_H_ 
#define TContainer_t_H_

#include <vector>
#include <list>
#include <deque>
#include <typeinfo>
#include <algorithm>
#include <iostream>

using namespace std;


//template <class T>
//T*& getRefOfIndex(list<T *> &c, unsigned index){
//     list<T *>::iterator it = c.begin();
//
//     for (unsigned i = 0; i < index; i++, it++){}
//
//     return *it;
//}
//
//template <class T, class C>
//T*& getRefOfIndex(C &c, unsigned index){
//    return c[index];
//}

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
	tContainer_t<T,C>& operator=(const tContainer_t<T,C>& tC);		//Assignment Operator
	
    //TODO: Assign & Get operator!
    T*& operator[](unsigned index);									//[] operator
    
	void operator+=(tContainer_t& tC);								//merge of 2 containers: arr1 += arr2, after the merge  
																	//arr1 will contain arr1 & arr2 content and arr2 will be empty

    template<class T, class C>
    friend  ostream& operator<<(ostream &os, tContainer_t<T,C> &t);

	//Public Methods
	bool IsEmpty() const;											//is the container empty?
	int NumberOfElements() const;									//number of elements in the container
	void Insert(T* element);											//insert  a new element in the end of the container
	T* GetFirstElement() const;										//return the 1st element in the container
	T* GetLastElement() const;										//return the last element in the container
	T* FindElement(T element);										//find specific element by value (in case of failure return 0)
	T* RemoveElement(T element);									//Remove the first element with the same value (in case of failure return 0)
	void RemoveAll();												//remove all elements without deleting them

/******************************
 * Private Member deceleration*
 ******************************/

private:

	//Private Member
	C container;
    iter_t it;

	//private Methods
	void findFirst( T element );									//return iterator of the first equivalent element otherwise return container.end()


};



/*
 * Equal predicate for find_if() STL function.
 */

template<class T>
class tContainer_equal_t{

public:

    explicit tContainer_equal_t<T>(T &obj): _obj (obj) { }

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
	int i;
    
    for (iter_type it = tC.container.begin(); it != tC.container.end(); it++){
        Insert(tc[i]);
    }
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
		//int i;
		
        this->RemoveAll();

        for (iter_type it = tC.container.begin(); it != tC.container.end(); it++){
            Insert(tc[i]);
        }

	}
	return *this;
}

//Assign
template <class T, class C>
T*& tContainer_t<T, C>::operator[]( unsigned index )
{
	//case container is list
	if (typeid(container)==typeid(list<T*>))
	{
        //iter_t it = container.begin();

        //for (unsigned i = 0; i < index; i++, it++){}

        return *it;

        //return  getRefOfIndex((dynamic_cast) container, index);

	} 

    
    else
    return container[index];
   //return getRefOfIndex(cont, index);
}



template <class T, class C>
void tContainer_t<T, C>::operator+=( tContainer_t& tC )
{

    for (iter_t it = tC.container.begin(); it != tC.container.end(); it++){
        Insert(*it);
    }
	
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
T* tContainer_t<T, C>::FindElement( T element )
{
	findFirst(element);	

    if (it != container.end()){
        return *it;
    }

    return 0;
}

template <class T, class C>
T* tContainer_t<T, C>::RemoveElement( T element )
{
	findFirst(element);

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

/**********************************
 * Private Methods implementation *
 **********************************/

template <class T, class C>
void tContainer_t<T, C>::findFirst( T element )
{

    it = find_if(container.begin(), container.end(), tContainer_equal_t<T>( element ) );
    
}


#endif
