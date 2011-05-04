//
// main.cpp
//
#include "tContainer_t.h"
#include "CatchMemoryLeak.h"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;

//Type of container & content 
//Note: should be replaced before running the main according to the needs
typedef int T;
typedef deque<T *> C;

//Members
int i, continerNumber, index;
T* result;
T value;
tContainer_t <T, C> container1 ,container2;
list<T *> values1, values2;


//Methods decelerations
void GetContainerNumber();
tContainer_t<T, C>& GetContainer();
list<T *> &GetValuesList(int i);

//Main
int main(int argc,int **argv){
	char answer;

    T *v;
    

	while (1)
	{
		cout <<endl 
			<< "Choose action:" << endl
			<< "*************" << endl
			<< "1- is Empty?			2 - number of elements" << endl
			<< "3- insert at the end		4 - return 1st" <<endl
			<< "5- return last			6 - find by value" <<endl
			<< "7- remove by value		8 - remove all" <<endl
			<< "9- Assign using []		10 - merge container" <<endl
			<< "11- Check for memory leaks" << endl
			<< "12- exit" <<endl<<endl;
		
        cout << "Container1:" << container1 << endl;
        cout << "Container2:" << container2 << endl;
        cin >> i;
		cout << endl;

		switch (i)
		{
		//is Empty?
		case 1:
			cout << "container 1 is " << (container1.IsEmpty()?"empty":"not empty") << endl
				 << "container 2 is " << (container2.IsEmpty()?"empty":"not empty") << endl
				 <<endl;
			break;
		//number of elements
		case 2:
			cout << "container 1 has " << container1.NumberOfElements() << " elements" <<endl
				<< "container 2 has " << container2.NumberOfElements() << " elements" <<endl
				<<endl;
			break;
		//insert at the end
		case 3:
			GetContainerNumber();
			cout << "enter value: " << endl;
            v = new T;
            cin >> *v;
            
            GetContainer().Insert(v);
            GetValuesList(continerNumber).push_back(v);
            
            break;
		//return 1st
		case 4:
			GetContainerNumber();
			cout << "1st element is : " << *GetContainer().GetFirstElement() << endl;
			break;
		//return last
		case 5:
			GetContainerNumber();
			cout << "Last element is : " << *GetContainer().GetLastElement() << endl;
			break;
		//find by value
		case 6:
			GetContainerNumber();
			cout << "enter value to find: " << endl;
			cin >> value;

			result = GetContainer().FindElement(value);
			if(result == 0){
				cout << "Element not found" << endl;
			}else if (*result == value){
				cout << "Element found" << endl;
			}else{
				cout << "unclear result" << endl;
			}
			break;
		//remove by value
		case 7:
			GetContainerNumber();
			cout << "enter value to remove: " << endl;
			cin >> value;

            result = GetContainer().RemoveElement(value);
			if(result == 0){
				cout << "Element didn't found" << endl;
			}else if (*result == value){
				cout << "Element removed" << endl;
                
                //Remove address in values vector in order to remove it
                GetValuesList(continerNumber).remove(result);
                delete result; //free memory
			}else{
				cout << "unclear result" << endl;
			}
			break;
		//remove all
		case 8:
			GetContainerNumber();
            GetContainer().RemoveAll();
			//free memory of the values vector
            for (list<T *>::iterator it = GetValuesList(continerNumber).begin(); it != GetValuesList(continerNumber).end(); it++){
                delete *it;
            }
			//clear the value list
            GetValuesList(continerNumber).clear();
			break;
		//Assign using []
		case 9:
			GetContainerNumber();
			cout << "enter index: " << endl;
			cin >> index;
			cout << "enter value: " << endl;
            cin >> value;

            if (index >= GetContainer().NumberOfElements()){
				cout << "illegal index" << endl;
                break;
            }

           *GetContainer()[index] = value;       
			break;
		//merge containers
		case 10:
			//free memory of the container 2 values vector
			for (list<T *>::iterator it = GetValuesList(2).begin(); it != GetValuesList(2).end(); it++){
				GetValuesList(1).push_back(*it);
			}
			//free memory of the container 2 values vector
			GetValuesList(2).clear();
			//merge containers
			container1 += container2;
			cout << "container merged" << endl;
			break;
		case 11:
			reportUnreleasedHeap(cout);
			break;
		case 12:
			//free the memory of the value vectors
			for (list<T *>::iterator it = GetValuesList(1).begin(); it != GetValuesList(1).end(); it++){
				v = *it;
				delete v;
			}
			for (list<T *>::iterator it = GetValuesList(2).begin(); it != GetValuesList(2).end(); it++){
				v = *it;
				delete v;
			}

			//delete elements of value vector
			values1.clear();values2.clear();

			//report on memory leaks
			reportUnreleasedHeap(cout);

			cout << "do you really want to exit? (y/n)" << endl;
			cin >> answer;
			if(answer == 'n'){
				break;
			}
			exit(1);
			break;
		}
	}
	return 1;
}

//Method Implementations

void GetContainerNumber(){
	cout << "choose container (1/2): " <<endl;
	cin >> continerNumber;
}

tContainer_t<T, C>& GetContainer()
{
	if (continerNumber == 2)
	{
		return container2;
	}else{
		return container1;
	}
}

list<T *> &GetValuesList(int i){

    if (i == 2){
        return values2;
    }
    else
        return values1;

}




