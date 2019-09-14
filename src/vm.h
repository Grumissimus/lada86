#include "constants.h"

#ifndef VIRTUAL_MACHINE_H
#define VIRTUAL_MACHINE_H

typedef enum VMState{
	ERROR, NEW, READY, FINISH
} VMState;

typedef struct VirtualMachine{
	VMState state;
	
	struct {
		unsigned int data;
		unsigned int code;
		unsigned int stack;
		unsigned int extra;
	} Size;
	
	unsigned char *program;
		
	unsigned int eip;
	unsigned int eflags;
	
	unsigned int registers[8];
	unsigned int segreg[4];
	double st[8];
	
	Operator op1;
	Operator op2;
	
} VirtualMachine;

VirtualMachine *vm_new();

boolean vm_set_data(VirtualMachine **vm, const char *data, unsigned int length);
boolean vm_set_code(VirtualMachine **vm, const char *code, unsigned int length);
boolean vm_set_stack(VirtualMachine **vm, const char *stack, unsigned int length);
boolean vm_set_extra(VirtualMachine **vm, const char *extra, unsigned int length);

boolean vm_run(VirtualMachine **vm);

boolean vm_restore(VirtualMachine **vm);
boolean vm_reset(VirtualMachine **vm);
void vm_delete(VirtualMachine **vm);

#endif //VIRTUAL_MACHINE_H
