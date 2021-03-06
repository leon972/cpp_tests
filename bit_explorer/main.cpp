/****************************************************************
Programma per la visualizzazione in formato binario
della memoria
Code by L.Berti 2007
*****************************************************************/

using namespace std;

#include <iostream>
#include <ctype.h>
#include <string.h>
#include <math.h>

#include <iostream>

/**Restituisce la sequenza di bit della memoria value
bsize=dimensione del buffer da esplorare (in bytes)
*/

char* get_bits(void* value,int bsize)
{
    if (value==(void*)0) return (char*)0;

    unsigned char* buff=(unsigned char*)value;
    static char res[1024];
    unsigned char by;
    int pos=0;
    int mask;

    memset(res,0,1024);

    for (int i=bsize-1;(i>=0 && i<1024);--i)
    {
        by=buff[i];

        mask=0x80;

        for (int j=0;j<8;++j)
        {
            if (by & mask) res[pos++]='1';
            else res[pos++]='0';
            mask>>=1;
        }
    }

    return res;
}

int main()
{
    float a=1.0f;
    cout<<"bits:"<<get_bits(&a,sizeof(a))<<endl;
    unsigned char byte=0x80;
    cout<<"bits:"<<get_bits(&byte,sizeof(byte))<<endl;

	return 0;
}
