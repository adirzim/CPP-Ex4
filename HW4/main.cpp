#include "tContainer_t.h"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;

//Members
//bool first = true;				//set to true at first run
int i,j,k,l,m,n;				//indexes
//int containerType;				//describe the type chosen by the user


//TODO: how to choose and access different types of containers

tContainer_t<string, vector<string*>> vecStringCont1;
tContainer_t<string, vector<string*>> vecStringCont2;
//tContainer_t<double, vector<double*>> vecDoubleCont1;
//tContainer_t<double, vector<double*>> vecDoubleCont2;
//tContainer_t<string, list<string*>> listStringCont1;
//tContainer_t<string, list<string*>> listStringCont2;
//tContainer_t<double, list<double*>> listDoubleCont1;
//tContainer_t<double, list<double*>> listDoubleCont2;
//tContainer_t<string, deque<string*>> dequeStringCont1;
//tContainer_t<string, deque<string*>> dequeStringCont2;
//tContainer_t<double, deque<double*>> dequeDoubleCont1;
//tContainer_t<double, deque<double*>> dequeDoubleCont2;

//Methods
//void ChooseContainers();									//choose the type of the containers
//tContainer_t* GetContainer(int number);						//get the requested container

//Main
int main(int argc,int **argv){

	while (1)
	{
//		if (first)
//		{
//			ChooseContainers();
//			first = false;
//		}

	}

	return 1;
}

//Method Implementations


//void ChooseContainers()
//{
//	cout << "Choose type:" << endl
//		<< "***********" << endl
//		<< "1 - string			2 - double" << endl
//	cin >> i;
//	cout << endl;
//
//	cout << "Choose container:" << endl
//		<< "*****************" << endl
//		<< "1 - Vector			2 - List" << endl
//		<< "3 - deque" << endl;
//		cin >> j;
//	cout << endl;
//
//	containerType = (i*100+j*10);
//}

//tContainer_t GetContainer(int number){
//
//	switch(containerType+number){
//		case 111:
//			return vecStringCont1;
//		case 112:
//			return vecStringCont2;
//		case 121:
//			return listStringCont1;
//		case 122:
//			return listStringCont2;
//		case 131:
//			return dequeStringCont1;
//		case 132:
//			return dequeStringCont1;
//		case 211:
//			return vecDoubleCont1;
//		case 212:
//			return vecDoubleCont2;
//		case 221:
//			return listDoubleCont1;
//		case 222:
//			return listDoubleCont2;
//		case 231:
//			return dequeDoubleCont1;
//		case 232:
//			return dequeDoubleCont2;
//	}
//}