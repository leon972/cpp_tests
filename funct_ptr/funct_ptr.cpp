/*********************************
Puntatori a funzione
Code by Leonardo Berti (c) 2010
**********************************/

#include <iostream>
using namespace std;

/**
calcola il quadrato
*/
int fn_square(int x)
{
    return x*x;
}

int fn_cube(int x)
{
    return x*x*x;
}

void display(const char* text)
{
    cout<<"display:"<<text<<endl;
}

/**
Passaggio di un puntatore a funzione ad una funzione
value=valore da usare con la funzione passata
*/
void use_function(int (*ptr)(int),int value)
{
    cout<<"il valore restituito è:"<<ptr(value)<<endl;
}

/**
dichiarazione di un array di puntatori a funzione
*/
int (*fun_ptr_array[2])(int);

/**
definizione di un tipo di puntatore a funzione
INT_FUNCTION è un tipo di dati per le funzioni che accettano
un int e restituiscono un int
*/

typedef int (*INT_FUNCTION)(int);

/**
funzione che accetta un intero e restituisce un puntatore a una funzione
che accetta un intero e restituisce un intero
*/

int (*(choose_function(int id)))(int)
{
    switch (id)
    {
        case 0:
        return fn_square;
        case 1:
        return fn_cube;
        default:
        return 0; //id non valido
    }
}

/**
puntatore a funzioni che accettano due int e restituiscono un
puntatore ad un array di 5 elementi int
*/
int (*(*fn_arr)(int,int))[5];

typedef int vector5[5];

//vettore di 5 elementi
vector5 vec5={1,2,3,4,5};

//funzione che restituisce un vettore di 5 elementi
vector5* test_function(int a,int b)
{
    return &vec5;
}

int main()
{

    //fun_ptr è un puntatore a una funzione che ha come argomento un intero e restituisce un intero
    int (*fun_ptr)(int)=fn_square;

    cout<<fun_ptr(2)<<endl; //stampa 4

    //assegna il puntaotore alla seconda funzione
    fun_ptr=fn_cube;

    cout<<fun_ptr(2)<<endl; //stampa 8

    //puntatore a una funzione che accetta un array di caratteri costanti e rende void
    //assegna al puntaote la funzione display
    void (*fun_ptr2)(const char*)=display;

    fun_ptr2("Hello World!");

    use_function(fun_ptr,5);

    //passa direttamente la funzione per nome
    use_function(fn_square,6);

    //usa il vettore di puntatori a funzione
    fun_ptr_array[0]=fn_square;
    fun_ptr_array[1]=fn_cube;

    cout<<"*** usa l'array di puntatori a funzione*"<<endl;
    for (int i=0;i<2;i++) use_function(fun_ptr_array[i],6);

    cout<<"*** usa il tipo di dati INT_FUNCTION *"<<endl;

    INT_FUNCTION fn1=fn_square;

    use_function(fn1,18);

    fn1=choose_function(0);//rende fn_square

    use_function(fn1,3);

    fn1=choose_function(1);//rende fn_cube

    use_function(fn1,3);

    fn_arr=test_function;

    vector5* res=fn_arr(1,1);

    for (int i=0;i<5;i++)
    {
        cout<<(*res)[i]<<endl;
    }

    return 0;

}
