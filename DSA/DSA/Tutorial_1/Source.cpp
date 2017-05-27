
/********************************************************************************test 2*********************************************************************************/
// A small program to used std::find() algorithm on vector container
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main()
{
	int n1 = 4;
	int n2 = 5;

	std::vector<int> v{ 0, 1, 2, 3, 4 };

	auto result1 = std::find(std::begin(v), std::end(v), n1);
	auto result2 = std::find(std::begin(v), std::end(v), n2);

	if (result1 != std::end(v)) {
		std::cout << "v contains: " << n1 <<  \n ;
	}
	else {
		std::cout << "v does not contain: " << n1 <<  \n ;
	}

	if (result2 != std::end(v)) {
		std::cout << "v contains: " << n2 <<  \n ;
	}
	else {
		std::cout << "v does not contain: " << n2 <<  \n ;
	}
}
*/
/********************************************************************************test 2*********************************************************************************/
/// Technique to reset the "capacity" of vector container, used swap function
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

class A
{
public:
	A(){}
	virtual ~A(){}

};


int main()
{
	std::map<int, A> mapA;

	std::vector<int> a,a1;
	std::cout << "size1: " << a.size() << std::endl;
	std::cout << "capacity: " << a.capacity() << std::endl;
	for (int ii = 0; ii < 10000; ++ii)
	{
		a.push_back(ii);
	}

	std::cout << "size2: " << a.size() << std::endl;
	std::cout << "capacity2: " << a.capacity() << std::endl;

	a.resize(0);
	a.reserve(0);
	//std::vector<int>().swap(a);
	a = std::vector<int>();
	std::cout << "size3: " << a.size() << std::endl;
	std::cout << "capacity3: " << a.capacity() << std::endl;
	std::cout << "capacity4: " << a1.capacity() << std::endl;

	char c;
	std::cin >> c;
	return 0;
}
*/
/********************************************************************************test 2*********************************************************************************/
/********************************************************************************test 5*********************************************************************************/
/// Example to use multi-map, useful if key-variables are same
//#include <map>
//#include <string>
//#include <iostream>
//
//int
//main(int argc, char** argv)
//{
//	std::multimap<std::string, std::string> m;
//	m.insert(std::make_pair("A", "B"));
//	m.insert(std::make_pair("A", "B"));
//	m.insert(std::make_pair("A", "C"));
//	std::cout << m.size() << std::endl;
//	return 0;
//}
/********************************************************************************test 5*********************************************************************************/

///******************************************************************************test 6*******************************************************/
// Example using member function pointer
//
//#include <iostream>
//
//
//class A
//{
//public:
//	typedef int(A::*AMemberFuncType)(int, int, int);
//
//	A();
//	int func(int a, int b, int c)
//	{
//		return (a + b + c);
//	}
//
//	AMemberFuncType getFptr()
//	{
//		return AMemberFunc;
//	}
//private:
//	AMemberFuncType AMemberFunc;
//};
//
//
//
//A::A()
//{
//	AMemberFunc = &A::func;
//}
//
//class B
//{
//	
//public:
//	typedef int(B::*BMemberFuncType)(int, int);
//	B();
//	int func(int a, int b)
//	{
//		return (a + b);
//	}
//	BMemberFuncType getFptr()
//	{
//		return BMemberFunc;
//	}
//private:
//	//int(B::*BMemberFunc)(int, int);
//	BMemberFuncType BMemberFunc;
//
//};
//
//
//B::B()
//{
//	BMemberFunc = &B::func;
//}
//
//class C
//{
//public:
//	typedef int(C::*CMemberFuncType)(int);
//	C();
//	int func(int a)
//	{
//		return (a * a);
//	}
//	CMemberFuncType getFptr()
//	{
//		return CMemberFunc;
//	}
//private:
//	CMemberFuncType CMemberFunc;
//};
//
//
//
//C::C()
//{
//	CMemberFunc = &C::func;
//}
//
//int main()
//{
//	//AMemberFunc p = &A::func;
//	{
//		B *pB = new B;
//		B::BMemberFuncType myBfptr = pB->getFptr();//&B::func;//
//		int sumB = (pB->*myBfptr)(3, 4);
//		delete pB;
//		pB = NULL;
//		std::cout << "SumB = " << sumB << std::endl;
//	}
//
//	{
//		A* pA = new A;
//		A::AMemberFuncType myAfptr = pA->getFptr();//&B::func;//
//		int sumA = (pA->*myAfptr)(5, 6, 7);
//		delete pA;
//		pA = NULL;
//		std::cout << "SumA = " << sumA << std::endl;
//	}
//
//	{
//		C* pC = new C;
//		C::CMemberFuncType myCfptr = pC->getFptr();//&B::func;//
//		int sumC = (pC->*myCfptr)(8);
//		delete pC;
//		pC = NULL;
//		std::cout << "SumC = " << sumC << std::endl;
//
//	}
//
//	return 0;
//}


/********************************************************************************test 6- member function pointers*******************************************************/

/********************************************************************************test 6- array of function pointers*******************************************************/
//
//#include <iostream>
//#include <tuple>
//#include <vector>
//#include <typeinfo>
//#include <typeindex>
//#include <map>
//class A
//{
//public:
//	typedef int(A::*AMemberFuncType)(int, int, int);
//
//	A();
//	int func(int a, int b, int c)
//	{
//		return (a + b + c);
//	}
//
//	AMemberFuncType getFptr()
//	{
//		return AMemberFunc;
//	}
//private:
//	AMemberFuncType AMemberFunc;
//};
//
//
//
//A::A()
//{
//	AMemberFunc = &A::func;
//}
//
//class B
//{
//
//public:
//	typedef int(B::*BMemberFuncType)(int, int);
//	B();
//	int func(int a, int b)
//	{
//		return (a + b);
//	}
//	BMemberFuncType getFptr()
//	{
//		return BMemberFunc;
//	}
//private:
//	//int(B::*BMemberFunc)(int, int);
//	BMemberFuncType BMemberFunc;
//
//};
//
//
//B::B()
//{
//	BMemberFunc = &B::func;
//}
//
//class C
//{
//public:
//	typedef int(C::*CMemberFuncType)(int);
//	C();
//	int func(int a)
//	{
//		return (a * a);
//	}
//	CMemberFuncType getFptr()
//	{
//		return CMemberFunc;
//	}
//private:
//	CMemberFuncType CMemberFunc;
//};
//
//
//
//C::C()
//{
//	CMemberFunc = &C::func;
//}
//
//int fun2(int a)
//{
//	std::cout << "inside fun2\n";
//	return 2;
//}
//
//
//
//typedef void (*VoidFnPtr)(void);
//typedef std::type_index TypeIndexInfo;
//typedef void* VoidPtr;
////typedef std::tuple<VoidPtr, TypeIndexInfo> TupleContainer;
//
//typedef std::map<VoidPtr, TypeIndexInfo> MyMapType;
//int main()
//{
//	//AMemberFunc p = &A::func;
//	B *pB = new B;
//	B::BMemberFuncType myBfptr = pB->getFptr();//&B::func;//
//	int sumB = (pB->*myBfptr)(3, 4);
//	delete pB;
//	pB = NULL;
//	std::cout << "SumB = " << sumB << std::endl;
//
//	A* pA = new A;
//	A::AMemberFuncType myAfptr = pA->getFptr();//&B::func;//
//	int sumA = (pA->*myAfptr)(5, 6, 7);
//	delete pA;
//	pA = NULL;
//	std::cout << "SumA = " << sumA << std::endl;
//
//	C* pC = new C;
//	C::CMemberFuncType myCfptr = pC->getFptr();//&B::func;//
//	int sumC = (pC->*myCfptr)(8);
//	delete pC;
//	pC = NULL;
//	std::cout << "SumC = " << sumC << std::endl;
//
//
//	// create a std::tuple.
//	//TupleContainer containerObj;
//	MyMapType mymap;
//	//
//	auto ttB = std::type_index(typeid(B*));
//	auto ttA = std::type_index(typeid(A*));
//	auto ttC = std::type_index(typeid(C*));
//	//VoidFnPtr BFnPtr = fun2;
//	/*vec.push_back(TupleContainer(static_cast<void*>(pB), ttB));
//	vec.push_back(TupleContainer(static_cast<void*>(pA), ttA));
//	vec.push_back(TupleContainer(static_cast<void*>(pC), ttC));*/
//
//	mymap.insert(std::make_pair(pB, ttB));
//	mymap.insert(std::make_pair(pA, ttA));
//	mymap.insert(std::make_pair(pC, ttC));
//
//	for (auto iter = begin(mymap); iter != end(mymap); ++iter)
//	{
//		//B* ptr = (B*)((*iter).first);
//		//ptr->func(3, 5);
//		//(B*)((*iter).first)
//
//	}
//
//	return 0;
//}

/********************************************************************************test 6- array of function pointers*******************************************************/

/********************************************************************************test 8- overloading new and delete operators**********************************************/

//#include<iostream>
//
//class One
//{
//public: 
//	One(int _i, int _j, char _a, char _a1)
//	{
//		i = _i;
//		j = _j;
//		a = _a;
//		a1 = _a1;
//	}
//
//	One(const One& orig)
//	{
//		i = orig.i;
//		j = orig.j;
//		a = orig.a;
//		a1 = orig.a1;
//	}
//
//private:
//	int i;
//	double j;
//	char a;
//	char a1;
//};
//void* operator new (size_t sz)
//{
//	void* ptr = (void*) malloc(sz);
//	return ptr;
//}
//
//template<typename T>
//void* operator new (size_t sz, T val)
//{
//	void* ptr = (void*)malloc(sz);
//	*((T)ptr) = val;
//	return ptr;
//}
//
//void* operator new[](size_t sz)
//{
//	void* ptr = (void*)malloc(sz);
//
//	return ptr;
//}
//void operator delete (void* ptr)
//{
//	free(&ptr);
//}
//
//int main()
//{
//	One o1(2, 3,  a ,  b );
//
//	One * p = new One (5,6, x ,  y );
//
//	int sz = sizeof(One);
//	std::cout << "Size of One: " << sz << std::endl;
//
//	int* pi = new int [1];
//
//	double* pd = new double[1];
//
//
//	return 0;
//}

/********************************************************************************test 8- overloading new and delete operators**********************************************/

/********************************************************************************test 9- finding the filename from pathname***********************************************/

///*
//This program finds the filename from the given fullname (pathname + filename).
//If user want to get result as filename with extension, then the macro FILENAME_WITH_EXTENSION
//should be enabled
//*/
//
//#include <iostream>
//
//#define FILENAME_WITH_EXTENSION
//
//int copy
//	(
//	const char* pSrc,
//	char** pDst,
//	const int start,
//	const int end
//	)
//{
//	if (NULL != *pDst)
//	{
//		delete[] *pDst;
//		*pDst = NULL;
//	}
//
//	int length = end - start + 1;
//	*pDst = new char[length]();
//	int ii = start;
//	int jj = 0;
//	for (; jj < length; ++ii, ++jj)
//	{
//		*(*pDst + jj) = *(pSrc + ii);
//	}
//	*(*pDst + jj) =  \0 ;
//	return length;
//}
//
//int GetFileName
//	(
//	const char* pSpec,
//	char** pName,
//	int& nMax
//	)
//{
//	//1) Search for  \  and  . . Update the position of  \  each time.
//	int pos_backslash = 0;
//	int pos_dot = 0;
//	int pathlength = 0;
//	int ii = 0;
//	while ( \0  != *(pSpec+ii))
//	{
//		if ( \\  == *(pSpec + ii))
//		{
//			pos_backslash = ii;
//		}
//		if ( .  == *(pSpec + ii))
//		{
//			pos_dot = ii;
//		}
//		++ii;
//	}
//
//	int end = pos_dot - 1;
//#ifdef FILENAME_WITH_EXTENSION
//	end = ii-1;
//#endif
//
//	if (0 != pos_dot)
//	{
//		nMax = copy(pSpec, pName, pos_backslash + 1, end);
//		return true;//valid file
//	}
//	else
//	{
//		return false;// invalid file, maybe directory passed
//	}
//}
//
//int main()
//{
//	const char* pFilename = "D:\\study\\MachineLearning\\ml-with-python\\codes\\training_1.py";
//	std::cout << "Input: " << pFilename << std::endl;
//	char* pName = NULL;
//	int size = 0;
//	if (true == GetFileName(pFilename, &pName, size))
//	{
//		std::cout << "GetFilename Successful \n ";
//		std::cout << "Filename: " << pName<<std::endl;
//		std::cout << "Length: " << size<<std::endl;
//	}
//	else
//	{
//		std::cout << "GetFilename Failed \n ";
//	}
//	if (NULL != pName)
//	{
//		delete[] pName;
//		pName = NULL;
//	}
//
//	return 0;
//}

/********************************************************************************test 9- finding the filename from pathname***********************************************/

/********************************************************************************test 10- swapping nibbles****************************************************************/
//#include<iostream>
//#include<string>
//
//unsigned char GETCHAR(unsigned char x)
//{
//	unsigned char ret; 
//	switch (x)
//	{
//	case 0:
//		ret = '0';
//		break;
//	case 1:
//		ret = '1';
//		break;
//	case 2:
//		ret = '2';
//		break;
//	case 3:
//		ret = '3';
//		break;
//	case 4:
//		ret = '4';
//		break;
//	case 5:
//		ret = '5';
//		break;
//	case 6:
//		ret = '6';
//		break;
//	case 7:
//		ret = '7';
//		break;
//	case 8:
//		ret = '8';
//		break;
//	case 9:
//		ret = '9';
//		break;
//	case 10:
//		ret = 'A';
//		break;
//	case 11:
//		ret = 'B';
//		break;
//	case 12:
//		ret = 'C';
//		break;
//	case 13:
//		ret = 'D';
//		break;
//	case 14:
//		ret = 'E';
//		break;
//	case 15:
//		ret = 'F';
//		break;
//	}
//	
//	return ret;
//}
//
//void swapNibbles
//	(
//	unsigned char* pData,
//	unsigned int lenInBytes,
//	unsigned int uiHt
//	)
//{
//	for (int ii = 0; ii < uiHt; ++ii)
//	{
//		for (int jj = 0; jj < lenInBytes; ++jj)
//		{
//			unsigned char byte = *(pData + ii*lenInBytes + jj);
//			byte = ((0xF0 & byte) >> 4) | ((0x0F & byte) << 4);
//			*(pData + ii*lenInBytes + jj) = byte;
//		}
//	}
//}
//
//void flipBytes
//	(
//	unsigned char* pData,
//	unsigned int lenInBytes,
//	unsigned int uiHt
//	)
//{
//	int mid = lenInBytes / 2;
//	for (int ii = 0; ii < uiHt; ++ii)
//	{
//		for (int jj = 0; jj < mid; ++jj)
//		{
//			unsigned char byte1 = *(pData + ii*lenInBytes + jj);
//
//			*(pData + ii*lenInBytes + jj) = 
//					*(pData + ii*lenInBytes + (lenInBytes - jj-1));
//
//			*(pData + ii*lenInBytes + (lenInBytes - jj-1)) = byte1;
//
//		}
//	}
//}
//
//void FlipImage
//	(
//	unsigned char* pData,
//	unsigned int uiWdt,
//	unsigned int uiHt
//	)
//{
//	int lenInBytes = uiWdt / 2;
//
//	swapNibbles(pData, lenInBytes, uiHt);
//	flipBytes(pData, lenInBytes, uiHt);
//}
//
//std::string gethex
//	(
//	unsigned char byte
//	)
//{
//	std::string str;
//	unsigned char n1 = ((0xF0 & byte)>>4);
//	unsigned char n2 = (0x0F & byte);
//	str.push_back(GETCHAR(n1));
//	str.push_back(GETCHAR(n2));
//	
//	/*if (n1 == 2)
//		str.push_back('2');
//
//	if (n2 == 3)
//		str.push_back('3');*/
//
//	return str;
//}
//
//int main()
//{
//	unsigned char pBitMapImg [] = 
//	{
//		 0x09 ,  0xA6 ,  0xBC ,  0x79 ,  0x76 ,  0x04 ,  0x31 ,  0x00 ,  0xFA ,  0x32 ,
//		 0xFF ,  0xFB ,  0x74 ,  0x46 ,  0x48 ,  0x29 ,  0xFC ,  0xAC ,  0xFE ,  0xEF ,
//		 0x01 ,  0x39 ,  0x45 ,  0xDE ,  0xCD ,  0xAD ,  0xEA ,  0xAF ,  0xDC ,  0x32 ,
//		 0xA3 ,  0x4D ,  0x59 ,  0x65 ,  0x49 ,  0x5F ,  0xA0 ,  0x34 ,  0x51 ,  0xF1 
//
//	};
//	int wdt = 20;
//	int ht = 4;
//
//	FlipImage(pBitMapImg, wdt, ht);
//
//	int lenInBytes = wdt / 2;
//	// print the flipped image
//	for (int ii = 0; ii < ht; ++ii)
//	{
//		for (int jj = 0; jj < lenInBytes; ++jj)
//		{
//			unsigned char byte1 = *(pBitMapImg + ii*lenInBytes + jj);
//			std::string hexStr = gethex(byte1);
//			std::cout << hexStr << " , ";
//		}
//		std::cout << std::endl;
//	}
//	
//
//	return 0;
//}

/********************************************************************************test 10- swapping nibbles****************************************************************/