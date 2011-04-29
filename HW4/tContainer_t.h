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

public:
	
	//CTOR & DTOR
	tContainer_t();													//default CTOR
	tContainer_t(tContainer_t& tC);									//Copy CTOR
	~tContainer_t();													//DTOR

	//Operator Implementations
	tContainer_t& operator=(const tContainer_t& tC);				//Assignment Operator
	T* operator[](int index)const;									//[] operator
	void operator+=(tContainer_t& tC);								//merge of 2 containers: arr1 += arr2, after the merge  
																	//arr1 will contain arr1 & arr2 content and arr2 will be empty

	//Getter

	//Public Methods
	bool IsEmpty() const;											//is the container empty?
	int NumberOfElements() const;									//number of elements in the container
	void Insert(T element);											//insert  a new element in the end of the container
	T GetFirstElement();											//return the 1st element in the container
	T GetLastElement();												//return the last element in the container
	T* FindElement(T element);										//find specific element by value (in case of failure return 0)
	//TODO: check what that mean predicate that has to be written by user
	T* RemoveElement(T element);									//Remove the first element with the same value (in case of failure return 0)
	void RemoveAll();												//remove all elements without deleting them


private:

	//Private Member
	//TODO: add private members
};

#endif