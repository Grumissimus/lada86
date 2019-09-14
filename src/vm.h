#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"

#ifndef VIRTUAL_MACHINE_H
#define VIRTUAL_MACHINE_H

typedef enum VMState{
	VM_ERROR, VM_NEW, VM_READY, VM_FINISH
} VMState;

typedef struct VirtualMachine{
	VMState state;
	
	unsigned char *program;
	unsigned int programSize;
	
	unsigned int eip;
	unsigned int eflags;
	
	unsigned int registers[8];
	unsigned int segreg[6];
	SegmentSize size;
	double st[8];
	
	Operator op1;
	Operator op2;
	
	
} VirtualMachine;

VirtualMachine *vm_new();

boolean vm_init_seg(VirtualMachine **vm, SegmentSize ss);

boolean vm_load_code(VirtualMachine **vm, const char *code, unsigned int length);
boolean vm_load_data(VirtualMachine **vm, const char *data, unsigned int length);

boolean vm_is_ready(VirtualMachine **vm);

void vm_print_full(VirtualMachine **vm);
void vm_print_reg(VirtualMachine **vm);
void vm_print_segreg(VirtualMachine **vm);
void vm_print_fpreg(VirtualMachine **vm);

boolean vm_run(VirtualMachine **vm);

void vm_delete(VirtualMachine **vm);

#endif //VIRTUAL_MACHINE_H
