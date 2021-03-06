/**********************************************************************************
 Code by Leonardo Berti (c) 2011
 Puntatori,array e references
 ***********************************************************************************/

#include <cstring>
#include <iostream>

using namespace std;

static unsigned char* mem = 0;
const size_t MEM_SIZE = 1000;

#define MEM_POS4 (*(mem+4))

/**
 * Alloca la memoria usando un doppio puntatore
 * @param mem puntatore all'area di memoria allocata nello heap
 * @param req_size numero di elementi richiesti
 */
void allocMem(unsigned char **mem, size_t req_size) {

    *mem = new unsigned char[req_size];
     memset(*mem,0,sizeof(unsigned char)*req_size);

}

void safeRelease(unsigned char** mem) {

    if (*mem) {
        delete[] * mem;
        *mem = 0;
    }
}

/**Alloca la meoria usando un referenze*/
void allocMem(unsigned char *&mem, size_t req_size) {

    mem = new unsigned char[req_size];
    memset(mem,0,sizeof(unsigned char)*req_size);
}

void saveRelease(unsigned char *&mem) {

    if (mem) {

        delete[] mem;
        mem = 0;
    }


}

void displayMem(unsigned char* mem, size_t sz) {

    cout << "memory dump:" << endl;

    for (int i = 0; i < sz; i++) {

        cout << i << "]=" << mem[i] << endl;
    }
}

void testMemPointers() {

    allocMem(&mem,MEM_SIZE); //usa il puntatore doppio
    //allocMem(mem,MEM_SIZE); //usa il reference

    //imposta dei riferimenti usati per scrivere in locazioni della memoria
    unsigned char* MEM_PTR1 = mem;
    unsigned char* MEM_PTR2 = mem + 1;
    unsigned char* MEM_PTR3 = mem + 2;

    //scrive dei dati in alcune locazioni della memoria
    *MEM_PTR1=0x1;
    *MEM_PTR2=0x2;
    *MEM_PTR3=0x3;

    *(mem+3)=0x41; //carattere A alla posizione con offset 3

    MEM_POS4=0x42; //carattere B alla posizione con offset 4

    unsigned char* ptr=&mem[5];

    *ptr=0x43;//carattere C alla posizione con offset 5

    ptr++; //incrementa il puntatore

    *ptr=0x44; //carattere D alla posizione con offset 6

    displayMem(mem,10);    

    safeRelease(&mem);

}

/*
 * 
 */
int main(int argc, char** argv) {

    testMemPointers();

    return 0;
}

