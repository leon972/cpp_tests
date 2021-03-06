/**********************************************************************************
 Code by Leonardo Berti (c) 2006
 Esempio di classe stack implementata con una classe che utilizza i tipi generici
 stack4.h
 -concrete types-
***********************************************************************************/

#ifndef _STACK4_INCLUDE_
#define _STACK4_INCLUDE_

namespace ClassStack {
    template <class T> class Stack {
private:

        T* v;
        int top;
        int maxsize;

public:

        //classi usate per la gestione delle eccezioni
        class Overflow {};
        class Underflow {};
        class BadSize {};

        //costruttore
        Stack(int size) {
            //genera una eccezione se la dimensione non è corretta
            if (size<=0) throw BadSize();

            maxsize=size;
            top=0;

            v=new T[maxsize];
        }

        //distruttore: dealloca la memoria
        ~Stack() {
            delete[] v;
        }

        T pop() {
            if (top==0) throw Underflow(); //stack vuoto:impossibile compiere l'operazione

            return v[--top];
        }

        void push(T c) {
            //lo stack è pieno
            if (top==maxsize) throw Overflow();
            v[top++]=c;
        }
    };
}

#endif

