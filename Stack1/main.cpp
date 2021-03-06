/**********************************************************************************
 Code by Leonardo Berti (c) 2006
 Esempio di classe stack
 main.cpp: utilizza lo stack definito in stack1.h
 -modular paradigm-
***********************************************************************************/

#include <iostream>
//include l'interfaccia stack
#include "stack1.h"

//usa lo spazio di nomi std (cin e cout)
using namespace std;

/** program entry point*/
int main(void)
{

	char ans;

	cout<<"Inserire il carattere da immettere nello stack:\n";
    //chiede di inserire un carattere
	cin>>ans;

	Stack::push(ans);

	cout<<"Inserire il secondo carattere da immettere nello stack:\n";
    //chiede di inserire un carattere
	cin>>ans;

	Stack::push(ans);

	//nota \x8a è il carattere ascii 8a cioè "è"
	cout<<"Lo stack contiene "<<Stack::pop()<<" e "<<Stack::pop()<<"\n";

}

