/************************************************************************
  Code by L.Berti (c) 2006
  tipo complex (numero complesso) personalizzato
*************************************************************************/

namespace custom_complex
{

/**
Numero complesso.
Permette di svolgere le operazioni base sui numeri complessi.
*/

class complex
{
private:
	double re,im; /*!<parte reale e parte immaginaria*/
public:

	/**
	Eccezione divisione per zero
	*/
	class DivisionByZero{}; //divizione per zero

	/**
	Crea un numero complesso specificando la parte reale e quella immaginaria
	@param r parte reale
	@param i parte immaginaria
	*/
	complex(double r,double i);
	complex(double r);
	complex();

    //nota: alcuni membri sono dichiarati friend perchè nell'implementazione
	//si deve accedere ai membri prvati re e im degli operandi

	//somma
	friend complex operator+(complex,complex);
	/**differenza
        */
	friend complex operator-(complex,complex);
	/**prodotto*/
	friend complex operator*(complex,complex);
	/**quoziente*/
	friend complex operator/(complex,complex);
        /**uguaglianza*/
	friend bool operator==(complex,complex);
	/**operatore diverso da*/
	friend bool operator!=(complex,complex);
	/**logaritmo naturale*/
	complex ln();
	/**esponenziale e^z*/
	complex expn();
	/**parte reale*/
	double Re();
	/**parte immaginaria*/
	double Im();
	//meno unario (opposto)
	friend complex operator -(complex);
	//coniugato (il coniugato di a+ib è a-ib)
	complex coniug();
	/**calcola l'inverso*/
	complex inv();
	/**modulo*/
	double mod();
	/**argomento (è l'angolo quando è espresso in forma trigonometrica r(cos(t)+isen(t))*/
	double arg();
	/**potenza*/
	friend complex operator^(complex,double);

};

}

