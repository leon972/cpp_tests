/**********************************************************************************
 Code by Leonardo Berti (c) 2006
 Esempio di classe stack implementata con una classe
 main.cpp:utilizza lo stack

***********************************************************************************/

#include <iostream>
#include "stack3.h"

using namespace std;
using namespace ClassStack;

int main(void)
{
	const int size=0xFF;

	try
	{
        Stack s1(size);

        cout<<"Riempie lo stack con tutti i caratteri ASCII:\n";

        for (int i=0;i<size;i++) s1.push(i);

        cout<<"Contenuto dello stack:\n";

        for (int i=0;i<size;i++) cout<<size-i-1<<":"<<s1.pop()<<"\n";

        //la memoria di s1 viene deallocata automaticamente

	}
	catch (Stack::Overflow o)
	{
	    cout<<"Eccezione:overflow";
	}
	catch (Stack::Underflow u)
	{
	    cout<<"Eccezione:underflow";
	}
	catch (Stack::BadSize bs)
	{
	    cout<<"Eccezione:bad size";
	}

	return 0; //programma terminato con successo
}

