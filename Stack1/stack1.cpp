/**********************************************************************************
 Code by Leonardo Berti (c) 2006
 Esempio di classe stack
 stack1.cpp: implementa lo stack definito in stack1.h
 nel pradigma di programmazione a moduli, l'utilizzatore dello stack deve
 riferirsi solo a stack1.h senza preoccuparsi di come è stato implementato
 -modular paradigm-
***********************************************************************************/

#include "stack1.h"

namespace Stack
{
	const int max_len=10;
	char s[max_len];
	int top=0;

	/** immette un carattere in cima allo stack */
	void push(char c)
	{
		if (top<max_len) s[top++]=c;
	}

	char pop()
	{
		if (top>0) return s[--top];
		else return 0;
	}
}



