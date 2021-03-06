/****************************************************************
Programma per la conversione di base numerica
Code by L.Berti 2007
*****************************************************************/

using namespace std;

#include <iostream>
#include <ctype.h>
#include <string.h>
#include <math.h>

//base corrente di input
int current_inbase=10;
//base corrente di output
int current_outbase=16;

const int MIN_BASE=2;
const int MAX_BASE=30;

const string sep="*****************************************************";

void ConvertMenu();

bool check_value(const char* value,int base);
char* base_conv(const char* value,int in_base,int out_base);
int to_base10(const char* value,int base);
char* to_basex(const unsigned int value,int base);
void ConvertSeqMenu();

void SelectBaseMenu()
{
    cin.clear();
    cin.sync();
    int r=-1;

    while (r!=0)
    {
        cout<<"Base input corrente:"<<current_inbase<<endl;
        cout<<"Selezionare la nuova base di input (un numero da "<<MIN_BASE<<" a "<<MAX_BASE<<" ,0 per uscire):"<<endl;

        if (!(cin>>r))
        {
            cout<<"Inserire un numero!"<<endl;
            r=-1;
        }
        else if (r>=MIN_BASE && r<=MAX_BASE)
        {
            current_inbase=r;
            r=0;


        }
        else if (r==0)
        {
            //esce
        }
        else
        {
            cout<<"Base non valida.Inserire una base compresa fra "<<MIN_BASE<<" e "<<MAX_BASE<<endl;
        }

        cin.clear();
        cin.sync(); //flush the input stream
    }


    //base output
    r=-1;

    while (r!=0)
    {
        cout<<"Base output corrente:"<<current_outbase<<endl;
        cout<<"Selezionare la nuova base di output (un numero da "<<MIN_BASE<<" a "<<MAX_BASE<<"0 per uscire):"<<endl;

        if (!(cin>>r))
        {
            cout<<"Inserire un numero!"<<endl;
            r=-1;
        }
        else if (r>=MIN_BASE && r<=MAX_BASE)
        {
            current_outbase=r;
            r=0;
        }
        else if (r==0)
        {
            //esce
        }
        else
        {
            cout<<"Base non valida.Inserire una base compresa fra "<<MIN_BASE<<" e "<<MAX_BASE<<endl;
        }

        cin.clear();
        cin.sync(); //flush the input stream
    }
}

void MainMenu()
{
    cin.clear();
    cin.sync();
    int r=-1;

    while (r!=0)
    {
        cout<<sep<<endl;
        cout<<"Programma per la conversione di base"<<endl;
        cout<<sep<<endl;
        cout<<"MENU PRINCIPALE"<<endl;
        cout<<sep<<endl;
        cout<<"1] Imposta la base corrente."<<endl;
        cout<<"2] Converti."<<endl;
        cout<<"3] Converti sequenza."<<endl;
        cout<<"0] Esci."<<endl;
        cout<<"(conversione corrente: da base "<<current_inbase<<" a base "<<current_outbase<<" )"<<endl;
        cout<<endl<<"Scegli:"<<endl;

        if (!(cin>>r))
        {
            cout<<"Inserire un numero!"<<endl;
            cin.clear();
            cin.sync();
        }
        else
        {
            switch (r)
            {
            case 1:
                SelectBaseMenu();
                break;
            case 2:
                ConvertMenu();
                break;
            case 3:
                ConvertSeqMenu();
                break;
            case 0:
                //esce dal menu
                break;
            default:
                cout<<"Scelta non valida!"<<endl;
            }
        }

    }
}

/**Converte un intervallo*/
void ConvertSeqMenu()
{
    cin.clear();
    cin.sync();

    int x1=0,x2=0;

    cout<<"Inserire il valore iniziale della sequenza:"<<endl;

    if (!(cin>>x1))
    {
        cin.clear();
        cin.sync();
        cout<<"E' richiesto un numero intero!"<<endl;
        return;
    }

    cout<<"Inserire il valore finale della sequenza:"<<endl;

    if (!(cin>>x2))
    {
        cin.clear();
        cin.sync();
        cout<<"E' richiesto un numero intero!"<<endl;
        return;
    }

    if (x2<x1)
    {
        cout<<"Il valore finale è minore di quello iniziale!"<<endl;
        return;
    }

    cout<<"Sequenza da "<<x1<<" a "<<x2<<" in base "<<current_outbase<<endl;

    for (int i=x1;i<=x2;++i)
    {
        cout<<i<<"] "<<to_basex(i,current_outbase)<<endl;
    }

}

void ConvertMenu()
{
    cin.clear();
    cin.sync();

    cout<<"Inserire un numero in base "<<current_inbase<<" (invio per tornare al menu principale):"<<endl;

    char value[1024];
    memset(value,0,1024);

    if (!(cin>>value))
    {
        cout<<"Input non valido!"<<endl;
        cin.clear();
        cin.sync();
    }
    else if (!check_value(value,current_inbase))
    {
        cout<<"Il valore inserito ("<<value<<") non è un numero valido in base "<<current_inbase<<endl;
    }
    else
    {
        //visualizza in output il numero convertito
        cout<<base_conv(value,current_inbase,current_outbase)<<"   (in base "<<current_outbase<<")"<<endl;
    }
}

/**Controlla che il numero sia valido nella base specificata*/
bool check_value(const char* value,int base)
{
    if (!value) return false;
    const size_t len=strlen(value);
    if (len==0) return false;
    int ival=0;

    for (unsigned int i=0;i<len;++i)
    {
        //ammessi numeri e caratteri da A a Z o a - z
        if (!isalnum(value[i])) return 0;

        if (isdigit(value[i]))
        {
            //0-9
            ival=(int)value[i]-48;
        }
        else
        {
            if (value[i]>='a' && value[i]<='z') ival=10+(int)value[i]-97;
            else ival=10+(int)value[i]-65;
        }

        if (ival>=base) return false; //numero non valido in questa base
    }

    return true;
}

/**Converta da una base ad un altra*/
char* base_conv(const char* value,int in_base,int out_base)
{
    if (!value) return (char*)0;
    const size_t MAX_SIZE=1024;
    static char cval[MAX_SIZE];
    const size_t len=strlen(value);

    if (!len) return (char*)0;
    if (len>MAX_SIZE) return (char*)0;

    if (!check_value(value,in_base)) return (char*)0;

    memset(cval,0,MAX_SIZE);
    memcpy(cval,value,len);

    //converte in base 10
    return to_basex(to_base10(value,in_base),out_base);

    return cval;
}

/**Potenza intera, restituisce b alla exp)*/
unsigned int ipow(unsigned int b,unsigned int exp)
{
    unsigned int res=1;

    for (unsigned int i=0;i<exp;++i)
    {
        res*=b;
    }

    return res;
}

/**Converte da numero in base "base" in intero in base 10*/
int to_base10(const char* value,int base)
{
    if (!value) return 0;
    if (base<=1) return 0;

    int c=0,r=0;
    int p=0;

    const size_t len=strlen(value);

    for (unsigned int i=0;i<len;++i)
    {
        p=(int)(ipow(base,len-i-1));

        c=(int)value[i];

        if (c>=48 && c<=57) //0-9
        {
            r+=(c-48)*p;
        }
        else if (c>=97 && c<=122) //a-z
        {
            r+=(c-87)*p;
        }
        else if (c>=65 && c<=90) //A-Z
        {
            r+=(c-55)*p;
        }
        else return 0; //non valido
    }

    return r;
}

/**Converte un valore decimale positivo in una base qualsiasi*/
char* to_basex(const double value,int base,int decimal_places)
{
    if (base<=1) return (char*)0;

    unsigned int uv=static_cast<int>(value);

    const int MAX_SIZE=1024;
    static char cval[MAX_SIZE];
    static char cres[MAX_SIZE];

    memset(cval,0,MAX_SIZE);

    int rem=value%base;
    int i=0;

    if (rem>=0 && rem<=9) cval[i]=(char)(48+rem);
    else cval[i]=(char)(rem+55); //rem-10+65, A=65

    int q=value/base;

    //converte la parte intera
    while (q && i<MAX_SIZE)
    {
        rem=q%base;
        q=q/base;
        ++i;
        if (rem>=0 && rem<=9) cval[i]=(char)(48+rem);
        else cval[i]=(char)(rem+55); //rem-10+65, A=65
    }

    //inverte la sequenza di resti
    int j=0;

    memset(cres,0,MAX_SIZE);

    while (i>=0)
    {
        cres[j++]=cval[i];
        --i;
    }

    if (decimal_places<=0) return cres;

    //parte decimale
    cres[j++]='.';

    i=decimal_places;

    double temp;
    double fv=value;

    while (i-- && j<MAX_SIZE)
    {
        temp=fv-static_cast<int>(fv); //prende la parte decimale corrente

        temp*=base;

        //la cifra espressa nella base è la parte intera
        rem=static_cast<int>(temp);

        if (rem>=0 && rem<=9) cres[j++]=(char)(48+rem);
        else cres[j++]=(char)(rem+55); //rem-10+65, A=65

    }

    return cres;
}

/**Converte un intero positivo da base 10 in una base qualsiasi*/
char* to_basex(const unsigned int value,int base)
{
    if (base<=1) return (char*)0;

    const int MAX_SIZE=1024;
    static char cval[MAX_SIZE];
    static char cres[MAX_SIZE];

    memset(cval,0,MAX_SIZE);

    int rem=value%base;
    int i=0;

    if (rem>=0 && rem<=9) cval[i]=(char)(48+rem);
    else cval[i]=(char)(rem+55); //rem-10+65, A=65

    int q=value/base;

    while (q && i<MAX_SIZE)
    {
        rem=q%base;
        q=q/base;
        ++i;
        if (rem>=0 && rem<=9) cval[i]=(char)(48+rem);
        else cval[i]=(char)(rem+55); //rem-10+65, A=65
    }

    //inverte la sequenza di resti
    int j=0;

    memset(cres,0,MAX_SIZE);

    while (i>=0)
    {
        cres[j++]=cval[i];
        --i;
    }

    return cres;
}

int main()
{
    MainMenu();
    return 0;
}
