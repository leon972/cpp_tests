/*
    Code by Leonardo Berti (c) 2007

	HelloWorld in standard C++,

    per compilare con gcc:

    mingw32-g++.exe -O1 hello.cpp -o hello.exe

    O1 indica di ottimizzare e -o hello.exe indica di inviare l'output sul file hello.exe

    per produrre il sorgente assembly usare

    mingw32-g++.exe -S hello.cpp
    questo tradurrà da c++ ad assembly nel file hello.s

    per produrre informazioni di debug usare l'opzione -g


*/


#include <iostream>

using namespace std;

int main (void)
{
	cout<<"Hello from standard C++!"<<endl;

	return 0;

}
