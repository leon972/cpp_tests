/**********************************************************************************
 Code by Leonardo Berti (c) 2006
 Esempio di classe stack
 stack2.h: contiene l'interfaccia utente dello stack, l'implementazione è in stack2.cpp
 il file utilizzatore dello stack dovrà includere solo stack2.h (interfaccia)
 utilizza l'exception handling per la gestione dell'overflow e underflow
 -modular paradigm-
***********************************************************************************/

namespace Stack
{
	void push(char);
	char pop();

	class Overflow {}; //utilizzata per la gestione della eccezione overflow
	class Underflow {}; //utilizzata per gestire l'underflow

}