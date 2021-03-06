/************************************************************************
  Code by L.Berti (c) 2006
  tipo complex (numero complesso) personalizzato
*************************************************************************/

#include <math.h>
#include "complex.h"

namespace custom_complex
{

	/**
          costruttore.cpp
        */
	complex::complex(double r,double i)
	{
		re=r;
		im=i;
	}

        /**
        crea un numero complesso specificando la parte reale
        */
	complex::complex(double r)
	{
		re=r;
		im=0;
	}

	complex::complex()
	{
		re=im=0;
	}

	complex operator+(complex c1,complex c2)
	{
		return complex(c1.re+c2.re,c1.im+c2.im);
	}

	complex operator-(complex c1,complex c2)
	{
		return complex(c1.re-c2.re,c1.im-c2.im);
	}

	complex operator*(complex c1,complex c2)
	{
		return complex(c1.re*c2.re-c1.im*c2.im,c1.re*c2.im+c1.im*c2.re);
	}

	complex operator/(complex c1,complex c2)
	{
        //moltiplica per l'inverso
		return c1*c2.inv();
	}

	/** inverso*/
	complex complex::inv()
	{
		double m=mod();
		m*=m;

		if (m==0) throw DivisionByZero();

		return complex(re/m,-im/m);
	}

	/** modulo*/
	double complex::mod()
	{
		return sqrt(re*re+im*im);
	}

	bool operator==(complex c1,complex c2)
	{
		return ((c1.re==c2.re) && (c1.im==c2.im));
	}

	bool operator!=(complex c1,complex c2)
	{
		return (!((c1.re==c2.re) && (c1.im==c2.im)));
	}

	double complex::Re()
	{
		return re;
	}

	double complex::Im()
	{
		return im;
	}

	//coniugato
	complex complex::coniug()
	{
		return complex(re,-im);
	}

	//restituisce l'angolo in radianti
	double complex::arg()
	{
		double m=mod();
        //se il modulo è zero l'angono non è definito
		if (m==0) throw DivisionByZero();

		return asin(im/m);
	}

	//potenza
	complex operator^(complex c,double n)
	{
		double m=c.mod();
		double t=c.arg();

		m=pow(m,n);
		t=t*n;

		return complex(m*cos(t),m*sin(t));

	}

	//logaritmo
	complex complex::ln()
	{
		double m=mod();

		return complex(log(m),arg());
	}

	//esponenziale e^z = e^a(cos(b)+isen(b))
	complex complex::expn()
	{
		double e1=exp(Re());
		double r=e1*cos(Im());
		double i=e1*sin(Im());
		return complex(r,i);
	}
}
