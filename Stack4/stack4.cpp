/**********************************************************************************
 Code by Leonardo Berti (c) 2006
 Esempio di classe stack implementata con una classe che utilizza i tipi generici
 stack4.cpp
 -concrete types-
***********************************************************************************/


#include "stack4.h"

namespace ClassStack
{
	template<class T> Stack<T>::Stack(int size)
	{
		//genera una eccezione se la dimensione non è corretta
		if (size<=0) throw BadSize();

		maxsize=size;
		top=0;

		v=new T[maxsize];
	}

	template <class T> Stack<T>::~Stack()
	{
		delete[] v;
	}

	template<class T> void Stack<T>::push(T c)
	{
		//lo stack è pieno
		if (top==maxsize) throw Overflow();

		v[top++]=c;

	}

	template<class T> T Stack<T>::pop()
	{
		if (top==0) throw Underflow(); //stack vuoto:impossibile compiere l'operazione

		return v[--top];
	}
}

