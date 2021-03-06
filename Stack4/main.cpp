/**********************************************************************************
 Code by Leonardo Berti (c) 2006
 Esempio di classe stack implementata con una classe che utilizza i tipi generici
main
 -concrete types-
***********************************************************************************/


#include <iostream>
#include "stack4.h"
#include "stack4.cpp"

using namespace ClassStack;

class MyClass
{
private:

	int a,b;
	char ch;

public:

	MyClass(int a,int b,char ch)
	{
		this->a=a;
		this->b=b;
		this->ch=ch;
	}

	void display(void)
	{
		std::cout<<a<<b<<ch<<"\n";
	}

};

int main(void)
{
	//crea due stack che utilizzano un tipo diverso

	Stack<char> chStack(10); //stack di caratteri
	Stack<int> intStack(10); //stack di interi
	Stack<MyClass> myStack(10); //stack di oggetti personalizzati

	MyClass obj1(1,2,'a'),obj2(3,4,'c');

	myStack.push(obj1);
	myStack.push(obj2);

	std::cout<<"Estrae gli ogetti dagli stack:\n";
	//estrae gli ogetti immessi
	myStack.pop().display();
	myStack.pop().display();

	std::cout<<"Stack di char:\n";

	chStack.push('a');
	chStack.push('b');

	try
	{
		std::cout<<"Svuota lo stack di char e visualizza il contenuto:";
		while(true)
		std::cout<<chStack.pop()<<"\n";

	}
	catch (Stack<char>::Underflow)
	{
		//stack vuoto
	}

	std::cout<<"Stack di int:\n";


	intStack.push(1);
	intStack.push(1);

	return 0;
}

