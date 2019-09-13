#include "constants.h"

#ifndef VIRTUAL_MACHINE_H
#define VIRTUAL_MACHINE_H

typedef enum VMState{
	ERROR, NEW, READY, FINISH
};

typedef struct VirtualMachine{
	struct {
		unsigned int data;
		unsigned int code;
		unsigned int stack;
		unsigned int extra;
	} Size;
	
	unsigned char *program;
		
	unsigned int eip;
	unsigned int eflags;
	
	unsigned int registers[8] = {0};
	unsigned int segreg[4] = {0};
    double st[8] = {0};
	
	Operator op1;
	Operator op2;
	
} VirtualMachine;

VirtualMachine *vm_new();

bool vm_set_data(VirtualMachine **vm, const char *data, int length);
bool vm_set_code(VirtualMachine **vm, const char *code, int length);
bool vm_set_stack(VirtualMachine **vm, const char *stack, int length);
bool vm_set_extra(VirtualMachine **vm, const char *extra, int length);

bool vm_run(VirtualMachine **vm);

bool vm_restore(VirtualMachine **vm);
bool vm_reset(VirtualMachine **vm);
void vm_delete(VirtualMachine **vm);

#endif //VIRTUAL_MACHINE_H