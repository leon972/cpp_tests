/*********************************
Functors
passaggio di funzioni come argomenti
Code by Leonardo Berti (c) 2010
**********************************/

#include <cmath>
#include <iostream>

using namespace std;

/**
funzione x*x
*/
class Square
{
    public:
    //invoca la funzione
    double operator()(const double x)
    {
        return x*x;
    }
};

/**
Ae^-x/t
*/
class Exp
{
    private:
    double A,t;

    public:
    Exp(double A,double t)
    {
        this->A=A;
        this->t=t;
    }
    double operator()(const double x)
    {
        return A*pow(M_E,x/t);
    }
};

/**
interfaccia funzioni di una variabile
*/
class IFunctionX
{
    public:
    virtual double operator()(double x)=0;
};

/**
Funzioni di due variabili
*/
class IFunctionXY
{
    public:
    virtual double operator()(double x,double y)=0;
};

/**
implementazioni interfaccia funzioni di una variabile
*/
class Log:public IFunctionX
{
    private:

    double base;

    public:

    Log(double base)
    {
        this->base=base;
    }

    double operator()(double x)
    {
        return log(x)/log(base);
    }
};

/**
Implementa una funzione di due variabili
*/
class MyXY:public IFunctionXY
{
    private:

    double P;

    public:
    MyXY(double p)
    {
        P=p;
    }

    double operator()(double x,double y)
    {
        return x*y/P-x+y;
    }
};

void TestFunction(IFunctionX& f)
{
    cout<<"Test function..."<<endl;

    for (double x=0;x<100;x+=1)
    {
        cout<<"f("<<x<<")="<<f(x)<<endl;
    }
}

void TestFunctionXY(IFunctionXY& f)
{
    cout<<"Test function..."<<endl;

    for (double x=0;x<100;x+=1)
    {
        cout<<"f("<<x<<","<<100-x<<")="<<f(x,100-x)<<endl;
    }
}

int main(void)
{
    Square f;

    for (int i=0;i<10;i++)
    {
        cout<<f(i)<<endl;
    }

    Exp f1(3,2);

    for (double v=0.0;v<20;v+=1.0)
    {
        cout<<f1(v)<<endl;
    }

    Log log2(2);

    TestFunction(log2);

    MyXY fxy(8);

    TestFunctionXY(fxy);

    return 0;
}
