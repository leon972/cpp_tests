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
        *it+=10; //è possibile assegnare un nuovo valore perchè l'iteratore non è costante
        cout<<*it<<endl;
    }

    //it1 si comporta come un
    //*int const
    //il puntatore è costante ma punta a dati modificabili
    const vector<int>::iterator it1=v.begin();

    *it1=25; //OK;

    cout<<*it1<<endl;

    //it1++; //errore! il puntatore è costante e non puo' puntare ad altri elementi

    //it è un puntatore non costante (puo' spostarsi su altri elementi)
    //ma punta a dati non modificabili

    vector<int>::const_iterator it2=v.begin();

    // *it2=9; //errore! i dati a cui punta non sono modificabili

    cout<<*it2<<endl;

    it2++; //OK perchè il puntatore non è costante

    cout<<*it2<<endl;


    return 0;
}
