#include "tContainer_t.h"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;


typedef int T;

typedef vector<T *> C;

//Members
int i, continerNumber, index;
T* result;
T value;
tContainer_t <T, C> container1 ,container2;
list<T *> values1, values2;


//Methods
void GetContainerNumber();
tContainer_t<T, C>& GetContainer();

list<T *> &GetValuesList(int i);

//Main
int main(int argc,int **argv){

    T *v;
    

	while (1)
	{
		cout << "Choose action:" << endl
			<< "*************" << endl
			<< "1- is Empty?			2 - number of elements" << endl
			<< "3- insert at the end		4 - return 1st" <<endl
			<< "5- return last			6 - find by value" <<endl
			<< "7- remove by value		8 - remove all" <<endl
			<< "9- insert using []		10 - get using []" <<endl
			<< "11- merge container		12 - exit" <<endl;
		
        cout << "Container1:" << container1 << endl;
        cout << "Container2:" << container2 << endl;
        cin >> i;
		cout << endl;

		switch (i)
		{
		case 1:
			cout << "container 1 is " << (container1.IsEmpty()?"empty":"not empty") << endl
				 << "container 2 is " << (container2.IsEmpty()?"empty":"not empty") << endl
				 <<endl;
			break;
		case 2:
			cout << "container 1 has " << container1.NumberOfElements() << " elements" <<endl
				<< "container 2 has " << container2.NumberOfElements() << " elements" <<endl
				<<endl;
			break;
		case 3:
			GetContainerNumber();
			cout << "enter value: " << endl;
            v = new T;
            cin >> *v;
            
            GetContainer().Insert(v);
            GetValuesList(continerNumber).push_back(v);
            
            break;
		case 4:
			GetContainerNumber();
			cout << "1st element is : " << *GetContainer().GetFirstElement() << endl;
			break;
		case 5:
			GetContainerNumber();
			cout << "Last element is : " << *GetContainer().GetLastElement() << endl;
			break;
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
		case 8:
			GetContainerNumber();

            GetContainer().RemoveAll();

            for (list<T *>::iterator it = GetValuesList(continerNumber).begin(); it != GetValuesList(continerNumber).end(); it++){
                delete *it;
            }

            GetValuesList(continerNumber).clear();

			break;
		case 9:
			GetContainerNumber();
			cout << "enter index: " << endl;
			cin >> index;
			cout << "enter value: " << endl;
            cin >> value;

            *(GetContainer()[index]) = value;
            

			break;
		case 10:
			/*GetContainerNumber();
			cout << "enter index: " << endl;
			cin >> index;
			cout << "index " << index << " have the value: " << GetContainer()[index] << endl;*/
            cout << "Retrieve not implemented";
			break;
		case 11:

            
            for (list<T *>::iterator it = GetValuesList(2).begin(); it != GetValuesList(2).end(); it++){
                GetValuesList(1).push_back(*it);
            }

            GetValuesList(2).clear();
        
			container1 += container2;
			cout << "container merged" << endl;

			break;
		case 12:
			
            for (list<T *>::iterator it = GetValuesList(1).begin(); it != GetValuesList(1).end(); it++){
                v = *it;
                delete v;
            }
            for (list<T *>::iterator it = GetValuesList(2).begin(); it != GetValuesList(2).end(); it++){
                v = *it;
                delete v;
            }

            values1.clear();values2.clear();


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




