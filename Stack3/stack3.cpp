/**********************************************************************************
 Code by Leonardo Berti (c) 2006
 Esempio di classe stack implementata con una classe
 stack3.cpp:implementazione
 -concrete types-
***********************************************************************************/

#include "stack3.h"

namespace ClassStack
{
	Stack::Stack(int size)
	{
		//genera una eccezione se la dimensione non è corretta
		if (size<=0) throw BadSize();

		maxsize=size;
		top=0;

		v=new char[maxsize];
	}

	Stack::~Stack()
	{
		//dealloca la memoria
		delete[] v;
	}

	void Stack::push(char c)
	{
		//lo stack è pieno
		if (top==maxsize) throw Overflow();

		v[top++]=c;
	}

	char Stack::pop()
	{
		if (top==0) throw Underflow(); //stack vuoto:impossibile compiere l'operazione

		return v[--top];
	}
}
