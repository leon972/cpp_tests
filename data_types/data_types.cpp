/**********************************************************************************
 Code by Leonardo Berti (c) 2007
 tipi base - fundamental types
***********************************************************************************/

#include<iostream>

using namespace std;

//user defined types
typedef struct {
    int id; //4 bytes
    char* name; //4 bytes
    char* address; //4 bytes

}
USER_RECORD,*USER_RECORD_PTR;

enum my_enum {

    red,green,blue,white,magenta,orange
};

class CRecord {
private:

    int _id;
    char* _name;

public:

    CRecord(char* name,int id) {
        _name=name;
        _id=id;
    }

    void print() {
        cout<<"ID="<<_id<<" name="<<_name<<endl;
    }
};

/**Tipi boolean*/
void test_bool(bool bx) {
    cout<<"test_bool"<<endl;
    //stampa 1 se bx ? true false altrimenti
    cout<<"Il valore ? "<<bx<<endl;

    //gli interi diversi da zero sono convertiti in true
    //gli interi uguali a zero sono convertiti in false

    int g=9;
    bool b1=g;
    int g1=0;

    cout<<"(bool)"<<g<<"="<<(bool)g<<endl;
    cout<<"(bool)"<<g1<<"="<<(bool)g1<<endl;

    //il valore boolean true ? convertito nell'intero 1 e false in zero
    int g2=(9==9);

    cout<<"(9==9)"<<g2<<endl;

    bool a=true;
    bool b=true;
    bool x=a+b; //a+b=2 cosi' x ? true

    cout<<a<<"+"<<b<<"="<<x<<endl;

    //un puntatore puo' essere convertito implicitamente in un boolean:
    //un nonzero pointer ? convertito in true e un puntatore con valore zero in false

    int* pa=0;
    int* pb=&g2;

    cout<<"(bool)*pa="<<(bool)pa<<endl; //stampa 0 perch? punta a null
    cout<<"(bool)*pb="<<(bool)pb<<endl; //stampa 1
}

/**Tipi char*/
void test_char() {
    cout<<"test char:"<<endl;
    //nota: un char ? costituito da 8 bit e quindi puo' contenere 256 valori differenti
    //il charset usato di una macchina ? tipicamente una variante dello standard ISO 646 (ad esempio il charset ASCII)
    //? possibile assumere che ogni charset comprende i valori decimali (0,1,...9) le 26 lettere
    //dell'alfabeto e i segni di punteggiatura decimale
    //i caratteri extra sono specifici dell'implementazione

    char ch='?';

    cout<<"ch="<<ch<<endl; //stampa un numero negativo

    //i 256 valori del tipo char possono essere interpretati sia come
    //interi da -127 a +127 che come interi da 0 a 255 questo dipende dall'implementazione

    unsigned char uch='?'; //se si usa unsigned char il valore convertito in int ? compreso fra 0 e 255

    cout<<"(int)ch="<<(int)ch<<endl;

    cout<<"(unsigned char) uch="<<(int)uch<<endl;

    char ch2=65;

    //stampa A
    cout<<"ch2="<<ch2<<endl;

    char a='a';
    char b='b';
    int s=a+b;

    cout<<"(int)"<<a<<"+"<<b<<"="<<s<<endl;

    //caratteri di escape
    char c1='\n'; //new line
    char c2='\f'; //form feed
    char c3='\t'; //tab;
    char c4='\v'; //vertical tab
    char c5='\b'; //back space
    char c6='\r'; //return
    char c7='\a'; //alert
    char c8='\\'; //back slash
    char c9='\?'; //question mark;
    char c10='\''; //single quote
    char c11='\"'; //double quote
    char c12='\x35'; //esadecimale
    char c13='\o23'; //ottale

    cout<<'|'<<c3<<'|'<<c3<<'|'<<endl;
    cout<<'|'<<c3<<'|'<<c3<<'|'<<endl;

    cout<<c7<<endl;
    //unicode
    cout<<'\u1e2b'<<endl;
    wchar_t wc= L'A'; //stampa 65 sulla console
    cout<<wc;
}

void test_int() {
    cout<<"test_int"<<endl;
    short s=-646;
    unsigned short us=9584;
    int i=-1; //int si intende sempre signed (? lo stesso di signed int)

    long l=-9348948L; //signed long litteral
    unsigned long ul=9384842UL; //usniged long literal
    long long ull=3948892383UL; //lungo esteso

    cout<<"ul="<<ul<<endl;

    //esadecimale
    int i1=0xFFFFFFFF; //nota: se l'implementazione usa int a 32 bit questo rappresenta -1 (numeri complemento a due)

    cout<<"i1="<<i1<<endl;
}

void sizes() {
    //nota bene: l'operatore sizeof resituisce le dimensioni
    //in base alle dimensioni del tipo char se sizeof(tipo)=N
    //significa che 'tipo' ha dimensioni pari a N volte le dimensioni di un char
    //per definizione sizeof(char)=1

    cout<<endl<<"dimensioni in multipli di sizeof(char):"<<endl;
    cout<<"sizeof(bool)="<<sizeof(bool)<<endl;
    cout<<"sizeof(char)="<<sizeof(char)<<endl;
    cout<<"sizeof(short)="<<sizeof(short)<<endl;
    cout<<"sizeof(int)="<<sizeof(int)<<endl;
    cout<<"sizeof(long)="<<sizeof(long)<<endl;
    cout<<"sizeof(long long)="<<sizeof(long long)<<endl;
    cout<<"sizeof(float)="<<sizeof(float)<<endl;
    cout<<"sizeof(double)="<<sizeof(double)<<endl;
    cout<<"sizeof(long double)="<<sizeof(long double)<<endl<<endl;

    char* p=0;

    cout<<"sizeof(*char)="<<sizeof(p)*8<<endl;

    char v[]="123456789"; //sizeof=10
    char* s="123456789"; //sizeof=4
    int iv[]={1,2,3,4,5,6,7,8,9}; //sizeof=36   (9x4)
    int v1[4]; //sizeof=16  (4x4)

    //restituisce 10 (conta anche lo zero terminatore)
    cout<<"sizeof(v[])="<<sizeof(v)<<endl;
    //restituisce 4 (bytes)
    cout<<"sizeof(s)="<<sizeof(s)<<endl;
    //restituisce 36 (9 elementi di 4 byte)
    cout<<"sizeof(iv)="<<sizeof(iv)<<endl;

    my_enum en=red;
    //restisuisce 4 (bytes)
    cout<<"sizeof(my_enum)="<<sizeof(my_enum)<<endl;
    //restituisce 4 (tratta gli enum come int)
    cout<<"sizeof(en)="<<sizeof(en)<<endl;
    cout<<"sizeof(USER_RECORD)="<<sizeof(USER_RECORD)<<endl;
    cout<<"sizeof(v1)="<<sizeof(v1)<<endl; //16

    //per ogni implementazione quello che si puo' sempre assumere ?:
    //sizeof(char)=1 (per definizione)
    //1<=sizeof(char)<=sizeof(short)<=sizeof(int)<=sizeof(long)
    //1<=sizeof(bool)<=sizeof(long)
    //sizeof(float)<=sizeof(double)<=sizeof(long double)
    //sizeof(N)=sizeof(signed N)=sizeof(unsigned N) (N=tipo aritmetico)

}

int main(void) {
    //built-in types:
    //arithmetic types
    //integral types
    short s=9;     //intero corto
    int a=0;       //intero
    long l=7372983; //intero lungo
    bool b=true;   //booleano
    char ch='A';   //carattere
    //floating point types
    float f=3.1415f;
    double g=9.81;


    //user defined types
    USER_RECORD rec;
    USER_RECORD_PTR p=&rec;

    rec.id=0;
    rec.name="item zero";
    rec.address="93849348";

    my_enum m=red;

    CRecord r("My record",10);

    r.print();

    test_bool(b);
    test_int();
    test_char();

    sizes();

    return 0;
}


