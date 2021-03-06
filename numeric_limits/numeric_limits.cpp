/**********************************************************************************
 Code by Leonardo Berti (c) 2007
 acquisizione delle informazioni sui tipi base usando numeric_limits
***********************************************************************************/

#include<iostream>
#include<limits>

using namespace std;

const char sep[]="\t\t";

/**Visualizza le informazioni principali per un tipo di dato*/
template <class T>void out_info(const char* descr)
{
    cout.fill(' ');
    cout.width(14);
    cout<<descr;
    cout.width(5);
    cout<<numeric_limits<T>::digits;
    cout.width(22);
    cout<<numeric_limits<T>::min();
    cout.width(22);
    cout<<numeric_limits<T>::max();
    cout.width(8);
    cout<<numeric_limits<T>::is_signed;
    cout.width(8);
    cout<<numeric_limits<T>::is_integer;

    cout<<endl;
}

/**Output delle informazioni estese per i tipi float e double*/
template <class T>void out_float_info(const char* descr)
{
    cout<<descr<<":"<<endl;
    cout<<"base of exponent:"<<numeric_limits<T>::radix<<endl;
    cout<<"number of radix digits in mantissa:"<<numeric_limits<T>::digits<<endl;
    cout<<"number of base 10 digits in mantissa:"<<numeric_limits<T>::digits10<<endl;
    cout<<"is signed:"<<numeric_limits<T>::is_signed<<endl;
    cout<<"is_exact:"<<numeric_limits<T>::is_exact<<endl;
    cout<<"min value:"<<numeric_limits<T>::min()<<endl;
    cout<<"max value:"<<numeric_limits<T>::max()<<endl;
    //epsilon è definito "machine accuracy" ed è il più piccolo numero floating point che aggiunto
    //ad 1.0 rende un valore superiore a 1.0
    cout<<"epsilon:"<<numeric_limits<T>::epsilon()<<endl;
    cout<<"round_error:"<<numeric_limits<T>::round_error()<<endl;
    cout<<"infinity:"<<numeric_limits<T>::infinity()<<endl;
    cout<<"quiet_NaN:"<<numeric_limits<T>::quiet_NaN()<<endl;
    cout<<"signaling_NaN:"<<numeric_limits<T>::signaling_NaN()<<endl;
    cout<<"min exponent:"<<numeric_limits<T>::min_exponent<<endl;
    cout<<"max exponent:"<<numeric_limits<T>::max_exponent<<endl;
    cout<<"min exponent (base 10):"<<numeric_limits<T>::min_exponent10<<endl;
    cout<<"max exponent (base 10):"<<numeric_limits<T>::max_exponent10<<endl;
    cout<<"has infinity:"<<numeric_limits<T>::has_infinity<<endl;
    cout<<"has quiet NaN:"<<numeric_limits<T>::has_quiet_NaN<<endl;
    cout<<"has signaling NaN:"<<numeric_limits<T>::has_signaling_NaN<<endl;
}

void table_head()
{
    cout.width(14);
    cout<<"DATA TYPE";
    cout.width(5);
    cout<<"BITS";
    cout.width(22);
    cout<<"MIN";
    cout.width(22);
    cout<<"MAX";
    cout.width(8);
    cout<<"SIGNED";
    cout.width(8);
    cout<<"IS_INT";

    cout<<endl;
}

int main(void)
{
    cout<<"Informazioni sui tipi base specifici di questa implementazione:"<<endl;

    //imposta la formattazione a sinistra per l'output
    cout.setf(ios_base::left,ios_base::adjustfield);
    //intestazione tabella

    table_head();
    out_info<char>("char");
    out_info<char>("bool");
    out_info<unsigned char>("unsigned char");
    out_info<short>("short");
    out_info<unsigned short>("unsigned short");
    out_info<int>("int");
    out_info<unsigned int>("unsinged int");
    out_info<long>("long");
    out_info<unsigned long>("unsigned long");
    out_info<long long>("long long");
    out_info<unsigned long long>("u long long");
    out_info<float>("float");
    out_info<double>("double");
    out_info<long double>("long double");

    cout<<"-----------------------------------------------"<<endl;
    out_float_info<float>("float");
    cout<<"-----------------------------------------------"<<endl;
    out_float_info<long double>("double");

    return 0;
}

