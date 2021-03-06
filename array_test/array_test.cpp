/**
 Utilizzo degli array
 Code by Leonardo Berti
*/

#include<iostream>


using namespace std;


static wchar_t string1[18];
static const char* txt="My text"; //puntatore costante a una stringa di testo
static const char txt1[]={'H','e','l','l','o'}; //array di char
static const char txt2[]="My text 2"; //array di char
static const char* vtxt[]={"text1","text2","text3","text4"};//un array di puntatori a char
static const int vi[]={1,2,3,4,5};
static const char mtext[][5]={"tx11","tx12","tx13","tx14",
                               "tx21","tx22","tx23","tx24"
                             };
//matrice 2 righe tre colonne di puntatori a testo
static char* mtext2[2][3];

void displ(const char* txt[],int size)
{
    cout<<sizeof(txt)<<endl; //4 perchè viene passato un puntatore
    for (int i=0;i<size;++i) cout<<txt[i]<<endl;
}

//questa è equivalente a displ
void displ1(const char** txt,int size)
{
    cout<<sizeof(txt)<<endl; //4 perchè viene passato un puntatore
    for (int i=0;i<size;++i) cout<<txt[i]<<endl;
}

//restituisce un array di stringhe
const char** const get_str_array(int& size)
{
    size=4;
    return vtxt;
}


int main()
{
    cout<<"Array test..."<<endl;

    memset(string1,0,sizeof(string1)); //dimensione in byte del vettore string1 (36 in questo caso)

    cout<<"sizeof(string1)="<<sizeof(string1)<<endl;

    cout<<txt<<endl;

    size_t len=sizeof(txt);

    cout<<"size="<<len<<endl; //dimensione del puntatore txt (4 bytes)

    cout<<txt1<<endl;

    cout<<sizeof(txt1)<<endl; //5 (5 caratteri) (nb qui lo zero finale non viene considerato)

    cout<<txt2<<endl;

    cout<<sizeof(txt2)<<endl; //10 (10 caratteri compreso lo zero terminatore)

    cout<<sizeof(vtxt)<<endl; //16 (è un array di 4 puntatori a char)

    displ(vtxt,4);

    displ1(vtxt,4);

    cout<<sizeof(vi)<<endl; //20 5 elementi int

    cout<<sizeof(mtext)<<endl; //40 8 stringhe di 5 caratteri

    cout<<"Matrice di stringhe:"<<endl;

    for (int row=0;row<2;row++)
    {
        for(int col=0;col<3;col++)
        {
            mtext2[row][col]=new char[3];
            sprintf(mtext2[row][col],"A%d%d",row,col);
        }
    }

    for (int row=0;row<2;row++)
    {
        cout<<endl;
        for(int col=0;col<3;col++)
        {
            cout<<mtext2[row][col]<<",";
            delete[] mtext2[row][col];
        }
    }

    cout<<endl;

    int sz;

    const char** const r=get_str_array(sz);

    for (int i=0;i<sz;i++) cout<<r[i]<<endl;

    return 0;
}

