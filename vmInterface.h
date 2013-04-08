typedef struct {
    unsigned int regD0;
    char* dataMemory;
    void* codeMemory;
    char regSP;
    unsigned int rollCounter;
} vm_t;

typedef void (*vm_entry)(vm_t*,unsigned int,char*,unsigned int);
void enterVM(vm_t* vm, int offset) {
    vm_entry entryPoint=(vm_entry)(vm->codeMemory+offset);
    entryPoint(vm, vm->regD0, vm->dataMemory, vm->rollCounter);
}
