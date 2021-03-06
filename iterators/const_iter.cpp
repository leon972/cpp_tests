/********************************************
Iteratori costanti e non costanti
19-4-2009
*********************************************/

#include <vector>
#include <iostream>

using namespace std;


int main()
{

    vector<int> v;

    for (int i=0;i<10;++i) v.push_back(i);

    //iteratore non costante (si comporta come un puntatore a int
    for (vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        *it+=10; //� possibile assegnare un nuovo valore perch� l'iteratore non � costante
        cout<<*it<<endl;
    }

    //it1 si comporta come un
    //*int const
    //il puntatore � costante ma punta a dati modificabili
    const vector<int>::iterator it1=v.begin();

    *it1=25; //OK;

    cout<<*it1<<endl;

    //it1++; //errore! il puntatore � costante e non puo' puntare ad altri elementi

    //it � un puntatore non costante (puo' spostarsi su altri elementi)
    //ma punta a dati non modificabili

    vector<int>::const_iterator it2=v.begin();

    // *it2=9; //errore! i dati a cui punta non sono modificabili

    cout<<*it2<<endl;

    it2++; //OK perch� il puntatore non � costante

    cout<<*it2<<endl;


    return 0;
}
