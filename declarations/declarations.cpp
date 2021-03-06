/**********************************************************************************
 Code by Leonardo Berti (c) 2007
 Dichiarazioni,definizioni,literals ecc...
***********************************************************************************/

#include <iostream>
#include <string>
#include <complex>

using namespace std;

//INTEGER LITERALS
int ia=636727;
//L postfisso serve a specificare esplicitamente un valore long
//U postfisso serve a specificare un valore unsigned
long int ib=100000L; //long
unsigned int ui=65535U; //unsigned
int h=0x3fd; //valore esadecimale
int v1=056; //valore ottale (zero seguito da una sequenza numerica)
//FLOATING POINT LITERALS
float f=5.6f; //f (o F)postfisso definisce un valore float
long double d=0.00089L; //L (o l)  postfisso definisce un long double
float t=1.2e6f; //1.2 x 10 alla 6
float t1=1.2e-6;
//CHAR LITERALS
char ch='a';
char A=65;
wchar_t aa=L'a'; //definisce un carattere esteso, (il significato L'ab' dipende dall'implementazione)
//BOOLEAN
bool b1=true;
bool b2=false;
//ENUMERATIONS
//per default ad ogni enumeratore viene assegnato un valore a partire da zero
//il range dell'enumeratore è compreso fra 0 e (2^k)-1 dove k è la piu'
//piccola potenza di due necessaria contenere tutti gli elementi
enum keywords {ASM,AUTO,BREAK};
enum myenum {red=0,green=8,blue=12}; //il range è compreso fra 0 e 2^4-1=15
enum myenum2 {sos=-3,sys=4,try1=1020}; //il range è compreso -2^10 e 2^10-1

myenum m1=myenum(5); //ok perchè 5 è compreso nel range
//myenum m2=5; errore: invalid conversione from 'int' to 'myenum'

//DICHIARAZIONI:
//una dichiarazione consiste in 4 parti:
//-uno specificatore (specifier) opzionale es. extern, virtual (non type attribute)
//-un tipo base (base type)
//-un dichiaratore (declarator)
//-un inizializzatore (opzionale)

//ogni dichiarazione che specifica un valore è una definizione

char* names[]={"Mario","Gustavo","Alfredo"}; //char=tipo base *names dichiaratore {...} inizializzatore

//dichiarazioni che sono anche definizioni:

char ch1; //associa a ch la quatità di memoria necessari a contenere un char
string s;
int count=1; //inizializza a 1
const double pi=3.1415926535897932385;
const char *name="Pluto";
const char* season[]={"winter","spring","summer","fall"};
struct Date {int d,m,y;};
int day(Date*p){return p->d;}
template <class T> T abs(T value) {return value<0 ? -value:value;}
namespace NS {int ai=9;} //definisce un namespace

//dichiarazioni che NON sono definizioni

struct User; //lo struct deve essere definito da qualche altra parte
double sqrt(double num); //dichiara una funzione senza definirla: la definizione deve essere fatta da qualche altra parte
extern int ei; //la memoria allocata per ei è definita in un altro modulo
typedef complex<short> Point;


int main(void)
{
    char ch1='L'; //ch1 locale
    ::ch1='G'; //ch1 globale

    cout<<"ch1="<<ch1<<endl; //ch1 locale
    cout<<"ch1="<<::ch1<<endl; //ch1 globale

    {
        cout<<"ch1="<<ch1<<endl; //ch1 locale

        char ch1='I'; //ch1 interno

        cout<<"ch1="<<ch1<<endl;
    }

    return 0;
}
