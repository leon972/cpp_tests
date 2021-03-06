/**********************************************************************************
 Code by Leonardo Berti (c) 2006
 Esempio di classe stack
 main.cpp: utilizza lo stack con la gestione delle eccezioni
 -modular paradigm-
***********************************************************************************/

#include <iostream>
#include "stack2.h"

//utilizza lo spazio di nomi std (per usare cin e cout)
using namespace std;

int main(void)
{
	char c;
	char ans='y';
	int cnt=0;

	try
	{
		while (ans=='y' || ans=='Y')
		{

			cout<<"Immettere il carattere n\xf8"<<++cnt<<":\n";

			cin>>c;

			Stack::push(c);

			cout<<"Continuare (y/n)?\n";

			cin>>ans;

		}
	}
	catch (Stack::Overflow)
	{
		cout<<"Errore: lo stack \x8a pieno!\n";
	}

	try
	{
		cout<<"Contenuto dello stack:\n";

		//visualizza il contenuto dello stack
		while (true)
		{
			cout<<Stack::pop()<<"\n";
		}
	}
	catch (Stack::Underflow) {}

	return 0;
}
