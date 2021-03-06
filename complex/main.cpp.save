/************************************************************************
  Code by L.Berti (c) 2006
  tipo complex (numero complesso) personalizzato
  Chiede all'utente di inserire due numeri complessi nella forma a+ib (o a-ib)
  ed esegue alcune operazioni.
  Vengono definiti anche gli operatori << e >> per l'output e l'acquisizione
  dei numeri da parte dell'utente.
*************************************************************************/

#include <iostream>
#include "complex.h"

using namespace std; //contiene cout e cin
using namespace custom_complex;

complex getComplex()
{
	double r,i;

	cout<<"Inserire la parte reale (re):\n";
	cin>>r;
	cout<<"Inserire la parte immaginaria (im):\n";
	cin>>i;

	return complex(r,i);

}
//definisce l'uperatore >> per acquisire il numero complesso da parte dell'utente
//il numero complesso è valido se viene inserito nella forma a+ib (o a-ib)
istream& operator>>(istream& s,custom_complex::complex& c)
{
	double r,i;
    char ch;
	double mul=1.0;

	//acquisisce la parte reale
	s>>r;

	s>>ch;

	if (ch=='+' || ch=='-')
	{
		if (ch=='-') mul=-mul; //il numero è inserito nella forma a-ib

		s>>ch;
		if (ch=='i' || ch=='j')
		{
			//acquisisce la parte immaginaria
			s>>i;

			i*=mul;
		}
	}

	if (s) c=complex(r,i);

	return s;
}

//definisce l'operatore personalizzato << per il tipo complex definito dall'utente
//serve a visualizzare il numero complesso

ostream& operator<<(ostream& s,complex c)
{
	double r,i;

	r=c.Re();
	i=c.Im();

	char sg;

	if (i<0)
	{
		//a-ib
		i=-i;
		sg='-';
	}
	else
	{
		//a+ib
		sg='+';
	}

	return s<<"("<<r<<" "<<sg<<" i"<<i<<")";
}

int main(void)
{
	try
	{
		cout<<"Numeri complessi\nInserire il primo numero (formato a+ib):\n";

		complex c1,c2;
        //nota: utilizza l'operatore >> personalizzato per il tipo complex
		cin>>c1;

		cout<<"Inserire il secondo numero (formato a+ib):\n";

		cin>>c2;

		cout<<"I numeri inseriti sono:"<<c1<<" e "<<c2;

		complex c3=c1+c2;

		cout<<"\n"<<c1<<"+"<<c2<<"="<<c3<<"\n";

		c3=c1/c2;

		cout<<"\n"<<c1<<"/"<<c2<<"="<<c3<<"\n";

		cout<<"\nmodulo di"<<c1<<"="<<c1.mod()<<"\n";

		cout<<"\nmodulo di"<<c2<<"="<<c2.mod()<<"\n";

		cout<<"\nargomento di"<<c1<<"="<<c1.arg()<<" radianti\n";

		cout<<"\nargomento di"<<c2<<"="<<c2.arg()<<" radianti\n";

		cout<<"\n e^"<<c1<<"="<<c1.expn()<<"\n";

	}
	catch (complex::DivisionByZero)
	{
		cout<<"Errore:operazione non valida, divisione per zero!";
	}

	char c;

	std::cin>>c;

	return 0;
}
