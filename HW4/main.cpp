#include "tContainer_t.h"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;

//TODO: use #define to choose different types of containers

//Members
int i, value, continerNumber, index, result;
tContainer_t <int, vector<int*>> container1 ,container2;

//Methods
void GetContainerNumber();
tContainer_t<int, vector<int*>>& GetContainer();


//Main
int main(int argc,int **argv){

	while (1)
	{
		cout << "Choose action:" << endl
			<< "*************" << endl
			<< "1- is Empty?			2 - number of elements" << endl
			<< "3- insert at the end	4 - return 1st" <<endl
			<< "5- return last			6 - find by value" <<endl
			<< "7- remove by value		8 - remove all" <<endl
			<< "9- insert using []		10 - get using []" <<endl
			<< "11- merge container		12 - exit" <<endl;
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
			cin >> value;
			GetContainer().Insert(value);
			break;
		case 4:
			GetContainerNumber();
			cout << "1st element is : " << GetContainer().GetFirstElement() << endl;
			break;
		case 5:
			GetContainerNumber();
			cout << "Last element is : " << GetContainer().GetLastElement() << endl;
			break;
		case 6:
			GetContainerNumber();
			cout << "enter value to find: " << endl;
			cin >> value;
			result = *(GetContainer().FindElement(value));
			if (result == value)
			{
				cout << "Element found" << endl;
			} 
			else if(result == 0)
			{
				cout << "Element not found" << endl;
			}else{
				cout << "unclear result" << endl;
			}
			break;
		case 7:
			GetContainerNumber();
			cout << "enter value to remove: " << endl;
			cin >> value;
			result = *(GetContainer().RemoveElement(value));
			if (result == value)
			{
				cout << "Element removed" << endl;
			} 
			else if(result == 0)
			{
				cout << "Element didn't found" << endl;
			}else{
				cout << "unclear result" << endl;
			}
			break;
		case 8:
			GetContainerNumber();
			GetContainer().RemoveAll();
			break;
		case 9:
			GetContainerNumber();
			cout << "enter index: " << endl;
			cin >> index;
			cout << "enter value: " << endl;
			cin >> value;
			GetContainer()[index] = value;
			break;
		case 10:
			GetContainerNumber();
			cout << "enter index: " << endl;
			cin >> index;
			cout << "index " << index << " have the value: " << GetContainer()[index] << endl;
			break;
		case 11:
			container1 += container2;
			cout << "container merged" << endl;
			break;
		case 12:
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

tContainer_t<int, vector<int*>>& GetContainer()
{
	if (continerNumber == 2)
	{
		return container2;
	}else{
		return container1;
	}
}

