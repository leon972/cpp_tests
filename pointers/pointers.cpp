/**********************************************************************************
 Code by Leonardo Berti (c) 2007
 Puntatori,array e strutture
***********************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

//questa accetta un puntatore a caratteri on un array di char
void prnt_array(char* ar)
{
    cout<<ar<<endl;
}

//questa funzione acccetta come argomento un array di interi con 5 elementi
void prn_int_array(int ar[5])
{
    for (int i=0;i<5;++i)
    {
        cout<<ar[i]<<",";
    }
    cout<<endl;
}

//passaggio di un array specificando le dimensioni
void prn_int_array2(int ar[],int asize)
{
    for (int i=0;i<asize;++i)
    {
        cout<<ar[i]<<",";
    }
    cout<<endl;
}


//questa equivale alla precendente
void prn_int_array3(int* ar,int asize)
{
    for (int i=0;i<asize;++i)
    {
        cout<<ar[i]<<",";
    }
    cout<<endl;
}

//passaggio di array multi dimensionali
void prn_mat34(int m[3][4])
{
    cout<<"Matrice 3x4:"<<endl;
    for (int i=0;i<3;++i)
    {
        for (int j=0;j<4;++j)
        {
            cout<<m[i][j]<<",";
        }
        cout<<endl;
    }
}

//la prima dimensione puo' non essere specificata per non serve per determinare
//la posizione di un elemento
//questa funzione puo' stampare qualsiasi matrice con 4 colonne

void prn_mati4(int m[][4],int dim1)
{
    cout<<"Matrice "<<dim1<<"x4:"<<endl;

    for (int i=0;i<dim1;++i)
    {
        for (int j=0;j<4;++j)
        {
            cout<<m[i][j]<<",";
        }
        cout<<endl;
    }
}

//matrice con dimensioni indefinite
void prn_matij(int* m,int dim1,int dim2)
{
    cout<<"Matrice "<<dim1<<"x"<<dim2<<endl;

    for (int i=0;i<dim1;++i)
    {
        for (int j=0;j<dim2;++j)
        {
            cout<<m[i*dim2+j]<<","; //attenzione!
        }
        cout<<endl;
    }
}

//passaggio di valori costanti
void g(const char* p)
{
    cout<<*p<<endl;

    //*p='p'; errore non si puo' cambiare il valore puntato
}

void try_const(char* p)
{
    char s[]="hello!";

    //puntatore a una stringa costante
    const char* ps=s;
    //ps[0]='p'; errore perchè ps punta a una stringa costante
    ps=p; //ok

    //puntatore costante (a una stringa non costante)
    //il dichiaratore che rende un puntatore costante è *const
    char *const pc=s;
    pc[0]='p'; //ok
    //pc=p; errore perchè pc è un puntatore costante e non puo' essere riassegnato

    //puntatore costante a stringa costante

    const char *const pcc=s;
    //pcc[0]='p'; //errore
    //pcc=p; //errore non puo' essere riassengato
}

//funzione che restituisce una string literal
//una string literal è allocata staticamente quindi puo' essere restituita da una funzione
char* error_msg(int e)
{
    switch (e)
    {
        case 0:
        return "no error";
        break;
        case 1:
        return "I/O error";
        break;
        case 3:
        return "Error 3";
        default:
        return "unknown error";
    }
}

//referenze usate come argomenti
//il valore di c viene incrementato
//nota: se la funzione deve modificare il valore allora è meglio passare un puntatore invece
//di un reference perchè il codice è piu' leggibile
//è conveniente usare un reference come argomento quando l'argomento è costante e non viene modificato
void incr(int& c)
{
    c++;
}

struct my_data
{
    char c;
    int val;

};

void prn_data(const my_data& d)
{
    cout<<d.c<<d.val<<endl;
    //d.val=0; errore perchè la struttura è read only
}

int var1=1,var2=2,var3=3;

int& choose_var(int i)
{
    switch (i)
    {
        case 1:
        return var1;
        break;
        case 2:
        return var2;
        case 3:
        return var3;
        default:
        return var1;
    }
}

//viene passato un reference di un char*
void allocate_mem_ref(char*& buffer,int size)
{
    buffer=new char[size];
}

//oppure
void allocate_mem_pptr(char** buffer,int size)
{
    *buffer=new char[size];
}

int main(void) {

#ifndef NULL
    //definizione di NULL (è costante per evitare ridefinizioni involontarie)
    const int NULL=0;
#endif

    //PUNTATORI
    char c='a';
    char* p=&c; //p contiene l'indirizzo di c
    int *pi; //puntatore a interi (pointer to int)
    char** ppc; //puntatore a puntatore a caratteri
    int *ap[15]; //array di 15 puntatori a interi
    int (*fptr)(char*); //puntatore a una funzione che restituisce un int e ha com argomento un char
    int* f(char* arg); //funzione che ha come argomento un puntatore a char e restituisce un puntatore a int

    char*text=0;

    text=new char[8];

    const char* s1="ppp";

    memcpy(text,s1,3);

    delete[] text;

    text=new char[4];

    delete[] text;

    //l'operazione fondamentale con un puntatore è
    //la dereferenziazione (indirection)
    //cioè ottenere il valore puntato
    cout<<"c="<<c<<" *p="<<*p<<endl;

    //null pointer:puntatore nullo
    //nessun oggetto puo' avere come indirizzo zero
    //quindi assegnare zero a un puntatore significa che il puntatore
    //non si riferisce a nessun oggetto
    //puntatore nullo
    int* ptr_i=0;
    char* s=NULL;
    float v[3]; //v è di tipo array float di 3 elementi
    //stampa 12 (3*sizeof(float))
    cout<<"sizeof(v)="<<sizeof(v)<<endl;
    char* a[10];
    //stampa 40 (un puntatore contiene un indirizzo di memroia, su sistemi a 32 bit è costituito da 4 byte )
    cout<<"sizeof(a)="<<sizeof(a)<<endl;
    //stampa 4
    cout<<"sizeof(a[1])="<<sizeof(a[1])<<endl;
    //la dimensione di un array deve essere una espressione costante
    const int msize=3;
    int msize2=9;
    int y[msize]; //ok
    int y2[msize2]; //ok

    //array multidimensionali
    int ad[5][6]; //ad è un array di 5 array di 6 interi
    //stampa 120 4*5*6
    cout<<sizeof(ad)<<endl;

    //INIZIALIZZAZIONE
    //inizializzatori di array (array initializers)
    int v2[]={1,2,3,4}; //la dimensione viene determinata automaticamente
    //stampa 16
    cout<<sizeof(v2)<<endl;
    char v3[]={'a','b','c','d'};
    //in questo caso viene assunto atomaticamente il valore zero per gli elementi non inizializzati
    int v4[8]={1,2,3,4};
    //un array di caratteri inizializzato con una string literal
    char str[]="Salve gente!";

    //PASSAGGIO DI ARRAY COME ARGOMENTI
    //viene passato l'array alla funzione
    prnt_array(str);
    //passaggio di un array a una funzione
    int u[5]={1,2,3,4,5};
    //l'array viene passato come puntatore
    prn_int_array(u);
    prn_int_array(v4);
    prn_int_array2(v4,4);

    //un array di 3 array di 4 int (matrice 3 righe x 4 colonne)
    int am[3][4]={ {1,2,3,4},{11,12,13,14},{21,22,23,24}};

    prn_mat34(am);
    prn_mati4(am,3);
    prn_matij(&am[0][0],3,4); //nota prn_matij(am,3,4); causa un errore perchè am è di tipo int (*)[4] e non int*

    //STRING LITERALS
    //una string literal è una stringa racchiusa tra apici
    //"prova" è di tipo const char[6] (una string literals è sempre seguita da zero \0 automaticamente)
    //per ragioni di compatibilità con il C una string literal puo' essere assegnata a un char*

    //ok in questo caso pero' msg non si puo' usare il puntatore msg per modificare
    //la stringa che è costante
    char* msg="Warning!";
    //msg[2]='p'; dovrebbe essere illegale
    //per avere una stringa modificabile si deve copiare in un array di caratteri
    char t[]="Modificabile";
    msg=t; //ok conversione implicita da char[] a char*
    //t=msg; errore conversione da char* a char[] non consentita

    t[0]='J';
    //due stringhe costanti potrebbero essere memorizzate allo stesso indirizzo
    const char* p1="a string";
    const char* q1="a string";
    //il risultato dipende dall'implementazione , il confronto è fatto fra i puntatori e non fra le stringhe
    cout<<"p1==q1:"<<(p1==q1)<<endl; //stampa 1 (true)

    //inizializzazione di stringhe lunghe (possono essere spezzate)
    //la stringa risultate è data dalla concatenazione di tutte le stringhe
    char my_msg[]="AAAAAAAAAAAAAA"
                  "BBBBBBBBBBBBBB"
                  "CCCCCCCCCCCCCC"
                  "DDDDDDDDDDDDDD"
                  "EEEEEEEEEEEEEE";

    //COSTANTI
    const int t3=9; //t non puo' essere modificato
    //const int y6; errore costante non inizializzata
    const int vx[4]={1,2,3,4}; //v[i] è costante
    //vx[2]=6; errore perchè vx[i] è costante
    //REFERENCES
    int ai=1;
    int& e=ai; //un nome alternativo per ai
    e++; // è la stessa cosa di ai++
    cout<<"ai="<<ai<<endl;
    const int& e1=ai;
    //e1++; errore perchè è costante
    int g=0;
    incr(g); //viene creato un reference a g e il valore di g risulta incrementato
    cout<<"g="<<g<<endl; //stampa 1
    //questa funzione restituisce un reference
    int& yr=choose_var(2);
    //yr è ora un nome alternativo per var2
    yr++;
    //var2 risulta incrementata
    cout<<var2<<endl;
    int k2=choose_var(2);
    //stampa ancora 3
    cout<<k2<<endl;
    //passaggio di un reference a char*
    char* buff=0;
    //usando il reference
    allocate_mem_ref(buff,16000);
    delete[] buff;
    buff=0;
    //usando il puntatore
    allocate_mem_pptr(&buff,16000);
    delete[] buff;
    buff=0;


    return 0;
}

//nota:questo dovrebbe generare un errore perchè viene dimensionato
//un array con un valore non costante gcc invece lo compila (?)
void dim_array(int asize)
{
    int k[asize];

    for (int j=0;j<asize;j++) k[j]=0;

    //oppure
    vector<int> kv(asize);
}


