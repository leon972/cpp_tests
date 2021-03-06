/*********************************
Bit Hacks
Code by Leonardo Berti (c) 2010

(ref. Bit Twiddling Hacks
By Sean Eron Anderson)

**********************************/

#include<iostream>
using namespace std;

/**
Testa se num è dispari
*/
bool is_odd(int n) {
    return n & 1;
}

/**
Costruisce una maschera di n bits
NB: al massimo si può ottenere una maschera di sizeof(int)*8-1 bit
*/
unsigned get_mask(int nbits)
{
    return (1<<nbits)-1;
}

/**
Setta un bit
@param bit_index indice del bit da settare
*/
void set_bit(unsigned &value,int bit_index)
{
    value |= (1<<bit_index);
}

/**
Resetta un bit
@param bit_index indice del bit da resettare (max 31)
*/
void reset_bit(unsigned &value,int bit_index)
{
    value &= ~(1<<bit_index);
}

/**
Acquisisce un bit
@param bit_index indice del bit da acquisire (max 31)
0=bit meno significativo
*/
int get_bit(unsigned value,int bit_index)
{
    return value & (1<<bit_index);
}

/**
Testa se un numero è una potenza di due o zero
*/
bool is_power_of_two(unsigned value)
{
    return (value & (value-1)) == 0;
}

/**
Conta il numero di bit settati nel valore v
*/
int count_set_bits(int v)
{
    int c;
    for (c=0;v;c++) v&=v-1;
    return c;
}

/**
Arrotonda l'intero senza segno al più vicino interno senza segno potenza di due
tale che il numero trovato è >=del numero passato alla funzione
*/
unsigned round_pow_two(unsigned v)
{
    --v;
    v |= v>>1;
    v |= v>>2;
    v |= v>>4;
    v |= v>>8;
    v |= v>>16;
    ++v;
    return v;
}

/**Restituisce la sequenza di bit della memoria value
bsize=dimensione del buffer da esplorare (in bytes)
*/

char* display_bits(void* value,int bsize)
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

int main() {


    cout<<"odd or even..."<<endl<<endl;

    //pari o dispari
    for (unsigned i=0;i<sizeof(unsigned)*8;i++) {

        cout<<i<<(is_odd(i) ? " is odd" : " is even")<<endl;

    }

    cout<<endl<<"bit masks..."<<endl<<endl;

    //maschera di n bits
    for (unsigned nbits=0;nbits<sizeof(unsigned)*8;nbits++)
    {
        int mask=get_mask(nbits);
        cout<<"mask with "<<nbits<<" bits:"<<display_bits(&mask,sizeof(int))<<endl;

    }

    cout<<endl<<"set bit..."<<endl<<endl;

    //setta i bit
    for (unsigned i=0;i<sizeof(unsigned)*8;i++)
    {
        unsigned value=0;
        set_bit(value,i);
        cout<<"set bit "<<i<<" : "<<value<<endl;
    }

    cout<<endl<<"reset bit..."<<endl<<endl;

    size_t sz=sizeof(unsigned)*8-1;

    //resetta i bit
    for (size_t i=0;i<sz;i++)
    {
        unsigned mask=get_mask(sz);
        reset_bit(mask,i);
        cout<<"reset bit "<<i<<" : "<<display_bits(&mask,sizeof(int))<<endl;
    }

    cout<<endl<<"power of two test..."<<endl<<endl;

    for (int i=0;i<65;i++)
    {
        cout<<i<<(is_power_of_two(i) ? " is power of two":"is NOT power of two")<<endl;
    }

    cout<<endl<<"set bits count..."<<endl<<endl;

    for (int i=0;i<16;i++)
    {
        cout<<i<<" ("<<display_bits(&i,sizeof(i))<<") "<<count_set_bits(i)<<" bits set"<<endl;

    }

    cout<<endl<<endl<<"round power of two..."<<endl<<endl;

    for (int i=0;i<200;i++)
    {
        cout<<i<<" next power of two : "<<round_pow_two(i)<<endl;
    }

    return 0;
}
