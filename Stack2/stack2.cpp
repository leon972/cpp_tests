/**********************************************************************************
 Code by Leonardo Berti (c) 2006
 Esempio di classe stack
 stack2.cpp: contiene l'interfaccia utente dello stack, l'implementazione è in stack2.cpp
 il file utilizzatore dello stack dovrà includere solo stack2.h (interfaccia)
 utilizza l'exception handling per la gestione dell'overflow e underflow
 -modular paradigm-
***********************************************************************************/

#include "stack2.h"

namespace Stack
{
	const int max_len=10;
	char s[max_len];
	int top=0;

	/** immette un carattere in cima allo stack */
	void push(char c)
	{
		if (top<max_len) s[top++]=c;
		else throw Overflow();
	}

	char pop()
	{
		if (top==0) throw Underflow(); //non ci sono elementi nello stack
		else return s[--top];
	}

}
