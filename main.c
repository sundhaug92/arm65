#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

#include "vmInterface.h"

typedef unsigned int (*intReturnsUint)(int);

int main(){
    unsigned int codeBytes = 0xFFFF<<4;
    void* virtualCodeAddress = mmap(NULL, codeBytes, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANONYMOUS | MAP_PRIVATE, 0, 0);

    unsigned int* tempCode = (unsigned int*) virtualCodeAddress;

    tempCode[0]=0xe2800028;
    tempCode[1]=0xe1a0f00e;

    intReturnsUint func=(intReturnsUint)virtualCodeAddress;
    unsigned int i=func(2);
    printf("%d", i);
}
